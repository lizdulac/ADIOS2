#include <iostream>
#include <numeric>
#include <random>
#include <vector>

#include <adios2.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank, size;
    int provided;

    // MPI_THREAD_MULTIPLE is only required if you enable the SST MPI_DP
    MPI_Init_thread(&argc, &argv, MPI_THREAD_MULTIPLE, &provided);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    const size_t Nx = 10, Ny = 3, Nz = 1;
    const size_t steps = 2;
    /** Application variable */
    std::default_random_engine generator;
    std::uniform_real_distribution<float> distribution(0.0, 10.0);

    std::vector<float> simArray1(Nx * Ny * Nz);
    std::vector<float> simArray2(Nx * Ny * Nz);
    std::vector<float> simArray3(Nx * Ny * Nz);
    std::vector<float> simArray4(Nx * Ny * Nz);
    for (size_t i = 0; i < Nx * Ny * Nz; ++i)
    {
        simArray1[i] = distribution(generator);
        simArray2[i] = distribution(generator);
        simArray3[i] = distribution(generator);
        simArray4[i] = distribution(generator);
    }

    adios2::ADIOS adios(MPI_COMM_WORLD);

    adios2::IO bpIO = adios.DeclareIO("BPExpression");
    bpIO.SetEngine("bp5");
    bpIO.DefineAttribute<int>("nsteps", steps);
    bpIO.DefineAttribute<int>("arraySize", Nx * Ny * Nz);
    bpIO.SetParameters("statslevel=1");
    bpIO.SetParameters("statsblocksize=5000");

    auto Ux =
        bpIO.DefineVariable<float>("uvel", {Nz, Ny, size * Nx}, {0, 0, rank * Nx}, {Nz, Ny, Nx});
    auto Uy =
        bpIO.DefineVariable<float>("vvel", {Nz, Ny, size * Nx}, {0, 0, rank * Nx}, {Nz, Ny, Nx});
    auto Uz =
        bpIO.DefineVariable<float>("wvel", {Nz, Ny, size * Nx}, {0, 0, rank * Nx}, {Nz, Ny, Nx});

    auto magU = bpIO.DefineDerivedVariable("derive/magU",
                                           "x:uvel \n"
                                           "y:vvel \n"
                                           "z:wvel \n"
                                           "magnitude(x,y,z)",
                                           adios2::DerivedVarType::StoreData);
    auto addU = bpIO.DefineDerivedVariable("derive/addU",
                                           "x:uvel \n"
                                           "y:vvel \n"
                                           "z:wvel \n"
                                           "x+y+z",
                                           adios2::DerivedVarType::MetadataOnly);

    // TODO add Operation to magU

    std::string filename = "expMagnitude.bp";
    adios2::Engine bpFileWriter = bpIO.Open(filename, adios2::Mode::Write);

    for (int i = 0; i < steps; i++)
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
    MPI_Finalize();

    return 0;
}
