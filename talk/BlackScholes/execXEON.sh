#!/bin/bash
export OMP_NUM_THREADS=272
echo "Blacksholes dram"
time ./09_WorkInParallel 99999999
#echo "Blacksholes MCdram"
#time numactl -m 4,5,6,7 ./09_WorkInParallel 99999999

