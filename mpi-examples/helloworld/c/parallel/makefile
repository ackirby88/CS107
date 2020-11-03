EXECS=parallel_hello
MPICC=mpicc

all: ${EXECS}

parallel_hello: mpi_hello_world.c
	${MPICC} -o parallel_hello mpi_hello_world.c

clean:
	rm ${EXECS}
