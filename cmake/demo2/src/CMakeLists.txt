
# Create variable called "DEMO_H" which contains all files ending in *.h
file(GLOB DEMO_H *.h)

# Create variable called "DEMO_SRC" containing all entries following it
set(DEMO_SRC
    SampleClass.cpp
)

# Build shared library
add_library(sampleLibrary SHARED ${DEMO_SRC} ${DEMO_H})

# Create executable called "demo2" which depends on main.cpp
add_executable(demo2 main.cpp)

# Link our shared library "sampleLibrary" to our executable "demo2"
target_link_libraries(demo2 sampleLibrary)

# Install targets into specific directories
install(TARGETS demo2 sampleLibrary
	RUNTIME DESTINATION bin/
	LIBRARY DESTINATION lib/
	ARCHIVE DESTINATION lib/
)

install(FILES ${DEMO_H} DESTINATION include)
