# ================================= #
# Create variable called "MATRIX_H"
# ================================= #
file(GLOB APP_H *.h *.hpp)

# =================================== #
# Create variable called "MATRIX_SRC"
# =================================== #
set(APP_SRC
    MatrixClass.cpp
)


# Create executable called "mixed" which depends on main.cpp
add_executable(app_demo main.cpp)

# Link our library "MyAwesomeLibrary" to our executable
target_link_libraries(app_demo ${awesome_lb})

# Install targets into specific directories
install(TARGETS app_demo
    RUNTIME DESTINATION bin/
    LIBRARY DESTINATION lib/
    ARCHIVE DESTINATION lib/
)

install(FILES ${APP_H} DESTINATION include)

