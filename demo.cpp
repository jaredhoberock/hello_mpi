// adapted from https://github.com/wesleykendall/mpitutorial/tree/gh-pages/tutorials/mpi-hello-world/code

// Author: Wes Kendall
// Copyright 2011 www.mpitutorial.com
// This code is provided freely with the tutorials on mpitutorial.com. Feel
// free to modify it for your own use. Any distribution of the code must
// either provide a link to www.mpitutorial.com or keep this header intact.
//
// An intro MPI hello world program that uses MPI_Init, MPI_Comm_size,
// MPI_Comm_rank, MPI_Finalize, and MPI_Get_processor_name.

#include <mpi.h>
#include <iostream>

int main()
{
  // intialize environment
  MPI_Init(nullptr, nullptr);

  // get the number of processes
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  // get the rank of this process
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

  // get the name of this processor
  char processor_name[MPI_MAX_PROCESSOR_NAME];
  int name_len;
  MPI_Get_processor_name(processor_name, &name_len);

  std::cout << "Hello world from processor " << processor_name << ", rank " << world_rank << " out of " << world_size << " processors" << std::endl;
}

