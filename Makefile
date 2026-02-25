build:
	mpicc main.c -g -Wall
build-release: 
	mpicc main.c -o2
run:
	mpiexec -n 4 a.out

test: build run
