
---
**Key:** 
:large_orange_diamond: - **Code Example** 
:large_blue_diamond: - **Code Exercise** 
:red_circle: - **Code Warning**  
[**Previous**: Operators, Loops, Functions](https://github.com/ackirby88/CS107/blob/master/C-Basics/C-4-OpsLoopsFunctions.md)  
[**Next**: Function Pointers](https://github.com/ackirby88/CS107/blob/master/C-Basics/C-6-FunctionPointers.md)

---
# Arrays, Memory, Pointers, References
We touched a little bit on arrays in the data structures section, but, let's look at statically and dynamically allocated arrays in detail.  

## Arrays
Recall, an array is a variable which stores multiple values of the same type contiguously in memory.
```C
int data[12];
```
<p align="center">
  <img src="array.png">
</p>

#### Array Declaration
```C
dataType arrayName[arraySize];
```
Note that `arraySize` must be a fixed constant known at **compile time**.  
:large_orange_diamond: [Array Memory Demo](https://bit.ly/2CFIYEY): We can check to see if the memory is actually contiguous.
```C
#include <stdio.h>

int main(void){
    int ndata = 12;
    int data[ndata];

    for (int i = 0; i < ndata; ++i) {
        printf("data[%2d] address %p\n",i,&data[i]);
    }
    return 0;
}
```
<details><summary><b>Result</b></summary>
<p>

```
data[ 0] address 0x7ffc29e1fbe0
data[ 1] address 0x7ffc29e1fbe4
data[ 2] address 0x7ffc29e1fbe8
data[ 3] address 0x7ffc29e1fbec
data[ 4] address 0x7ffc29e1fbf0
data[ 5] address 0x7ffc29e1fbf4
data[ 6] address 0x7ffc29e1fbf8
data[ 7] address 0x7ffc29e1fbfc
data[ 8] address 0x7ffc29e1fc00
data[ 9] address 0x7ffc29e1fc04
data[10] address 0x7ffc29e1fc08
data[11] address 0x7ffc29e1fc0c
```  
</p>
</details>

#### Array Initialization
We can initialize arrays during the declaration:
```C
int arr1[4] = {4, 234, 22, -1};
int arr2[]  = {45, 107, 207, 4, 0};
```

#### Array Access
We can simply access arrays by using `[]`. For example, 
```C
int b = data[2];
```
:red_circle: **Be careful when accessing data elements!** The compiler won't stop you from accessing elements out-of-bounds. We can accidently access elements beyond our allocated memory.
```C
int data[4] = {0, 0, 0, 0};

printf("data[4] = %d\n",data[12]); // index 4 is out of bounds
>>> data[4] = -585229896
```

---
[**Next**: Function Pointers](https://github.com/ackirby88/CS107/blob/master/C-Basics/C-6-FunctionPointers.md)
