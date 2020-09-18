
---
**Key:** 
:large_orange_diamond: - **Code Example** 
:large_blue_diamond: - **Code Exercise** 
:red_circle: - **Code Warning**  
[**Previous**: Compilation Basics](https://github.com/ackirby88/CS107/blob/master/C-Basics/C-0-CompilationBasics.md)  
[**Next**: C Preprocessor](https://github.com/ackirby88/CS107/blob/master/C-Basics/C-2-Prepocessor.md)

---
## Source Files
The majority of our code will be written in source files.  

**<details><summary>C++ Source File Extensions</summary>**
<p>

- `.cpp`
- `.cc`
- `.C`
- `.cxx`
</p>
</details>

**<details><summary>C Source File Extensions</summary>**

- `.c`
</p>
</details>

---
## Header Files
Header files usually contain function declarations but can sometimes also contain functions implementations, e.g. inlined functions.  
**Header files can be used used to share these declarations and macro expansions across multiple files.**

**<details><summary>C++ Header File Extensions</summary>**
<p>

- `.hpp`
- `.h`
</p>
</details>

**<details><summary>C Hource File Extensions</summary>**

- `.h`
</p>
</details>

---
### Example: `print_hello_world()`
**<details><summary>:large_orange_diamond: hello_1.h: header file</summary>**
<p>
  
```C
void print_hello_world(void);
```
</p>
</details>

**<details><summary> :large_orange_diamond: hello_1.c: source file</summary>**
<p>
  
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

- If `hello_1.h` is not included in `hello_1.c`, `print_hello_world()` would not be known by the `main` function
- **Programs compiled with gcc are parsed top-down**

Luckily for us, **the C Preprocessor replaces the `#include "hello_1.h"` line** with all of the code found in **hello_1.h**.  

---
:large_orange_diamond: [Hello World Header Files!](https://deepnote.com/project/fdeed75f-9b4a-428c-8bb7-3766103008ee#%2FC-Basics%2FHelloWorldNameMangle%2Fhello_1.c)  
This example also introduces *name mangling* which we will learn more later in the semester.

---
[**Next**: C Preprocessor](https://github.com/ackirby88/CS107/blob/master/C-Basics/C-2-Prepocessor.md)
