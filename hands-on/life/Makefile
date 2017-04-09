CC=icc

FLAGS=-O3 -g -I/opt/intel/advisor/include/ -xhost #-fopenmp

all: life

life: life.c
	$(CC) $(FLAGS) life.c -o life

clean:
	rm life
