#include <iostream>
#include <vector>
#include <numeric>
#include <random>

#include <adios2.h>
#if ADIOS2_USE_MPI
#include <mpi.h>
#endif

int main(int argc, char *argv[])
{
    int rank, size;
#if ADIOS2_USE_MPI
    int provided;

    // MPI_THREAD_MULTIPLE is only required if you enable the SST MPI_DP
    MPI_Init_thread(&argc, &argv, MPI_THREAD_MULTIPLE, &provided);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
#else
    rank = 0;
    size = 1;
#endif

    const size_t Nx = 100, Ny = 100, Nz = 100;
    const size_t steps = 2;
    /** Application variable */
    std::default_random_engine generator;
    std::uniform_real_distribution<float> distribution(0.0,10.0);

    std::vector<float> simArray1(Nx * Ny * Nz);
    std::vector<float> simArray2(Nx * Ny * Nz);
    std::vector<float> simArray3(Nx * Ny * Nz);
    for (size_t i = 0; i < Nx * Ny * Nz; ++i)
    {
        simArray1[i] = distribution(generator);
        simArray2[i] = distribution(generator);
        simArray3[i] = distribution(generator);
    }

#if ADIOS2_USE_MPI
    adios2::ADIOS adios(MPI_COMM_WORLD);
#else
    adios2::ADIOS adios;
#endif

    adios2::IO bpIO = adios.DeclareIO("BPExpression");
    bpIO.SetEngine("bp4");
    bpIO.DefineAttribute<int>("nsteps", steps);
    bpIO.DefineAttribute<int>("arraySize", Nx * Ny * Nz);
    bpIO.SetParameters("statslevel=1");
    bpIO.SetParameters("statsblocksize=5000");

    auto Ux = bpIO.DefineVariable<float>(
        "sim/Ux", {Nz, Ny, size * Nx}, {0, 0, rank * Nx}, {Nz, Ny, Nx});
    auto Uy = bpIO.DefineVariable<float>(
        "sim/Uy", {Nz, Ny, size * Nx}, {0, 0, rank * Nx}, {Nz, Ny, Nx});
    auto Uz = bpIO.DefineVariable<float>(
        "sim/Uz", {Nz, Ny, size * Nx}, {0, 0, rank * Nx}, {Nz, Ny, Nx});
    auto magU = bpIO.DefineDerivedVariable("derive/magU", "x:sim/Ux \n"
        "y:sim/Uy \n"
        "z:sim/Uz \n"
        //"sqrt(x+y+z) + sqrt(y+z) + sqrt(x+z)");
        "x+y+z");
/*    auto magU = bpIO.DefineDerivedVariable("derive/magU", "x:sim/Ux \n"
        "y:sim/Uy \n"
        "z:sim/Uz \n"
        "sqrt(x^2+y^2+z^2)");
*/

    // add Operation to magU

    std::string filename = "expMagnitude.bp";
    adios2::Engine bpFileWriter = bpIO.Open(filename, adios2::Mode::Write);

    for (int i=0; i<steps; i++)
    {
        std::cout << "Start step " << i << std::endl;
        bpFileWriter.BeginStep();
        bpFileWriter.Put(Ux, simArray1.data());
        bpFileWriter.Put(Uy, simArray2.data());
        bpFileWriter.Put(Uz, simArray3.data());
        bpFileWriter.EndStep();
    }

    /** Create bp file, engine becomes unreachable after this*/
    bpFileWriter.Close();
    if (rank == 0)
    {
        std::cout << "Wrote file " << filename << " to disk. \n";
    }
#if ADIOS2_USE_MPI
    MPI_Finalize();
#endif

    return 0;
}
