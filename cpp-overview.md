Title: C++ Track Overview  
Category: lectures  
Date: 2019-11-22  
Slug: lecture5-C++-Overview  
Author: Andrew Kirby  
tags: C++  

## Background
This track assumes basic programming knowledge at the level covered in [Harvard's CS50](https://cs50.harvard.edu/college/2019/fall/).  
Our goal will be to build up your C++ experience and introduce system development techniques for Computational Science & Engineering.

```C++
class CppTrack: public CS107 {
  public:
    void displayTrack(char advanced) {
      (advanced) ? printf("C++ Track!") : printf("Python Track!");
    }
};
```

---
## C++ Track Outline
- C Basics [Lectures 5-6]
  - Source and Header Files
  - C-preprocessor
  - Compilation Basics
  - Primitive, Derived, and User-Defined Data Types
  - Operators, Loops, Functions
  - Memory, Pointers, References 
  - Function Pointers

- C++ Object-Oriented Programming [Lectures 7-8]
  - Classes/Objects: methods, constructors, access, operator overloading
  - Inheritence: (pure) virtual functions
  - Templating

- Tools and Documentation [Lectures 13-14]
  - Project Organization
  - Build Systems and Generators: Make, CMake
  - Building and Linking Libraries: static/dynamic libraries, mixed-language programming (C++/F90, Python/C++)
  - Doxygen, Sphinx
  - Testing: TravisCI, Google Test, CMake Tests, Code Coverage

- Design Patterns, Data Structures, Algorithms [Lectures 16-20]  

---

## Supplemental Information  
[C++ Tutorial](http://www.cplusplus.com/doc/tutorial/): Reference tutorial for C++.   
[Deepnote](https://harvard-iacs.github.io/2020-CS107/pages/deepnote.com): Excercises will be hosted in Deepnote as done with the python track.  
[CS50 IDE](https://ide.cs50.io/): Easy collaboration space for C++ and python. Documentation found [here](https://cs50.readthedocs.io/lab/).  
[CS50 Sandbox](https://sandbox.cs50.io/): Some of the lecture content may hosted in a CS50 Sandbox.  
[IDEAS Project](https://ideas-productivity.org/events/hpc-best-practices-webinars/): Best Practices for `Computational Science` Software Developers.  

---
[Next: Introduction to C++]({filename}intro-C++.md)

