#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>


int main(int argc, char **argv){

	MPI_Init (&argc, &argv);

	int rank, size;

	// Get MPI rank and size
	MPI_Comm_rank (MPI_COMM_WORLD, &rank);
	MPI_Comm_size (MPI_COMM_WORLD, &size);

	if(rank==0){
		MPI_Send(buffer, size, MPI_INT,1, 123, MPI_COMM_WORLD);
	}
	else{
		MPI_Recv(buffer, size, MPI_INT, 0, 123, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	}

	MPI_Finalize();

}
