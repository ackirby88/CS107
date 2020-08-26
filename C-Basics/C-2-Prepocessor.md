Title: C/C++ Preprocessor
Category: lectures
Date: 2020-9-22
Slug: lecture5-C++/C2
Author: Andrew Kirby
Tags: C, C++, Preprocessor

---
**Key:** 
:large_orange_diamond: - **Code Example** 
:large_blue_diamond: - **Code Exercise** 
:red_circle: - **Code Warning**  
[**Previous**: Source & Header Files]({filename}C-1-SourceHeaderFiles.md)  
[**Next**: C Data Types]({filename}C-3-CDataTypes.md)

---
# C Preprocessor (cpp)
The C Preprocessor is a *macro processor* which allows you to define macros (abbreviations).  
It is used **automatically** by the C compiler to transform your program before actual compilation.  

The C Preprocessor can perform multiple functions:  
- **Include header files:** files of declarations that can be substituted into your program  
- **Define macro expansions:** abbreviations that are expanded with their definition in line  
- **Conditional compilation:** include or exclude specific definitions using conditionals  

## Preprocessor Directives
- **Preprocessor directives are lines starting with the character `#`**, e.g. `#define FOO 107`
- **Whitespace is also allowed before and after the `#` symbol**
- **Directives can expand over multiple lines by using the character `\`**
 
**Example:**  
**<details><summary> :large_orange_diamond: Macro Define: cubeThreads</summary>**
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

- `#include <file>:` **include system header file**  
The preprocessor searches for *file* in system directories (see the directory seearch list: `cpp -v`).  

- `#include "file"`: **include header files of your own program**  
The preprocessor searches for *file* first in the current directory, then in the same directories used for system header files.  

- `#include` *`anything else`*:   
This is known as a *computed #include* directive where *anything else* can be other macros, which are expanded.  
After the expansion, it must conform one of the first two variants: `<file>` or `"file"`.  

#### How `#include` Works
Looking at our **Hello, World!** example, the C Proprocessor generates the following from **hello_1.h** to **hello_1.c**: 

**<details><summary>:large_orange_diamond: Before Pre-Processing</summary>**
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

**<details><summary>:large_orange_diamond: After Pre-Processing</summary>**
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
You will most likely include a header file multiple times in a project.

- Compiling error occurs if a header file is included multiple times in the same file (variables/functions get defined multiple times)
- **The FIX:** Add *Include Guards* in the header file

**<details><summary>:large_orange_diamond: print_hello_world.h</summary>**
<p>

```C
// include guards
#ifndef HELLO_H
#define HELLO_H

/* system header files */
#include <stdio.h>

/* function declarations */
void print_hello_world(void);

#endif /* HELLO_H */
```
</p>
</details>

**<details><summary>:large_orange_diamond: print_hello_world.c</summary>**
<p>

```C
/* header files */
#include "print_hello_world.h"
#include "print_hello_world.h" // include 2nd time!

int main(){
  print_hello_world();
  return 0;
}

void print_hello_world(void){
  printf("Hello, World!\n");
}
```
</p>
</details>

- The macro `HELLO_H` indicates that the file has been included once already  
- If a subsequent `#include` specifies the same file, and the macro in the `#ifndef` is already defined, then the contents within the directives are skipped  

**NOTE:** You may see `#pragma once` which is a **non-standard** macro.

- Widely used directive designed to cause the current source file to be included only once in a single compilation
- **`#pragma once` is now obsolete and should not be used!**  

:large_orange_diamond: [Deepnote: Header File Collision](https://deepnote.com/project/fdeed75f-9b4a-428c-8bb7-3766103008ee)

---
## Simple Macros

#### **`#define`:** define a variable 
As we have seen, we can make a macro that serves as a substitution or abbreviation.  
Before we can use the macro, it must first be defined with the `#define` directive.  

- `#define VAR value`: sets `VAR` to `value`  

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
#### **`#undef`:** undefine a macro variable

- `#undef VAR`: unsets `VAR`  

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
- In **user** header files: the macro name should **not** begin with `_`  
- Avoid naming collisions with system header files which normally begin with `__`  
- Good practice: macro name contains file name and additional text to avoid conflicts with other header files

**Bad User Macro Naming Examples:**

- `#define _MYVAR_`
- `#define __TESTVAR__`

---
## Conditional Macros
A conditional in the C preprocessor begins with a conditional directive: `#if`, `#ifdef` or `#ifndef`.  
These conditional macros need to be closed with the directive `#endif`.

- `#if` Directive: Basic conditionals paired with `#endif`.
- `#else` Directive: Including some text if the condition fails.
- `#elif` Directive: Testing several alternative possibilities.

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
#### **`#ifdef`:** Check if a variable has been defined using two directives  
- `#ifdef VAR`  
- `#if defined VAR`  

---
#### **`#ifndef`:** Check if a variable has not been defined  
- `#ifndef VAR` 
- `#if !defined`  

---
## Macros With Arguments
**Macros can be more flexible when they accept arguments.**  
Arguments are fragments of code that you supply each time the macro is used.  
These fragments are included in the expansion of the macro according to the directions in the macro definition.  

A **macro that accepts arguments is called a *function-like* macro** because the syntax for using it looks like a function call.

- `#define` directive with a list of argument names in parentheses after the macro name
- **open-parenthesis must follow the macro name immediately (no space in between)**  

For example, here is a macro that computes the minimum of two numeric values, as it is defined in many C programs:   
`#define MIN(X, Y)  ((X) < (Y) ? (X) : (Y))`  

- Example Usage: `MIN(2,3)` expands to `2`
- Example Usage: `MIN(cs + 107, *p)` expands to `((cs + 107) < (*p) ? (cs + 107) : (*p))`  

---
### :red_circle: Macros With Arguments: Unintended Consequences :red_circle:

We can have **unintended side effects using macros for function-like expressions**.  
For example, if we defined a MAX function as follows:  

**<details><summary>:red_circle: Buggy Macro Example: Define</summary>**
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
If caution is taken, macros with arguments can be combined to make useful programming options.  

---
### Exercise: Macros With Arguments
**Build a program that depends on physical space dimensions: 2D or 3D**

- (a) Write a function to take additional arguments without having to make a new function
- (b) Have the function change via compile-time defined variables on the command line

:large_orange_diamond: [Deepnote: 3D Function Arguments](https://deepnote.com/project/fdeed75f-9b4a-428c-8bb7-3766103008ee)  

---
## Some Useful System Macros  
- `__FILE__` The name of the current file, as a string literal  
- `__LINE__` Current line of the source file, as a numeric literal  
- `__DATE__` Current system date, as a string  
- `__TIME__` Current system time, as a string  
- `__cplusplus` Undefined for C code compiled by a C compiler; `199711L` C code is compiled by a C++ compiler (98 C++ standard)  
- `__func__` Current function name of the source file, as a string (part of C99)  

:large_orange_diamond: [Deepnote: System Macros](https://deepnote.com/project/fdeed75f-9b4a-428c-8bb7-3766103008ee)

---
## C Preprocessor Exercises
:large_blue_diamond: [Deepnote: Fix Max Define Bug](https://deepnote.com/project/fdeed75f-9b4a-428c-8bb7-3766103008ee)  
:large_blue_diamond: Build a program that uses `float` when the macro `SINGLE_PRECISION` is defined, otherwise uses `double` as the floating pointing representation by defining a macro.  

---
[**Next**: C Data Types]({filename}C-3-CDataTypes.md)
