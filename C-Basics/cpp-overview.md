Title: C++ Track Overview  
Category: lectures  
Date: 2020-9-22
Slug: lecture5-C++ 
Author: Andrew Kirby  
tags: C++ 

## Background
This track assumes basic programming knowledge at the level covered in [Harvard's CS50](https://cs50.harvard.edu/college/2019/fall/).  
Our goal is to build up your C++ experience and introduce system development techniques for Computational Science & Engineering.

```cpp
class CppTrack: public CS107 {
  public:
    void displayTrack(char advanced) {
      (advanced) ? printf("C++ Track!") : printf("Python Track!");
    }
};
```

---
## C++ Track Outline

**C Basics [Lectures 5-6]**

- [Compilation Basics]({filename}C-0-CompilationBasics.md)
- [Source & Header Files]({filename}C-1-SourceHeaderFiles.md)
- [C-Preprocessor]({filename}C-2-Prepocessor.md)
- [C Data Types]({filename}C-3-CDataTypes.md)
- [Operators, Loops, Functions]({filename}../../lecture6/C++/C-4-OpsLoopsFunctions.md)
- [Arrays, Pointers, Memory, References]({filename}../../lecture6/C++/C-5-Memory.md)
- [Function Pointers]({filename}../../lecture6/C++/C-6-FunctionPointers.md)


**C++ Object-Oriented Programming [Lectures 7-8]**

- [Classes & Objects]({filename}../../lecture7/C++/CPP-0-ClassesObjects.md)
- [Constructors]({filename}../../lecture7/C++/CPP-1-Constructors.md)
- [Inheritence]({filename}../../lecture7/C++/CPP-2-Inheritence.md)
- [Polymorphism]({filename}../../lecture8/C++/CPP-3-Polymorphism.md)
- [Templating and Namespaces]({filename}../../lecture8/C++/CPP-4-Templates-Namespaces.md)

**Tools and Documentation [Lectures 13-14]**

- Project Organization
- Build Systems and Generators: Make, CMake
- Building and Linking Libraries: static/dynamic libraries, mixed-language programming (C++/F90, Python/C++)
- Doxygen, Sphinx
- Testing: TravisCI, Google Test, CMake Tests, Code Coverage

**Design Patterns, Data Structures, Algorithms [Lectures 16-20]**

---

## Supplemental Information  
[C++ Tutorial](http://www.cplusplus.com/doc/tutorial/): Reference tutorial for C++.   
[Deepnote](https://harvard-iacs.github.io/2020-CS107/pages/deepnote.com): Excercises will be hosted in Deepnote as done with the python track.  
[CS50 IDE](https://ide.cs50.io/): Easy collaboration space for C++ and python. Documentation found [here](https://cs50.readthedocs.io/lab/).  
[CS50 Sandbox](https://sandbox.cs50.io/): Some of the lecture content may hosted in a CS50 Sandbox.  
[IDEAS Project](https://ideas-productivity.org/events/hpc-best-practices-webinars/): Best Practices for `Computational Science` Software Developers.  

---
[Next: Compilation Basics]({filename}C-0-CompilationBasics.md)

