#!/usr/bin/env python
import numpy as np
import time
from mpi4py import MPI

Ntot = 1e7

comm = MPI.COMM_WORLD
myrank = comm.Get_rank()
nproc  = comm.Get_size()

N = int(Ntot)/nproc

tstart = time.clock()
pi = 0.0
for i in range(N):
	x = np.random.rand()
	y = np.random.rand()
	r = np.sqrt(x**2 + y**2)
	if r < 1:
		pi += 1

pi = comm.reduce(pi, op=MPI.SUM, root=0)
Ntot = comm.reduce(N, op=MPI.SUM, root=0)
tstop = time.clock()

if myrank == 0:
	pi *= 4.0/Ntot
	relerr = abs(pi - np.pi)/np.pi
	print 'Approximate Pi = %1.3f' % pi
	print 'Relative error = %1.3e' % relerr
	print 'Elapsed time   = %1.3e' % float(tstop - tstart)