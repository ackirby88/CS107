###############################
### MPI Compilers and Flags ###
###############################
MPICC  = mpicc
MPICXX = mpicxx
CFLAGS = # -g -O0 -Wall


#########################
### Include Directory ###
#########################
INCLUDE := .
VPATH = .

####################
### Source Files ###
####################
SRCS = stencil.c stencil_par.c
OBJS = $(SRCS:.c=.o)


##################
### Executable ###
##################
EXEC = mpi_stencil

# math library
LIBS = -lm

##################
# default target #
##################
all: $(EXEC)


############################################################
# Exec depends on the object files
# it is made automatically using the LDFLAGS variables
# $@ : the file name of the target
# $^ : The names of all the dependencies sperated by spaces,
#      but with duplicate names removed.
############################################################
$(EXEC): $(OBJS)
	$(MPICC) $(CFLAGS) $(OBJS) $(LIBS) -o $@


################################################################################
# The .o files are made automatically using the CXXFLAGS and FORFLAGS variables.
# $< : The name of the first dependency, any dependency that is more recent than
#      its corresponding target. It will recompile any F95 or cpp file if it is
#      newer than the corresponding .o file.
################################################################################
%.o : %.c
	$(MPICC) -I$(INCLUDE) -c $(CFLAGS) $<

%.o : %.cxx
	$(MPICXX) -I$(INCLUDE) -c $(CFLAGS) $<


############
# Clean up #
############
.PHONY: clean


# Maintanace Targets
# ----------------------------------------------
clean:
	@echo "*** Clean : removing object files    "
	@( $(RM) *.o *.mod *~)
	@( $(RM) $(EXEC))

