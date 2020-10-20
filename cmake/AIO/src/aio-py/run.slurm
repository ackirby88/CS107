#!/bin/bash
#
#SBATCH --job-name=test.model   # Job name
#SBATCH --output=log.test.%j    # Log file
#
#SBATCH --ntasks=2              # Number of ranks
#SBATCH --cpus-per-task=1       # Number of omp threads per rank
#SBATCH --nodes=1               # Number of nodes
#SBATCH --ntasks-per-node=2     # How many tasks on each node
#SBATCH --time=10:00

date
mpirun -np 2 python main.py
