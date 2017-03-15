CC=icc

FLAGS=-O3 -g -I/opt/intel/advisor/include/ -xhost #-fopenmp

all: life

life: lifeOMP.c
	$(CC) $(FLAGS) lifeOMP.c -o lifeOMP

clean:
	rm lifeOMP
