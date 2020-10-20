# ============ #
# source files
# ============ #
set(F95_KERNELS
    add_matrix.F95
)

# ==================== #
# build shared library
# ==================== #
add_library(f95_kernels SHARED ${F95_KERNELS})

# =========================== #
# install f95_kernels library
# =========================== #
install(TARGETS f95_kernels
        RUNTIME DESTINATION bin/
        LIBRARY DESTINATION lib/
        ARCHIVE DESTINATION lib/
)
