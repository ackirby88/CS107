
---
**Key:** 
:large_orange_diamond: - **Code Example** 
:large_blue_diamond: - **Code Exercise** 
:red_circle: - **Code Warning**  
[**Previous**: Memory, Pointers, References](https://github.com/ackirby88/CS107/blob/master/C-Basics/C-5-Memory.md)  
[**Next**: C++ Classes & Objects](https://github.com/ackirby88/CS107/blob/master/C++/CPP-0-ClassesObjects.md)

---
# Function Pointers
A function pointer is a variable that stores the *address of a function* which can be used within in a program, including as a function argument.

## Syntax

## Functions as Arguments to Other Functions

## Callback Functions

## Function Pointers *in the wild*
C has a built-in sort function:
```C
void qsort (void* base, size_t num, size_t size,  
            int (*comparator)(const void*,const void*));
```
**Parameters**
- [x] **base** − pointer to the first element of the array to be sorted
- [x] **num**  − number of elements in the array pointed by base
- [x] **size** − size in bytes of each element in the array
- [x] **comparator** − function that compares two elements

```C
int comparator(const void* p1, const void* p2);
Return value meaning
<0 The element pointed by p1 goes before the element pointed by p2
 0 The element pointed by p1 is equivalent to the element pointed by p2
>0 The element pointed by p1 goes after the element pointed by p2
```

## Building a *Class* in C - *Sort Of*
Structs allow various data members of different types to be stored. However, structs don't actually have **methods**. But we can trick it!  
We can store function pointers in structs which we can use as a method.  
```C
typedef double (*custom_print_func_t)(int in_var);

typedef struct {
    int exp;
    custom_print_func_t my_print;
} func_t;
```
:large_orange_diamond: [Function Pointers in Structs!](https://bit.ly/2WQlwM5)  

---
[**Next**: C++ Classes & Objects](https://github.com/ackirby88/CS107/blob/master/C++/CPP-0-ClassesObjects.md)
