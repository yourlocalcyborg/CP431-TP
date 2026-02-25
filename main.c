#include <mpi.h>
#include <stdio.h>

int dispatcher(int size, MPI_Comm comm) {
  printf("DISPATCHER START\n");

  // Init workers
  unsigned long long int results[] = {0xfffff};
  for (int i = 0; i < size; i++) {
    MPI_Send(results, 1, MPI_UNSIGNED_LONG, i, 0, comm);
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
  unsigned long long int results[] = {0x00};
  MPI_Recv(results, 1, MPI_UNSIGNED_LONG_LONG, 0, 0, comm, MPI_STATUS_IGNORE);
  printf("WORKER %d RECEIVE: %#x \n", rank, results[0]);
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
