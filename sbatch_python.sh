#! /bin/bash

#SBATCH -p TC  # use the TC partition
#SBATCH -J files  # give the job a custom name
#SBATCH -o results-%j.out  # give the job output a custom name
#SBATCH -t 0-00:01  # one minute time limit

#SBATCH -N 4  # number of nodes


srun python files.py

