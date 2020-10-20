file(GLOB KERNELS_H *.h)

set(KERNELS_SRC
    aio_mpi.c
    aio_file.c
    aio_utilities.c
)

add_library(aio_kernels SHARED ${KERNELS_SRC} ${KERNELS_H})

add_executable(aio main.c)
target_link_libraries(aio aio_kernels)

install(TARGETS aio aio_kernels
        RUNTIME DESTINATION bin/
        LIBRARY DESTINATION lib/
        ARCHIVE DESTINATION lib/
)

install(FILES ${KERNELS_H} DESTINATION include)