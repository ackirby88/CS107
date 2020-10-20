## Configure and Build Instructions


### Enable Fortran95 External Library
1. Inside the build directory, type `ccmake . `.  
   This will display a text-based CMake configuration gui.  
2. Go to `ENABLE_F95_KERNELS`, hit **enter** to toggle the option to `ON`.
3. Hit `c` to configure.
4. Hit `g` to generate and exit.
5. Type `make install`.
6. `cd bin`
7. `./mixed`
