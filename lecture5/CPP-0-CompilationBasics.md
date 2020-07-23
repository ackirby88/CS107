
---
**Key:** 
:large_orange_diamond: - **Code Example** 
:large_blue_diamond: - **Code Exercise** 
:red_circle: - **Code Warning**  
[Previous: C++ Track Overview](https://github.com/ackirby88/CS107/blob/master/cpp-overview.md)

---
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
[Next: Source & Header Files](https://github.com/ackirby88/CS107/blob/master/lecture5/CPP-1-SourceHeaderFiles.md)
