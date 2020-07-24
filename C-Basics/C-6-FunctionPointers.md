
---
**Key:** 
:large_orange_diamond: - **Code Example** 
:large_blue_diamond: - **Code Exercise** 
:red_circle: - **Code Warning**  
[**Previous**: Memory, Pointers, References](https://github.com/ackirby88/CS107/blob/master/C-Basics/C-5-Memory.md)  
[**Next**: C++ Classes & Objects](https://github.com/ackirby88/CS107/blob/master/C++/CPP-0-ClassesObjects.md)

---
# Function Pointers

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
