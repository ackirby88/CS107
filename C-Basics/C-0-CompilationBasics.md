
---
**Key:** 
:large_orange_diamond: - **Code Example** 
:large_blue_diamond: - **Code Exercise** 
:red_circle: - **Code Warning**  
[**Previous**: C++ Track Overview](https://github.com/ackirby88/CS107/blob/master/cpp-overview.md)  
[**Next**: Source & Header Files](https://github.com/ackirby88/CS107/blob/master/C-Basics/C-1-SourceHeaderFiles.md)

---
# Compilation Basics
(*We will have more on this topic later in the semester.*)  

Within this track, we will need to compile our codes.  
C and C++ are compiled programming languages contrasting Python which is an interpreted language.  
Compiled languages are usually *much faster* than interpreted languages.

- **Compiled** languages pass the source code to a compiler, which is translated directly to machine code.  
- **Interpreted** languages pass the source code to a separate program called an *interpreter*, which reads each line of code and then executes it on the processor. 

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

## Compiling on the command line:
**<details><summary>:large_orange_diamond: Compiling with gcc</summary>**
<p>
  
```C
gcc -o hello hello.c
```
</p>
</details>

Here, `gcc` is the GNU C compiler, `-o hello` tells the compiler to *output* a program named `hello`, and we provide the **hello.c** source file as the input.  

We can also compile the single file using **make**.
**<details><summary>:large_orange_diamond: Compiling with make (simple version)</summary>**
<p>
  
```C
make hello
```
</p>
</details>


## Executing on the command line:
**<details><summary>:large_orange_diamond: hello Output (simple version)</summary>**
<p>
  
```C
./hello
>>> Hello, World!
```
</p>
</details>

:large_orange_diamond: Sandbox Example: [Hello World!](https://bit.ly/2Oq5iV8)  
:large_orange_diamond: Guided Example: [Hello World Lab!](https://lab.cs50.io/ackirby88/CS107/master/labs/helloworld/)
([Github markdown](https://github.com/ackirby88/CS107/blob/master/labs/helloworld/README.md))

---
[**Next**: Source & Header Files](https://github.com/ackirby88/CS107/blob/master/C-Basics/C-1-SourceHeaderFiles.md)
