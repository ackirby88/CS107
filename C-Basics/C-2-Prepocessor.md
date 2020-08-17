
---
**Key:** 
:large_orange_diamond: - **Code Example** 
:large_blue_diamond: - **Code Exercise** 
:red_circle: - **Code Warning**  
[**Previous**: Source & Header Files](https://github.com/ackirby88/CS107/blob/master/C-Basics/C-1-SourceHeaderFiles.md)  
[**Next**: C Data Types](https://github.com/ackirby88/CS107/blob/master/C-Basics/C-3-CDataTypes.md)

---
# C Preprocessor (cpp)
The C Preprocessor is a *macro processor* which allows you to define macros (abbreviations).  
It is used **automatically** by the C compiler to transform your program before actual compilation.  

The C Preprocessor can perform multiple functions:
- Include header files - files of declarations that can be substituted into your program
- Define macro expansions - abbreviations that are expanded with their definition in line
- Conditional compilation - include or exclude specific definitions using conditionals
- Line control - inform the compiler of where source lines originated from when a program to used to combine or rearrange source files into an intermediate file which is then compiled

## Preprocessor Directives
Preprocessor directives are lines starting with the character `#`, e.g. `#define FOO 107`.  
Whitespace is also allowed before and after the `#`, and directives can expand over multiple lines by using the character `\`.  
**<details><summary>:large_orange_diamond: Macro Define: cubeThreads</summary>**
<p>
  
```C
#define cubeThreads              \
  for (int k = 0; k < 4; ++k)    \
    for (int j = 0; j < 3; ++j)  \
      for (int i = 0; i < 6; ++i)
```
</p>
</details>

**<details><summary>:large_orange_diamond: Usage: cubeThreads</summary>**
<p>
  
```C
cubeThreads {
  my_array[k][j][i] = 2*i + j + 3*k;
}
```
</p>
</details>

---
### **`#include`**
Both user and system header files are included using the preprocessing directive `#include`.
- [x] `#include <file>`: **include system header files**  
The preprocessor searches for a file named *file* in a list of directories specified by you, then in a standard list of system directories. 
You specify directories to search for header files with the command option `-I`.  
To see which directories the C Preprocessor searches, we can execute `cpp -v`.  

**<details><summary>:large_orange_diamond: C Preprocessor Search Locations: `cpp -v`</summary>**
<p>
  
> ```bash
> $ cpp -v
> ...
> #include "..." search starts here:
> #include <...> search starts here:
> /usr/lib/gcc/x86_64-linux-gnu/7/include
> /usr/local/include
> /usr/lib/gcc/x86_64-linux-gnu/7/include-fixed
> /usr/include/x86_64-linux-gnu
> /usr/include
> End of search list.
> ```
</p>
</details>

- [x] `#include "file"`: **include header files of your own program**  
The preprocessor searches for a file named *file* first in the current directory, then in the same directories used for system header files.  

- [x] `#include`*`anything else`*:   
This is known as a *computed #include* directive where *anything else* can be other macros, which are expanded. After the expansion, it must conform one of the first two variants: `<file>` or `"file"`.

#### How `#include` Works
Looking at **Example 1**, the C Proprocessor generates the following from **hello_1.h** to **hello_1.c**: 
**<details><summary>:large_orange_diamond: Example 1</summary>**
<p>

**hello_1.h**
```C
void print_hello_world(void);
```
**hello_1.c**
```C
#include <stdio.h>
#include "hello_1.h"

int main(void){
  print_hello_world();
  return 0;
}

void print_hello_world(void){
  printf("Hello, World!\n");
}
```
</p>
</details>

**<details><summary>:large_orange_diamond: Example 1: Post-Preprocessor</summary>**
<p>
  
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
</p>
</details>

- Note that the C Preprocessor would also replace `#include <stdio.h>` accordingly.  

---
#### Include Guards: Once-Only Include Files
You will most likely include a header file multiple times in a project. This may lead to compiling errors if the header file contains defined data types.
To fix this, we normally add *Include Guards* in the header file:  
```C
// include guards
#ifndef HELLO_H
#define HELLO_H
void print_hello_world(void);
#endif /* HELLO_H */
```
Notice that the macro `HELLO_H` indicates that the file has been included once already. If a subsequent `#include` specifies the same file, and the macro in the `#ifndef` is already defined, then the file contents within the directives are skipped completely.  

You may see `#pragma once` which is a **non-standard** but widely used directive designed to cause the current source file to be included only once in a single compilation. **However, `#pragma once` is now obsolete and should not be used.**  

:large_orange_diamond: [Header File Collision](https://bit.ly/32NDaUr)

---
## Simple Macros

### **`#define`**:  
As we have seen, we can make a macro that serves as a substitution or abbreviation. Before we can use the macro, it must first be defined with the `#define` directive.

- [x] `#define VAR value`: sets `VAR` to `value`  

**<details><summary>:large_orange_diamond: Define Macro Expansion</summary>**
<p>

```C
#define BUFFER 128
char *str = (char *) malloc(BUFFER);
```
**Expanded result:**
```C
char *str = (char *) malloc(128);
```
</p>
</details>

Note that the C preprocessor is sequential top-down.
**<details><summary>:large_orange_diamond: Define Macro Top-Down Expansion</summary>**
<p>

```C
course = CS
#define CS 107
num = CS
``` 
**Expanded result:**
```C
course = CS
num = 107
``` 
</p>
</details>

---
### **`#undef`:**
We can also undefine a variable as follows:
- [x] `#undef VAR`: unsets `VAR`  

**<details><summary>:large_orange_diamond: Undefine Macro Example</summary>**
<p>
  
```C
#define CS 107
course = CS
#undef CS
num = CS
``` 
**Expanded result:**
```C
course = 107
num = CS
```
</p>
</details>

---
#### Macro Naming Conventions
:arrow_right: **NOTE**: In a **user** header file, the macro name should **not** begin with `_`; this is due to avoiding collisions with system header files which normally begin with `__`. It is good practice to make the macro contain the name of the file and possibly additional text to avoid conflicts with other header files.

**Bad User Macro Naming**: `#define _MYVAR_` or `#define __TESTVAR__`.

---
## Conditional Macros
A conditional in the C preprocessor begins with a conditional directive: `#if`, `#ifdef` or `#ifndef`.  
These conditional macros need to be closed with the directive `#endif`.
- [x] `#if` Directive: Basic conditionals paired with`#endif`.
- [x] `#else` Directive: Including some text if the condition fails.
- [x] `#elif` Directive: Testing several alternative possibilities.

Example:  
**<details><summary>:large_orange_diamond: Conditional Macro Example</summary>**
<p>
  
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
</p>
</details>

---
### **`#ifdef`:** Check if a variable has been defined using two directives

- [x] `#ifdef VAR`
- [x] `#if defined VAR`

---
### **`#ifndef`:** Check if a variable has not been defined
- [x] `#ifndef VAR`

---
## Macros With Arguments
Macros can be more flexible when they accept arguments. Arguments are fragments of code that you supply each time the macro is used. These fragments are included in the expansion of the macro according to the directions in the macro definition.  

A macro that accepts arguments is called a *function-like* macro because the syntax for using it looks like a function call.

- Define a macro with arguments: **write a `#define` directive with a list of argument names in parentheses after the macro name**
- **Open-parenthesis must follow the macro name immediately (no space in between)**

For example, here is a macro that computes the minimum of two numeric values, as it is defined in many C programs:
```C
#define MIN(X, Y)  ((X) < (Y) ? (X) : (Y))
```
An example usage could be `MIN(2,3)` resulting in the expected value `2`.   
We can even do `MIN(cs + 107, *p)` which expands to `((cs + 107) < (*p) ? (cs + 107) : (*p))`

---
### :red_circle: Macros With Arguments: Unintended Consequences
We can have unintended side effects using macros for function-like expressions. :red_circle:  

For example, if we defined a MAX function as follows:
**<details><summary>:red_circle: Buggy Macro Example</summary>**
<p>
  
```C
#define MAX(a,b) a > b ? a : b
```
</p>
</details>

**<details><summary>:red_circle: Buggy Macro Example: Usage</summary>**
<p>
  
```C
i = MAX(2,3)+5;
j = MAX(3,2)+5;
```
</p>
</details>

**<details><summary>:red_circle: Buggy Macro Example: Expansion</summary>**
<p>
  
```C
i = 2 > 3 ? 2 : 3+5;
j = 3 > 2 ? 3 : 2+5;
```
</p>
</details>

**<details><summary>:red_circle: Buggy Macro Example: Result</summary>**
<p>
  
```C
i = 8
j = 3
```
</p>
</details>

**Be sure to use extra parenthesis for these scenarios!**

:large_orange_diamond: [3D Function Arguments](https://bit.ly/3e6HLD2)  
If caution is taken, macros with arguments can be combined to make useful programming options. 
Let's suppose that we want to build a program that depends on physical space dimensions: 2D or 3D. We would like to have our functions take additional arguments without having to make a new function (recall that C programming does **not** allow function overloading).  

## Some Useful Macros
- `__FILE__` The name of the current file, as a string literal
- `__LINE__` Current line of the source file, as a numeric literal
- `__DATE__` Current system date, as a string
- `__TIME__` Current system time, as a string
- `__cplusplus` Undefined for C code compiled by a C compiler; `199711L` C code is compiled by a C++ compiler (98 C++ standard)
- `__func__` Current function name of the source file, as a string (part of C99)

:large_orange_diamond: [Macro Example](https://bit.ly/3hpti7g)

## C Preprocessor Exercises
:large_blue_diamond: [Fix Max Define Bug](https://bit.ly/2BpdkL2)  
:large_blue_diamond: Build a program that uses `float` when the macro `SINGLE_PRECISION` is defined, otherwise uses `double` as the floating pointing representation by defining a macro.

---
[**Next**: C Data Types](https://github.com/ackirby88/CS107/blob/master/C-Basics/C-3-CDataTypes.md)
