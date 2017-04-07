# Intel Xeon and Intel Xeon Phi

## Compile and running for Intel Xeon

```
icc helloWorld.c -o helloWorld
./helloWorld
```

## Compile and running for Intel Xeon Phi

```
icc helloWorld.c -o helloWorld.mic -mmic
micnativeloadex helloWorld.mic
ssh mic0 
./helloWorld.mic
```

## Offloading to Intel Xeon Phi

```
icc helloWorldOffload.c -o helloWorldOffload
export OFFLOAD_REPORT=2
./helloWorldOffload
```

# Intel Xeon Phi (KNL)

```
lscpu
```

```
numactl -H
```

```
cd Blacksholes
numactl -m 0,1,2,3  - dram
numactl -m 4,5,6,7  - mcdram
```

copy binary to phi02

show that compiled code to avx 512 does not work on xeon

```
cd ~/3/
numactl -m 0,1,2,3  - dram
numactl -m 4,5,6,7  - mcdram
```

# OpenMP samples

## OpenMP Sample Program

Build the application for Xeon (without OpenMP Option)
```
icc omp-matrix.c -o omp-matrix
```

The OpenMP pragmas are ignored by compiler:
```
OMP-hello.c(10): warning #3180: unrecognized OpenMP #pragma
      #pragma omp parallel
              ^

OMP-hello.c(19): warning #3180: unrecognized OpenMP #pragma
      #pragma omp for
              ^

OMP-hello.c(24): warning #3180: unrecognized OpenMP #pragma
      #pragma omp for
              ^
```

## Build the application for Xeon
```
icc omp-matrix.c -o omp-matrix -fopenmp
```

## Build the application for Coprocessor
```
icc omp-matrix.c -o omp-matrix.mic -mmic -fopenmp
```

## Launch the application on Xeon
```
export OMP_NUM_THREADS=10
./omp-matrix
```

### Results:

```
hello from hostname phi02.ncc.unesp.br
hello from hostname phi02.ncc.unesp.br
hello from hostname phi02.ncc.unesp.br
hello from hostname phi02.ncc.unesp.br
hello from hostname phi02.ncc.unesp.br
hello from hostname phi02.ncc.unesp.br
hello from hostname phi02.ncc.unesp.br
hello from hostname phi02.ncc.unesp.br
hello from hostname phi02.ncc.unesp.br
hello from hostname phi02.ncc.unesp.br
```

## Launch the application on the Coprocessor from host
```
micnativeloadex ./omp-matrix.mic -e "OMP_NUM_THREADS=10 LD_LIBRARY_PATH=/opt/intel/lib/mic/"

```

### Results:

```
hello from hostname phi02-mic0.ncc.unesp.br
hello from hostname phi02-mic0.ncc.unesp.br
hello from hostname phi02-mic0.ncc.unesp.br
hello from hostname phi02-mic0.ncc.unesp.br
hello from hostname phi02-mic0.ncc.unesp.br
hello from hostname phi02-mic0.ncc.unesp.br
hello from hostname phi02-mic0.ncc.unesp.br
hello from hostname phi02-mic0.ncc.unesp.br
hello from hostname phi02-mic0.ncc.unesp.br
hello from hostname phi02-mic0.ncc.unesp.br
sum of vector elements: 5789.473684
```

# Advisor

  * Transposição de matrizes ("Multithreaded Transposition of Square Matrices with Common Code for Intel Xeon Processors and Intel Xeon Phi Coprocessors" - http://research.colfaxinternational.com/post/2013/08/12/Trans-7110.aspx)

## compilar para Xeon

```
make clean
make runme-CPU
```

## compilar para Xeon Phi

```
make clean
make runme-CPU
```

# Syncronization
## tachyon

# Offload
## offload sample
## offload example
