EXECS=sendrecv.mpi
MPICC=mpicc

all: sendrecv.o
	${MPICC} sendrecv.o -o ${EXECS}

sendrecv.o: sendrecv.c
	${MPICC} -c sendrecv.c

clean:
	@( $(RM) *.o *.mod *~ ${EXECS})
