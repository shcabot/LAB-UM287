#include "mpi.h"
#include<stdio.h>
#include<math.h>

int main( int argc, char *argv[] )
{
 int nproc, myrank, istart, iend;
 int i,N=1e9;
 double A=0.0, B=1.0,x,dx,sum,global_sum;
 double tstart,tstop;

/* Initialize MPI */
 MPI_Init(&argc,&argv);
 /* Get the number of processes */
 MPI_Comm_size(MPI_COMM_WORLD,&nproc);
 /* Get my process number (rank) */
 MPI_Comm_rank(MPI_COMM_WORLD,&myrank);
 printf("Hello World from processor %d of %d\n",myrank,nproc);

 tstart = MPI_Wtime();
 dx = (B-A)/(N-1);
 sum = 0.0;
 istart = (N/nproc)*myrank;
 iend   = (N/nproc)*(myrank+1);
 for (i=istart; i<iend; i++) {
   x = A + i*dx;
   sum += 4.0/(1.0+x*x);
 }
 sum *= dx;
 MPI_Reduce(&sum, &global_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD); 
 tstop = MPI_Wtime();
 if (myrank==0){ printf("sum = %f, global_sum = %f, relerr = %e, elapsed time = %f\n",sum,global_sum,fabs(global_sum-M_PI)/M_PI,tstop-tstart);
 }
/* Finalize */
 MPI_Finalize();
 return 0;
} 
