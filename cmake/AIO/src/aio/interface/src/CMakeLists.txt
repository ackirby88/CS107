# include kernel header files
include_directories(../../kernels/src)

file(GLOB INTERFACE_H *.h)
set(INTERFACE_SRC
    aio_interface.c
)

add_library(aio_interface SHARED ${INTERFACE_SRC})
target_link_libraries(aio_interface aio_kernels)

install(TARGETS aio_interface
        RUNTIME DESTINATION bin/
        LIBRARY DESTINATION lib/
        ARCHIVE DESTINATION lib/
)

install(FILES ${INTERFACE_H} DESTINATION include)