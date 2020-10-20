# include kernel header files
include_directories(../../kernels/src)
include_directories(utils)

add_subdirectory(utils)

file(GLOB TOOLS_H *.h)

add_executable(ls.mpi ls-parallel.c)
add_executable(ls.serial ls-serial.c)

target_link_libraries(ls.mpi aio_tool_utils)
target_link_libraries(ls.serial aio_tool_utils)

install(TARGETS ls.mpi ls.serial
        RUNTIME DESTINATION bin/
        LIBRARY DESTINATION lib/
        ARCHIVE DESTINATION lib/
)

install(FILES ${TOOLS_H} DESTINATION include)