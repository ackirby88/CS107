
---
**Key:** 
:large_orange_diamond: - **Code Example** 
:large_blue_diamond: - **Code Exercise** 
:red_circle: - **Code Warning**  
[Previous: Compilation Basics](https://github.com/ackirby88/CS107/blob/master/C-Basics/C-0-CompilationBasics.md)

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
:large_orange_diamond: [FIXME Hello World with header files!](...)

---
[Next: C-Preprocessor](https://github.com/ackirby88/CS107/blob/master/C-Basics/C-2-Prepocessor.md)
