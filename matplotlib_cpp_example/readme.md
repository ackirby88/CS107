## Matplotlib for C++ on Deepnote
- This code demonstrates how to use Python's Matplotlib via a C++ API.  
- It uses CMake to obtain all necessary libraries and generate the makefile.  
- CMake is preinstalled in the terminal environment on Deepnote.

---
[Matplotlib for C++](https://matplotlib-cpp.readthedocs.io/en/latest/index.html): Documentation to Matplotlib for C++, a C++ wrapper for Python’s matplotlib (MPL) plotting library.  
[Examples](https://github.com/Cryoris/matplotlib-cpp/tree/master/examples): Lots of examples can be found in the source repo.

---

## Quick Start
- `./config.sh`
- `cd bin`
- `./example`  
**NOTE:** These examples do not display to figures to the screen, but they do plot the figures to pdf files.
---

#### Configuring
:red_circle: WARNING :red_circle: The configure script forces a hook into Deepnote's Python site-packages (see config.sh).   

First, run the `config.sh` script.  
You will only need to do this one time (unless you add more source files to CMakeLists.txt).

#### Modifying
The file `main.cpp` is located in the `src` directory. You can modify this file or add new source files.  
**If you add new source files, you will need to modify the CMakeLists.txt file by adding file names starting at Line 41.**

#### Rebuilding
To rebuild the executable after modification, go to the `builds` directory.  
Within this directory, type `make` or `make clean; make`.  
This is rebuild the code and place the new executable into the `bin` directory.

#### Executing
Go to the `bin` directory.  
Execute via `./example`.

**NOTE:** The examples do not display to figures to the screen, but they do plot the figures to pdf files.
