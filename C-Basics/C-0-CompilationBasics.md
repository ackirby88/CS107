Title: C/C++ Compilation Basics
Category: lectures
Date: 2020-9-22
Slug: lecture5-C++/C0
Author: Andrew Kirby
Tags: C, C++, compiling

---
**Key:** 
:large_orange_diamond: - **Code Example** 
:large_blue_diamond: - **Code Exercise** 
:red_circle: - **Code Warning**  
[**Previous**: C++ Track Overview]({filename}cpp-overview.md)  
[**Next**: Source & Header Files]({filename}C-1-SourceHeaderFiles.md)

---
# Compilation Basics
(*We will have more on this topic later in the semester.*)  

Within this track, we will need to compile our codes.  
C and C++ are compiled programming languages contrasting Python which is an interpreted language.  
Compiled languages are usually *much faster* than interpreted languages.

- **Compiled** languages pass the source code to a compiler, which is translated directly to machine code.  
- **Interpreted** languages pass the source code to a separate program called an *interpreter*, which reads each line of code and then executes it on the processor. 

---
## Compiling `Hello, World!`
Let's take a look at the canonical **Hello, World!** to learn the basics of compiling programs from source files.  

**<details><summary>:large_orange_diamond: hello.c</summary>**
<p>
  
```C
#include <stdio.h>

int main(void) {
  printf("Hello, World!\n");
  return 0;
}
```
</p>
</details>

---
#### Compiling on the command line:
**<details><summary>:large_orange_diamond: Compiling with gcc</summary>**
<p>
  
```C
gcc -o hello hello.c
```
</p>
</details>

- `gcc`: the GNU C compiler
- `-o hello`: *output* a program named `hello`
- `hello.c`: source file to compile

---
We can also compile the single file using **make**.
**<details><summary>:large_orange_diamond: Compiling with make (simple version)</summary>**
<p>
  
```C
make hello
```
</p>
</details>

---
#### Executing on the command line:
**<details><summary>:large_orange_diamond: hello Output</summary>**
<p>
  
```C
./hello
>>> Hello, World!
```
</p>
</details>

---
:large_orange_diamond: Sandbox Example: [Hello World!](https://deepnote.com/project/fdeed75f-9b4a-428c-8bb7-3766103008ee#%2FC-Basics%2FHelloWorld%2FHelloWorld.c)   

---
[**Next**: Source & Header Files]({filename}C-1-SourceHeaderFiles.md)
