# C Data Types

## Primitive Types
There are four basic data types: `int`, `char`, `float`, and `double`.
- `int`: stores an integer
- `char`: stores a single character and requires a single byte of memory
- `float`: stores floating point numbers with **single** precision
- `double`: stores floating point numbers with **double** precision

## Modifiers: `signed`, `unsigned`, `short`, and `long`
These change the range and size that the variable can represent, e.g. `unsigned char` values range at least [0,255].
```C
long long int a;   // 8 bytes
unsigned short b;  // 2 bytes, [0,65535]
```

## Qualifiers: `const`, `volatile`, `restrict`
### 1. `const`
The qualifier `const` can be applied to the declaration of any variable to specify that its value will not be changed.
```C
const int a = 7;
int const b = 8;
```

- **Pointer to constant**: `const int*`  
Pointer to constant can be declared in following two ways.
```C
const int *ptr;
int const *ptr; 
```
We can change the pointer to point to any other integer variable, but cannot change the value of the object (entity) pointed using pointer ptr. 
The pointer is stored in the read-write area (stack in the present case). 
The object pointed may be in the read-only or read-write area. Let's look at some examples.  
**Example:**
```C
#include <stdio.h> 
int main(void){
  int i = 10;
  int j = 20;
  /* ptr is pointer to constant */
  const int *ptr = &i;	 

  printf("ptr: %d\n", *ptr);
  /* error: object pointed cannot be modified using the pointer ptr */
  *ptr = 100;

  ptr = &j;  /* valid */
  printf("ptr: %d\n", *ptr);

  return 0;
}
```
**Output:**
```
 error: assignment of read-only location ‘*ptr’
```

Following is another example where variable `i` itself is constant.  
**Example:**
```C
#include <stdio.h> 

int main(void){
  /* i is stored in read only area */
  int const i = 10;
  int j = 20;

  /* Pointer to integer constant:
   *  i is of type "const int"
   * &i is of type "const int *"
   *  p is of type "const int" 
   */
  int const *ptr = &i;
  printf("ptr: %d\n", *ptr);

  /* error */
  *ptr = 100;

  /* valid. We call it up qualification.
   * In C/C++, the type of "int *" is allowed to up qualify to the type "const int *".
   * The type of &j is "int *" and is implicitly up qualified by the compiler to "const int *".
   */
  ptr = &j;
  printf("ptr: %d\n", *ptr);
  
  return 0;
}
```
**Output:**
```
error: assignment of read-only location ‘*ptr’
```

- **Constant pointer to variable**: `int *const`  
```C
int *const ptr; 
```
The declaration is a constant pointer to an integer variable, means we can change the value of object pointed by pointer, but cannot change the pointer to point another variable.  
**Example:**
```C
#include <stdio.h> 

int main(void){
  int i = 10;
  int j = 20;

  /* constant pointer to integer */
  int *const ptr = &i;

  printf("ptr: %d\n", *ptr);

  *ptr = 100; /* valid */
  printf("ptr: %d\n", *ptr); 

  ptr = &j; /* error */
  return 0;
}
```
**Output:**
```
error: assignment of read-only variable ‘ptr’
```

- **Constant pointer to constant**: `int *const`
```C
const int *const ptr; 
```
The declaration is a constant pointer to a constant variable which means we cannot change value pointed by the pointer as well as we cannot point the pointer to other variables.  
**Example:**
```C
#include <stdio.h>

int main(void){ 
  int i = 10;
  int j = 20;

  /* constant pointer to constant integer */
  const int *const ptr = &i;
  printf("ptr: %d\n", *ptr);
  
   ptr = &j;  /* error */
  *ptr = 100; /* error */

  return 0;
}
```
**Output:**
```
error: assignment of read-only variable ‘ptr’
error: assignment of read-only location ‘*ptr’
```

### 2. `volatile`

### 3. `restrict` (only for pointers)

## Declaration and Assignment
To use variables in C/C++, they first must be declared.  
```C
int a;
double var;
double *p = NULL;
```
We can also declare variables in a single line:
```C
int a, b, c;
```
:red_circle: But be careful with assigning pointers on a single line! The `*` needs to be placed on **each** variable.
```C
int *a_ptr, *b_ptr;
int* c_ptr, c; // c_ptr is a pointer to an integer address, c is actually an integer!
````
My personal preference is to place the `*` next to the variable rather than next to the type (but either is okay).

### C++ Assignment
In C++, we can initialize variables using a *constructor initialization* by enclosing the initial value between parenntheses `()`.
```C++
#include <iostream>
using namespace std;

int main ()
{
  int a=5;     // initial value = 5
  int b(2);    // initial value = 2
  int result;  // initial value undetermined

  a = a + 3;
  result = a - b;
  cout << result;
  
  return 0;
}
```

## Scope
The scope of local variables is limited to the block enclosed in braces (`{}`) where they are declared. 
```C
/* Variable scope and assignment examples */
int main(void){
  int a;
  {
    int b = 7; // We can use 'b' only within these braces
    a = b;
  }
  // b not visible here
  
  printf("Value of a: %d\n",a);
  
  for (int i = 0; i < 107; ++i) {
    // i only visible within this loop's braces
    a += i;
  }
}
```

### Size of Data Types
The amount of bytes used to store a variable may vary by machine. To check, you can use the `sizeof` unary operator.
This will return the **number of bytes**.
```C
sizeof(var)
sizeof var
```

---
## Derived Types
There are five derived types: `Function`, `Pointer`, `Array`, `Structure`, and `Union`.

#### Function Type
A function type describes a function that returns a value of a specified type.  
If the function returns no value, it should be declared as "function returning void " as follows:  
```C
void function1 ();
```
In the following example, the data type for the function is "function returning int ":
```C
int uppercase(int lc){
  int uc = lc + 0X20;
  return uc;
}
```

#### Pointer Type
A pointer type describes a value that represents the *address* of an object of a stated type.  
A pointer is stored as an integral value that references the address of the target object.  
Pointer types are derived from other types, called the referenced type of the pointer.  
For example:
```C
int *p;          /*  p is a pointer to an int type */
double *q();     /*  q is a function returning a pointer to an object of type double */
int (*r)[5];     /*  r is a pointer to an array of five elements */
                 /*  (r holds the address to the first element of the array) */
const char s[6]; /*  s is a const-qualified array of 6 elements */
```
The construction `void *` designates a generic *pointer to void* type.  
The `void *` construction can be used to point to an object of any type, and it is most useful when a pointer is needed to point to the address of objects with different or unknown types (such as in a function prototype). A pointer to `void` can also be converted to or from a pointer of any other type, and has the same representation and alignment requirements as a pointer to a character type.  
```C
int MPI_Send(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm);
```


#### 

### User-Defined Types

---
## Operators
### Unary Operators
- minus `-`, plus `+`
- logical negation `!`
- prefix increment `++` and decrement `--`
- address operator `&` and indirection `*`
- bitwise negation `~`
- cast operator
- `sizeof` operator

## Loops

## Functions

---
## Memory, Pointers, References
