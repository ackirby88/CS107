#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv){
    int rank, nproc;
    int name_len;
    char processor_name[MPI_MAX_PROCESSOR_NAME];

    /* Initialize MPI environment */
    MPI_Init(&argc, &argv);

    /* Get MPI process rank id */
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    /* Get number of MPI processes in this communicator */
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);

    /* Get name of the processor */
    MPI_Get_processor_name(processor_name, &name_len);

    /* Print hello world message */
    printf("Hello world from processor %s, rank %d out of %d processes\n",processor_name, rank, nproc);

    /* Finalize MPI environment */
    MPI_Finalize();
    return 0;
}
