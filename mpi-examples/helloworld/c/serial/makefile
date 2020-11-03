EXECS=serial_hello
MPICC=mpicc

all: ${EXECS}

serial_hello: hello_world.c
	${MPICC} -o serial_hello hello_world.c

clean:
	rm ${EXECS}
