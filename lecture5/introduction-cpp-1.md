# C Programming Basics

## Compilation Basics
(*We will have more on this topic later in the semester.*)  

Within this track, we will need to compile our codes.  
C and C++ are compiled programming languages contrasting Python which is an interpreted language.  
Compiled languages are usually *much faster* than interpreted languages.

**Compiled** languages pass the source code to a compiler, which is translated directly to machine code.  
**Interpreted** languages pass the source code to a separate program called an *interpreter*, which reads each line of code and then executes it on the processor. 

Let's take a look at the canonial **Hello, World!** to learn the basics of compiling programs from source files.  
#### Example 0: hello.c
```C
#include <stdio.h>

int main(void) {
  printf("Hello, World!\n");
  return 0;
}
```  
#### Compiling on the command line:  
```C
gcc -o hello hello.c
```
Here, `gcc` is the GNU C compiler, `-o hello` tells the compiler to *output* a program named `hello`, and we provide the **hello.c** source file as the input.  
We can also compile the single file using **make**: `make hello`

#### Executing on the command line:
```C
./hello
>>> Hello, World!
```

Sandbox Demo: [Hello World!](https://bit.ly/2Oq5iV8)  
Guided Exercise: [Hello World Lab!](https://lab.cs50.io/ackirby88/CS107/master/labs/helloworld/)
([Github markdown](https://github.com/ackirby88/CS107/blob/master/labs/helloworld/README.md))

---
## Source Files
We will write our C++ code to source files which have the file extension of `.cpp`, `.C`, or `.cxx`.  
C files have the file extension of `.c`.

## Header Files
Header files usually contain function declarations but can sometimes also contain functions implementations, e.g. inlined functions.  
Header files can be used used to share these declarations and macro expansions across multiple files.  

Here we can see a function declaration for the function `print_hello_world()`:
#### Example 1: hello_1.h
```C
#ifndef HELLO_H
#define HELLO_H

void print_hello_world(void);

#endif /* HELLO_H */

```
#### Example 1: hello_1.c
```C
#include <stdio.h>
#include "hello_1.h"

int main(void){
  print_hello_world();
  return 0;
}

void print_hello_world(void){
  printf("Hello, world!\n");
}
```  
If we don't include the header file `hello_1.h` containing the function declaration `print_hello_world()` at the top of the source file, then the function `print_hello_world()` would not be known by the `main` function. This is because programs compiled with gcc are parsed *top-down*.  
Luckily for us, the C Preprocessor replaces the `#include "hello_1.h"` line with all of the code found in **hello_1.h**.

---
## C Preprocessor (cpp)
The C Preprocessor is a *macro processor* which allows you to define macros (abbreviations).  
It is used **automatically** by the C compiler to transform your program before actual compilation.  

The C Preprocessor can perform multiple functions:
- Include header files - files of declarations that can be substituted into your program
- Define macro expansions - abbreviations that are expanded with their definition in line
- Conditional compilation - include or exclude specific definitions using conditionals
- Line control - inform the compiler of where source lines originated from when a program to used to combine or rearrange source files into an intermediate file which is then compiled

### Preprocessor Directives
Preprocessor directives are lines starting with the character `#`, e.g. `#define FOO 107`.  
Whitespace is also allowed before and after the `#`, and directives can expand over multiple lines by using the character `\`.  
```C
#define cubeThreads              \
  for (int k = 0; k < 4; ++k)    \
    for (int j = 0; j < 3; ++j)  \
      for (int i = 0; i < 6; ++i)
```  
Example Usage:  
```C
cubeThreads {
  my_array[k][j][i] = 2*i + j + 3*k;
}
```

### **`#include`**
Both user and system header files are included using the preprocessing directive `#include`.
- [x] `#include <file>`: **include system header files**
The preprocessor searches for a file named *file* in a list of directories specified by you, then in a standard list of system directories. 
You specify directories to search for header files with the command option `-I`.  
To see which directories the C Preprocessor searches, we can execute `cpp -v`.  
> ```bash
> $ cpp -v
> ...
> #include "..." search starts here:
> #include <...> search starts here:
> /usr/lib/gcc/x86_64-linux-gnu/7/include
> /usr/local/include
> /usr/lib/gcc/x86_64-linux-gnu/7/include-fixed
>  /usr/include/x86_64-linux-gnu
>  /usr/include
> End of search list.
> ```

- [x] `#include "file"`: **include header files of your own program**  
The preprocessor searches for a file named *file* first in the current directory, then in the same directories used for system header files.  

- [x] `#include`*`anything else`*:   
This is known as a *computed #include* directive where *anything else* can be other macros, which are expanded. After the expansion, it must conform one of the first two variants: `<file>` or `"file"`.

### **`#define`/`#undef`**
`#define VAR value`: sets `VAR` to `value`  
`#undef VAR`: unsets `VAR`  


### **`#ifdef`/`#ifndef`**
`#ifdef VAR` **or** `#if defined VAR`: check of `<VAR>` is defined  

### **`#pragma once`**

---
Before we dive into C++, let's first review some concepts from the C programming language.

---
### Primitive, Derived, and User-Defined Data Types

---
### Operators, Loops, Functions

---
### Memory, Pointers, References 

---
### Function Pointers
