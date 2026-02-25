#include <mpi.h>
#include <stdio.h>

int dispatcher(int size, MPI_Comm comm) {
  printf("DISPATCHER START\n");

  // Init workers
  for (int i = 0; i < size; i++) {
    unsigned long long int send[] = {i};
    MPI_Send(send, 1, MPI_UNSIGNED_LONG, i, 0, comm);
  }

  // Wait for worker finish, re-dispatch
  while (1) {
    //MPI_Recv();
    break;
  }
  return 0;
}

int worker(int rank, MPI_Comm comm) {
  printf("WORKER %d START\n", rank);

  unsigned long long int column[] = {0x00};
  MPI_Recv(column, 1, MPI_UNSIGNED_LONG_LONG, 0, 0, comm, MPI_STATUS_IGNORE);

  unsigned long long int col = column[0];

  printf("WORKER %d STARTING COLUMN %#x\n", rank, col);

  unsigned long long int results[col];
  for (unsigned long long int i = 0; i < col; i++) {
    results[i] = col*(i+1);
    printf("VALUE: %d * %d = %d\n", col, (i+1), col*(i+1));
  }

  return 0;	
}

int main(int argc, char** argv) {
  // Initialize the MPI environment
  MPI_Init(NULL, NULL);
  
  // Get the number of processes
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);
  
  // Get the rank of the process
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  
  if (world_rank > 0) {
    worker(world_rank, MPI_COMM_WORLD);
  }
  else {
    dispatcher(world_size, MPI_COMM_WORLD);
  }
  
  // Finalize the MPI environment.
  MPI_Finalize();
}
