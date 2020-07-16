# C Programming Basics
Before we dive into C++, let's review some concepts from the C programming language first.

---
## Source Files
We write our code to source files which have the file extension of `.cpp`, `.C`, or `.cxx`.  
C files have the file extension of `.c`.

#### hello.c
We have the canonical *Hello, World!* written in the C programming language.
```C
#include <stdio.h>

int main(void) {
    printf("Hello, world!\n");
    return 0;
}
```  
To compile this code, we can use `gcc` which is the GNU C compiler: `gcc -o hello hello.c`.  
Lastly, we can execute the code `./hello` which results in `Hello, World!`.

## Header Files
Header files usually contain function declarations but can sometimes also contain functions implementations (e.g. inline functions).  
#### hello_1.h
```C
#ifndef HELLO_H
#define HELLO_H
void print_hello_world(void);
#endif /* HELLO_H */

```
#### hello_1.c
```C
#include "hello_1.h"

int main(void){
  print_hello_world();
  return 0;
}

void print_hello_world(void){
  printf("Hello, world!\n");
}
```  
Since programs are compiled top-down, if we didn't have the header file included at the top of the source file, 
the function `print_hello_world()` would not be known by the `main` function. 
Lucky for us, the C preprocessor replaces the `#include "hello_1.h"` line with all of the code found in **hello_1.h**.  
We will learn more about `#include` and the C prepocessor shortly.


---
## Compilation Basics
(*We will have more on this topic later in the semester.*)  

Within this track, we will need to compile our codes.
C and C++ are compiled languages contrasting Python which is an interpreted programming language.  
**Compiled code** means we pass the source code to a compiler which translates it to machine code that the processor executes.  
**Interpreted code** is passed to a seperate program called an *interpreter* which reads each line of code and executes it on the processor.  
Compiled languages are *much faster* than interpreted languages.  

Within this track, we will need to compile our codes. Using the compiler directly in the command line:  
#### hello.c  
```C
#include <stdio.h>

int main(void) {
    printf("Hello, world!\n");
    return 0;
}
```  
#### Compiling on the command line:  
```C
gcc -o hello hello.c
```
Sandbox Demo: [Hello World!](https://bit.ly/2Oq5iV8)  
Guided Exercise: [Hello World Lab!](https://github.com/ackirby88/CS107/blob/master/labs/helloworld/README.md)  

---
## C Preprocessor 
The C preprocessor is a *macro processor* which allows you to define macros (abbreviations).  
It is used **automatically** by the C compiler to transform your program before actual compilation.  

The C preprocessor can perform multiple functions:
- Include header files
- Define macro expansions
- Conditional compilation


### `#include`:  
Both user and system header files are included using the preprocessing directive `#include`. It has three variants:  
`#include <file>`  
`#include "file"`  
`#include `*`anything else'*  

`#define VAR value`: sets `VAR` to `value`  
`#undef VAR`: unsets `VAR`  
`#ifdef VAR` **or** `#if defined VAR`: check of `<VAR>` is defined  
`#ifndef`  
`#pragma once`  

---
### Primitive, Derived, and User-Defined Data Types

---
### Operators, Loops, Functions

---
### Memory, Pointers, References 

---
### Function Pointers
