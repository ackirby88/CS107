# ======================== #
# Compiler Parallel/Serial #
# ======================== #
ifdef MPIPRG
  CC = mpic++
  FC = mpif90
else
  CC = g++
  FC = gfortran
endif

# ================== #
# Optimization level #
# ================== #
ifdef DEBUG
  # Debug Flags: "make gnu DEBUG=1"
  CFLAGS = -O0 -pg -Wall -Wextra -pedantic
  FFLAGS = -O0 -pg -Wall -Wextra -pedantic -fimplicit-none -fbounds-check -fbacktrace -ffpe-trap=zero,overflow,underflow 
else
  CFLAGS = -O2
  FFLAGS = -O2
endif

# ====== #
# Linker #
# ====== #
LD = $(CC)

# ======== #
# Archiver #
# ======== #
AR = ar

# ============= #
# Linking flags #
# ============= #
LDFLAGS = $(FFLAGS)

# ============== #
# Archiver flags #
# ============== #
ARFLAGS = rv

# ==================== #
# Indexing the archive #
# ==================== #
RANLIB = ranlib
