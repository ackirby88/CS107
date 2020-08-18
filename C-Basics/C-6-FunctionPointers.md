
---
**Key:** 
:large_orange_diamond: - **Code Example** 
:large_blue_diamond: - **Code Exercise** 
:red_circle: - **Code Warning**  
[**Previous**: Arrays, Pointers, Memory, References](https://github.com/ackirby88/CS107/blob/master/C-Basics/C-5-Memory.md)  
[**Next**: C++ Classes & Objects](https://github.com/ackirby88/CS107/blob/master/C++/CPP-0-ClassesObjects.md)

---
# Function Pointers
A **function pointer** is a variable that stores the **address of a function** which can be used within in a program, including as a function argument.

## Syntax    
```C
return_type (*function_name) (argument list);
```

**<details><summary><b>:large_orange_diamond: Function Pointer Example </b></summary>**
<p>
    
A function named `foo` takes two integers as arguments and returns an integer.
```C
#include <stdio.h>

int my_add_function(int a, int b){
    return a+b;
}

int main(void){
    int (*foo)(int,int);   // optional argument names
    foo = my_add_function; // initialize the function pointer 
    
    /* optionally: we can use & */
    // foo = &my_add_function;
    
    int a = 5, b = 70;
    int sum = foo(a,b);
    printf("The sum of %d and %d equals %d.\n",a,b,sum);

    return 0;
}
```
</p>
</details>

:large_orange_diamond: [Function Pointer Demo](https://bit.ly/3jCxPFn)

---
### Reading Function Pointer Declarations
```C
void *(*bar_func)(int *);
```
To understand this function, start reading inside out: `(*bar_foo)` - pointer to the function.  
The leading `void *` is simply a pointer to a void type, and, lastly, the function takes in an integer pointer as an argument.

---
## Functions as Arguments to Other Functions
You can pass functions as arguments to other functions which can be executed within the function.  
For example, if you need a sorting function for your C/C++ program, there is a function called `qsort`. Let's take a look at how it works.

---
### Function Pointers *in the wild*
C has a built-in sort function:
```C
void qsort (void* base, size_t num, size_t size,  
            int (*comparator)(const void*,const void*));
```
**<details><summary><b>Sort Function Parameters</b></summary>**
<p>

- [x] **base** − pointer to the first element of the array to be sorted
- [x] **num**  − number of elements in the array pointed by base
- [x] **size** − size in bytes of each element in the array
- [x] **comparator** − function that compares two elements
</p>
</details>

**<details><summary><b>:large_orange_diamond: The `comparator` Function</b></summary>**
<p>
    
```C
int comparator(const void* p1, const void* p2);
Return value meaning
<0 The element pointed by p1 goes before the element pointed by p2
 0 The element pointed by p1 is equivalent to the element pointed by p2
>0 The element pointed by p1 goes after the element pointed by p2
```
</p>
</details>

:large_orange_diamond: [Sorting Structs Demo](https://bit.ly/30SRetk)

---
## Callback Functions
Another use of function pointers is in **callback** functions. 

We can request that a user set the function we want to call *abstractly*.  
Here we see an example where we pass the function pointer that is to be set by a *user*. Then we call the callback function after is set. 

**<details><summary><b>:large_orange_diamond: Callback Function Example</b></summary>**
<p>
    
```C
#include <stdio.h>

double custom_mult(double x,double y){
    return x*x + 2.0*x*y + y*y;
}

// callback prototype
typedef double (*multiply_func_t)(double,double);

void set_callback(multiply_func_t *func_ptr){
      *(void **)(func_ptr) = custom_mult;
}

int main(void){
    multiply_func_t callback_multiply;
    set_callback(&callback_multiply);
    
    double x = 2.6, y = 5.1;
    double result = callback_multiply(x,y);
    printf("The results from our callback Op(x=%f,y=%f) = x*x + 2.0*x*y + y*y = %f\n",x,y,result);
    
    return 0;
}
```
</p>
</details>

:large_orange_diamond: [Callback Functions Demo](https://bit.ly/3g0XlBP)  
:large_orange_diamond: [Callback Functions Shared Library Demo](https://bit.ly/2ZXsZuG)

---
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
