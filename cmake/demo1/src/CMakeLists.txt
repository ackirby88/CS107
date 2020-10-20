
# make variable called "DEMO_H" which contains all files ending in *.h
file(GLOB DEMO_H *.h)

# make variable called "DEMO_SRC" containing all entries following it
set(DEMO_SRC
    SampleClass.cpp
)

# make executable called "demo1" which depends all things following the name
add_executable(demo1 main.cpp ${DEMO_SRC} ${DEMO_H})
