# include kernel header files
include_directories(../../../kernels/src)

file(GLOB TOOL_UTILS_H *.h)

set(TOOL_UTILS_SRC
    command_line.c
)

add_library(aio_tool_utils SHARED ${TOOL_UTILS_SRC} ${TOOL_UTILS_H})
target_link_libraries(aio_tool_utils aio_kernels)

install(TARGETS aio_tool_utils
        RUNTIME DESTINATION bin/
        LIBRARY DESTINATION lib/
        ARCHIVE DESTINATION lib/
)

install(FILES ${TOOL_UTILS_H} DESTINATION include)