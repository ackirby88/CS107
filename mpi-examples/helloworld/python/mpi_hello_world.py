"""
Python Parallel Hello World
"""
from __future__ import print_function
from mpi4py import MPI

size = MPI.COMM_WORLD.Get_size()
rank = MPI.COMM_WORLD.Get_rank()
name = MPI.Get_processor_name()

print("Hello World from processor %s, rank %d out of %d" % (name, rank, size))

