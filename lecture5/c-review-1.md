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

:large_orange_diamond: Sandbox Example: [Hello World!](https://bit.ly/2Oq5iV8)  
:large_orange_diamond: Guided Example: [Hello World Lab!](https://lab.cs50.io/ackirby88/CS107/master/labs/helloworld/)
([Github markdown](https://github.com/ackirby88/CS107/blob/master/labs/helloworld/README.md))

---
## Source Files
We will write our C++ code to source files which have the file extension of `.cpp`, `.cc`, `.C`, or `.cxx`.  
C files have the file extension of `.c`.

## Header Files
Header files usually contain function declarations but can sometimes also contain functions implementations, e.g. inlined functions.  
Header files can be used used to share these declarations and macro expansions across multiple files.  

Here we can see a function declaration for the function `print_hello_world()`:
#### Example 1: hello_1.h
```C
void print_hello_world(void);
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
:large_orange_diamond: Sandbox Example: [FIXME Hello World with header files!](...)

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

#### How `#include` Works
Looking at **Example 1**, the C Proprocessor generates the following from **hello_1.h** to **hello_1.c**:  
```C
#include <stdio.h>
void print_hello_world(void);

int main(void){
  print_hello_world();
  return 0;
}

void print_hello_world(void){
  printf("Hello, world!\n");
}
```  
Note that the C Preprocessor would also replace `#include <stdio.h>` accordingly.  

#### Include Guards: Once-Only Include Files
You will most likely include a header file multiple times in a project. This may lead to compiling errors if the header file contains defined data types.
To fix this, we normally add *Include Guards* in the header file:  
```C
#ifndef HELLO_H
#define HELLO_H
void print_hello_world(void);
#endif /* HELLO_H */
```
Notice that the macro `HELLO_H` indicates that the file has been included once already. If a subsequent `#include` specifies the same file, and the macro in the `#ifndef` is already defined, then the file contents within the directives are skipped completely.  

You may see `#pragma once` which is a non-standard but widely used directive designed to cause the current source file to be included only once in a single compilation. **However, `#pragma once` is now obsolete and should not be used.**  

:large_orange_diamond: Guided Example: [FIXME Header File Collision Lab]()

:arrow_right: **NOTE**: In a **user** header file, the macro name should **not** begin with `_`; this is due to avoiding collisions with system header files which normally begin with `__`. It is good practice to make the macro contain the name of the file and possibly additional text to avoid conflicts with other header files.

## Simple Macros

### **`#define`**:  
As we have seen, we can make a macro that serves as a substitution or abbreviation. Before we can use the macro, it must first be defined with the `#define` directive.  
- [x] `#define VAR value`: sets `VAR` to `value`  
Example:
```C
#define BUFFER 128
char *str = (char *) malloc(BUFFER);
```
results in the expanded version  
```C
char *str = (char *) malloc(128);
```
Note that the C preprocessor is sequential top-down. So given the following as input to the C Preprocessor 
```C
course = CS
#define CS 107
num = CS
``` 
results in the expanded version
```C
course = CS
num = 107
``` 

### **`#undef`**
We can also undefine a variable as follows:
- [x] `#undef VAR`: unsets `VAR`  
Example:
```C
#define CS 107
course = CS
#undef
num = CS
``` 
results in the expanded version
```C
course = 104
num = CS
```
## Conditional Macros
A conditional in the C preprocessor begins with a conditional directive: `#if`, `#ifdef` or `#ifndef`.  
These conditional macros need to be closed with the directive `#endif`.
- [x] `#if` Directive: Basic conditionals paired with`#endif`.
- [x] `#else` Directive: Including some text if the condition fails.
- [x] `#elif` Directive: Testing several alternative possibilities.

Example:  
```C
#if X == 1
...
#else /* X != 1 */
#  if X == 2
...
#  else /* X != 2 */
...
#  endif
#endif
```

### **`#ifdef`**
We can check if a variable has been defined using two directives:
- [x] `#ifdef VAR`
- [x] `#if defined VAR`

### **`#ifndef`**
We can also check if a variable has not been defined:
- [x] `#ifndef VAR`

## Macros With Arguments
Macros can be more flexible when they accept arguments. Arguments are fragments of code that you supply each time the macro is used.  
These fragments are included in the expansion of the macro according to the directions in the macro definition.  
A macro that accepts arguments is called a *function-like* macro because the syntax for using it looks like a function call.

To define a macro that uses arguments, you write a `#define` directive with a list of argument names in parentheses after the name of the macro.  
The open-parenthesis must follow the macro name immediately, with no space in between.

For example, here is a macro that computes the minimum of two numeric values, as it is defined in many C programs:
```C
#define MIN(X, Y)  ((X) < (Y) ? (X) : (Y))
```
An example usage could be `MIN(2,3)` resulting in the expected value `2`.   
We can even do `MIN(cs + 107, *p)` which expands to `((cs + 107) < (*p) ? (cs + 107) : (*p))`

:red_circle: **WARNING**: We could have unintended side effects using macros for function-like expressions.  
For example, if we defined a MAX function as  
```C
#define MAX(a,b) a > b ? a : b
```
and the code
```C
i = MAX(2,3)+5;
j = MAX(3,2)+5;
```
Then the expansion gives
```C
i = 2 > 3 ? 2 : 3+5;
j = 3 > 2 ? 3 : 2+5;
```
Thus, after execution **`i=8`** and **`j=3`** instead of **`i=j=8`**!  
So be sure to use extra parenthesis for these scenarios.

:large_orange_diamond: **Example**: [3D Function Arguments](https://bit.ly/3e6HLD2)  
If caution is taken, macros with arguments can be combined to make useful programming options. 
Let's suppose that we want to build a program that depends on physical space dimensions: 2D or 3D. We would like to have our functions take additional arguments without having to make a new function (recall that C programming does **not** allow function overloading).  

## Some Useful Macros
- `__FILE__` The name of the current file, as a string literal
- `__LINE__` Current line of the source file, as a numeric literal
- `__DATE__` Current system date, as a string
- `__TIME__` Current system time, as a string
- `__cplusplus` Undefined for C code compiled by a C compiler; `199711L` C code is compiled by a C++ compiler (98 C++ standard)
- `__func__` Current function name of the source file, as a string (part of C99)

## C Preprocessor Exercises
:large_blue_diamond: Exercise: [Fix Max Define Bug](...)  
:large_blue_diamond: Build a program that uses `float` when the macro `SINGLE_PRECISION` is defined, otherwise uses `double` as the floating pointing representation by defining a macro.

---
[Next: C Language Specifics](https://github.com/ackirby88/CS107/blob/master/lecture5/c-review-2.md)
