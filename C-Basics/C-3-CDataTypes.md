
---
**Key:** 
:large_orange_diamond: - **Code Example** 
:large_blue_diamond: - **Code Exercise** 
:red_circle: - **Code Warning**  
[Previous: C Preprocessor](https://github.com/ackirby88/CS107/blob/master/C-Basics/C-2-Prepocessor.md)

---
# C Data Types

## Primitive Types
- `int`: stores an integer
- `char`: stores a single character and requires a single byte of memory
- `float`: stores floating point numbers with **single** precision
- `double`: stores floating point numbers with **double** precision
- `void`: the absence of type

### Integer Literals
Within C/C++, there are four literal types: `decima`, `binary`, `octal`, and `hexadecimal`.  
```C
int b = 0b101;     // binary
int d = 42;        // decimal
int o = 023;       // octal
int h = 0xC05FEFE; // hexadecimal
```
:red_circle: Be careful with leading zeros! Leading zeros indicate octal numbers. :red_circle:  
:large_orange_diamond: [Literals Sandbox](https://bit.ly/2ZJ0Ffg)

## Derived Types
- `Function`:  a function that returns a value of a specified type
- `Pointer`: a value that represents the address of an object of a stated type
- `Array`: a data structure that can store a fixed-size sequential collection of elements of the same type
- `Structure`: a data structure that can store data items of different types
- `Union`: a data structure that can store different data types in the same memory location

### 1. Function Type
A function type describes a function that returns a value of a specified type.  
If the function returns no value, it should be declared as "function returning void " as follows:  
```C
void function1();
```
In the following example, the data type for the function is "function returning int ":
```C
int uppercase(int lc){
  int uc = lc + 0X20;
  return uc;
}
```

### 2. Pointer Type
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

int *prt = (int *) malloc(10*sizeof(int));
```
The construction `void *` designates a generic *pointer to void* type.  
The `void *` construction can be used to point to an object of any type, and it is most useful when a pointer is needed to point to the address of objects with different or unknown types (such as in a function prototype). A pointer to `void` can also be converted to or from a pointer of any other type, and has the same representation and alignment requirements as a pointer to a character type.  
```C
int MPI_Send(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm);
```

### 3. Array Type
An array is a data structure that can store a fixed-size sequential collection of elements of the same type.
Arrays cannot be of void or function type, since the void type cannot be completed and function types are not object types requiring storage.
```C
int nvec = 107;

/* allocate memory */
double *vec = (double *) malloc(nvec*sizeof(double));

vec[0] = 1.1234534631246;
for (int i = 1 ; i < nvec; ++i) {
  vec[i] = 2.0*vec[i-1];
}

/* deallocate memory */
free(vec); vec = NULL;
```

Each of the elements has the size of a double object, 8 bytes (64 bits). The size of the array is determined by its initialization; in the previous example, the array has `nvec = 107` explicit elements.

An array is allocated contiguously in memory, and cannot be empty (that is, have no members).  
An array can have only one dimension. To create an array of "two dimensions," declare an array of arrays, and so on.
```C
/* allocate first dimension */
int **two_dim = (int **) malloc(10 * sizeof(int *));

/* allocate second dimension */
for (int j = 0; j < 10; ++j) {
  two_dim[j] = (int *) malloc(25*sizeof(int));
}

/* fill array of arrays: i-index is contiguous in memory */
for (int j = 0; j < 10; ++j) {
  for (int i = 0; i < 25; ++i) {
    two_dim[j][i] = 2*j + i;
  }
}

/* deallocate memory */
for (int j = 0; j < 10; ++j) {
  free(two_dim[j]); two_dim[j] = NULL;
}
free(two_dim); two_dim = NULL;
```

### 4. Structure Type
A structure type is a sequentially allocated nonempty set of objects, called members, allowing grouping of heterogeneous data. 
Unlike arrays, the elements of a structure need not be of the same data type. Also, elements of a structure are accessed by name, not by subscript. 
```C
struct [structure tag] {
  member definition;
  member definition;
  ...
  member definition;
} [one or more structure variables];  
```
**Example:**
```C
struct student {
  char name[30];
  int age;
};

struct student andrew, ed, mary;

// access member
andrew.age = 21;
```

:large_orange_diamond: Sandbox Example: [Structs - Pass-by-Value/Address/Reference](https://bit.ly/3fMX05R)

### 5. Union Type
A **union** is a special data type available in C that allows to store different data types in the same memory location. You can define a union with many members, but only one member can contain a value at any given time. Unions provide an efficient way of using the same memory location for multiple-purpose.
```C
union [union tag] {
   member definition;
   member definition;
   ...
   member definition;
} [one or more union variables];  
```
**Example:**
```C
union Data {
   int i;
   float f;
   char str[20];
} data;
```

---
## User-Defined Types

### Modifiers
- `signed` (int/char): target type will have signed representation (this is the default if omitted)
- `unsigned` (int/char): target type will have unsigned representation
- `short`: target type will be optimized for space and will have width of at least 16 bits
- `long`: target type will have width of at least 32 bits
- `long long`: target type will have width of at least 64 bits  

These change the range and size that the variable can represent, e.g. `unsigned char` values range at least [0,255].
```C
long long int a;   // 8 bytes
unsigned short b;  // 2 bytes, [0,65535]
```
---
### Qualifiers
- `const`: object cannot be modified; attempt to do so directly is a compile-time error
- `volatile`: tells compiler value may change at any time code not seen by the compiler
- `restrict`: **(C only)** tells compiler that assigned pointer is the only way to access the object pointed by it
- `static`: value remains in memory for duration of program life
- `extern`: t provides the compiler with sufficient information to access a variable declared in another file

#### 1. `const`
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

- **Constant pointer to constant**: `const int *const`
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

---
**Summary**  
`int const*` is pointer to constant integer  
`int *const` is a constant pointer to integer  
`const int* const` is a constant pointer to constant integer

---

#### 2. `volatile`
The `volatile` qualifier tells the compiler that the **value of the variable may change at any time, without any action being taken by the code** the compiler finds nearby. Volatile accesses cannot be optimized out or reordered with another visible side effect that is sequenced-before or sequenced-after the volatile access. 
This qualifier is used primarily in embedded programming of devices, e.g.  mobile phones, washing machines, and digital cameras.

#### 3. `restrict` (C only)
In the C programming language, `restrict` is a keyword that can be used in pointer declarations. By adding this type qualifier, a programmer hints to the compiler that for the lifetime of the pointer, only the pointer itself or a value directly derived from it (such as pointer + 1) will be used to access the object to which it points.

`restrict` limits the effects of pointer aliasing, aiding optimizations. If the declaration of intent is not followed and the object is accessed by an independent pointer, this will result in undefined behavior.

If the compiler knows that there is only one pointer to a memory block, it can produce better optimized code. For instance:
```C
void updatePtrs(size_t *restrict ptrA, size_t *restrict ptrB, size_t *restrict val){
  *ptrA += *val;
  *ptrB += *val;
}
```

#### 4. `static`
Static variables have a property of preserving their value even after they are out of their scope! Hence, static variables preserve their previous value in their previous scope and are not initialized again in the new scope.
```C
#include<stdio.h>
int fun(){
  static int count = 0;
  count++;

  return count;
}

int main(void){
  printf("Count = %d", fun());
  printf("Count = %d", fun());
  return 0;
}
```
**Output:**
```
Count = 1
Count = 2
```

#### 5. `extern`
An object declaration outside of a function is called an **external declaration**. If the file does not include the file 
provides the compiler with sufficient information to access a variable declared in another file. Later in the semester when we build libraries, we will see be utilized to prevent *name mangling* with `extern "C"{...}`.

---
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
:red_circle: But be careful with assigning pointers on a single line! The `*` needs to be placed on **each** variable. :red_circle:
```C
int *a_ptr, *b_ptr;
int* c_ptr, c; // c_ptr is a pointer to an integer address, c is actually an integer!
````
My personal preference is to place the `*` next to the variable rather than next to the type (but either is okay).

### C++ Initialization
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

---
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
[Next: Operators, Loops, Functions](https://github.com/ackirby88/CS107/blob/master/C-Basics/C-4-OpsLoopsFunctions.md)
