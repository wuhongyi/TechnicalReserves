// test1.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 六 4月 11 19:42:07 2015 (+0800)
// Last-Updated: 六 4月 11 20:08:54 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 11
// URL: http://wuhongyi.cn 

//mpic++ test1.cc -o 111
//mpirun -np 4 ./111
#include<mpi.h>
int main (int argc, char *argv[]) 
{
  int rank;
  double param;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  if(rank==5)
    param=23.0;
  MPI_Bcast(&param,1,MPI_DOUBLE,5,MPI_COMM_WORLD);
  printf("P:%d after broadcast parameter is %f\n",rank,param);
  MPI_Finalize();
}
// 
// test1.cc ends here
