#include <mpi.h>
#include <stdio.h>

/* This example demonstrates how to pass an integer between two ranks */
int main(int argc, char **argv){
    int rank, nproc;
    int number;

    /* Initialize MPI environment */
    MPI_Init(&argc, &argv);

    /* Get MPI process rank id */
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    /* Get number of MPI processes in this communicator */
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);
   
    /* Assert MPI comm size is 2 */
    if (nproc != 2) {
        if(rank == 0)  printf("Please run with only 2 mpi ranks!\n\t mpirun -np 2 ./sendrecv.mpi\n");

        MPI_Finalize(); // shutdown and return
        return 0;
    }

    /* Initialize each rank's number */
    number = (rank == 0) ? 999:-1;

    /* Display each ranks number before send-recv */
    printf("[BEFORE] Rank[%d] has number: %d\n",rank,number);

    /* Rank 0 send new number to Rank 1 */
    if (rank == 0) {
        MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    } else if (rank == 1) {
	    MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    /* Display each ranks number after send-recv */
    printf(" [AFTER] Rank[%d] has number: %d\n",rank,number);

    /* Finalize MPI environment */
    MPI_Finalize();
    return 0;
}
