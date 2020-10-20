
# ================================= #
# Create variable called "MATRIX_H"
# ================================= #
file(GLOB MATRIX_H *.h)

# =================================== #
# Create variable called "MATRIX_SRC"
# =================================== #
set(MATRIX_SRC
    MatrixClass.cpp
)

# ==================== #
# Build shared library
# ==================== #
add_library(matrixClass SHARED ${MATRIX_SRC} ${MATRIX_H})


# =================================================================== #
# Optional Fortran95 Math Library:
#   NOTE: use ccmake or cmake-gui to enable library!
# =================================================================== #
OPTION(ENABLE_F95_KERNELS "Enable to use Fortran95 Math Kernels" OFF)

if(ENABLE_F95_KERNELS) 
  # Fortran math kernels
  add_subdirectory(src-F95)

  # link Fortran math kernels to matrixClass shared library
  target_link_libraries(matrixClass f95_kernels)

  # add compiler directive
  target_compile_definitions(matrixClass PUBLIC -DF95_MATH)
endif()
# =================================================================== #

# Create executable called "mixed" which depends on main.cpp
add_executable(mixed main.cpp)

# Link our shared library "matrixClass" to our executable "mixed"
target_link_libraries(mixed matrixClass)

# Install targets into specific directories
install(TARGETS mixed matrixClass
	RUNTIME DESTINATION bin/
	LIBRARY DESTINATION lib/
	ARCHIVE DESTINATION lib/
)

install(FILES ${MATRIX_H} DESTINATION include)
