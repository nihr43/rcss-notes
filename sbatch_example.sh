#! /bin/bash

#example derived from docs.rnet.mirroui.edu

#SBATCH -p TC  # use the Lewis partition
#SBATCH -J hello_world  # give the job a custom name
#SBATCH -o results-%j.out  # give the job output a custom name
#SBATCH -t 0-00:01  # one minute time limit

#SBATCH -N 5  # number of nodes


# Commands with srun will run on all cores in the allocation

srun hostname
