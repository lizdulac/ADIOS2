#include <iostream> 
#include <vector>
#include <numeric>

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

    const size_t Nx = 100, steps = 100;
    /** Application variable */
    std::vector<float> simArray1(Nx);
    std::vector<float> simArray2(Nx);
    std::iota(simArray1.begin(), simArray1.end(), -4);
    std::iota(simArray2.begin(), simArray2.end(), 4);

#if ADIOS2_USE_MPI
    adios2::ADIOS adios(MPI_COMM_WORLD);
#else
    adios2::ADIOS adios;
#endif

    adios2::IO bpIO = adios.DeclareIO("BPExpression");
    bpIO.DefineAttribute<int>("nsteps", steps);
    bpIO.DefineAttribute<int>("arraySize", Nx);

    auto bpVar1 = bpIO.DefineVariable<float>(
        "simVar1", {size * Nx}, {rank * Nx}, {Nx});
    auto bpVar2 = bpIO.DefineVariable<float>(
        "simVar2", {size * Nx}, {rank * Nx}, {Nx});
    auto derVar = bpIO.DefineDerivedVariable<float>("derivedVar", "x+y \n"
        "x:simVar1 \n"
        "y:SimVar2");

    std::string filename = "SimpleExpression.bp";
    adios2::Engine bpFileWriter = bpIO.Open(filename, adios2::Mode::Write);

    for (int i=0; i<steps; i++)
    {
        bpFileWriter.BeginStep();
        bpFileWriter.Put(bpVar1, simArray1.data());
        bpFileWriter.Put(bpVar2, simArray2.data());
        bpFileWriter.EndStep();
    }

    /** Create bp file, engine becomes unreachable after this*/
    bpFileWriter.Close();
    if (rank == 0)
    {
        std::cout << "Wrote file " << filename
                  << " to disk. It can now be read by running "
                     "./bin/hello_bpReader.\n";
    }
#if ADIOS2_USE_MPI
    MPI_Finalize();
#endif

    return 0;
}
