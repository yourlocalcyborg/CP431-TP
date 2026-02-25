#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void collector(int size, unsigned long int N, MPI_Comm comm) {
  // Create final result array
  // TODO: change to a different data structure to avoid blowing stack on larger Ns
  unsigned long long int *final = malloc(sizeof(unsigned long long int)*(N*N+1));
  for (int i = 0; i <= N*N; i++) {
    final[i] = 0;
  }

  int numworkers = size - 1;

  // Recieve results from worker
  int column = 1;
  while (column <= N) {
    // Calculate which worker has current column
    int worker = (column % (numworkers));
    if (worker == 0) worker = numworkers;
  
    // Receive column from worker
    unsigned long long int receive[column];
    //printf("C: ATTEMPT RECEIVE W%d\n", worker);
    MPI_Recv(receive, column, MPI_UNSIGNED_LONG_LONG, worker, 0, comm, MPI_STATUS_IGNORE);
    printf("C: RECEIVED W%d FOR COLUMN %lld\n", worker, receive[0]);

    // Add results to final array
    for (size_t i = 0; i < (column); i++) {
      //printf("C: ADD %u\n", receive[i]);
      final[receive[i]] = 1;
    }

    column++;
  }
  
  // Count final amount of different numbers
  int count = 0;
  for (size_t i = 0; i <= N*N; i++) {
    count += final[i];
  }
  
  printf("C: FINAL COUNT IS %u\n", count);
}

void worker(int rank, int size, unsigned long int N, MPI_Comm comm) {
  int column = rank;
  while (column <= N) {
    
    unsigned long long int results[column];
    for (unsigned long long int i = 1; i <= column; i++) {
      results[i-1] = column*(i);
    }
    
    MPI_Send(results, column, MPI_UNSIGNED_LONG_LONG, 0, 0, comm);
    column += size-1;
  }

  
}

int main(int argc, char** argv) {
  if (!(argc > 1)) {
    printf("Usage: %s [N]\n", argv[0]);
    return 1;
  }
  unsigned long int N = atoi(argv[1]);

  // Initialize the MPI environment
  MPI_Init(NULL, NULL);
  
  // Get the number of processes
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);
  
  // Get the rank of the process
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  
  if (world_rank > 0) {
    worker(world_rank, world_size, N, MPI_COMM_WORLD);
  }
  else {
    collector(world_size, N, MPI_COMM_WORLD);
  }
  
  // Finalize the MPI environment.
  MPI_Finalize();
}
