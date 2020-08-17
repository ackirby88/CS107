
---
**Key:** 
:large_orange_diamond: - **Code Example** 
:large_blue_diamond: - **Code Exercise** 
:red_circle: - **Code Warning**  
[**Previous**: C++ Polymorphism](https://github.com/ackirby88/CS107/blob/master/C++/CPP-3-Polymorphism.md)  

---
# Templating
Templates are the foundation of generic programming, which involves writing code in a way that is independent of any particular type.

A **template** is a blueprint for creating a generic class or a function.

## Function Template
The general form of a template function definition is as follows:
```C++
template <class T> ret_type func_name(parameter_list) {
   // body of function
} 
```
```C++
template <typename T> ret_type func_name(parameter_list) {
   // body of function
} 
```

## Class Template
```C++
template <class type> class class-name {
   // body of class
}
```
---
### Function Template Example
**<details><summary>:large_orange_diamond: Function Template</summary>**
<p>
   
```C++
// function template
#include <iostream>
using namespace std;

template <class T>
T getMax(T a, T b) {
  T result;
  result = (a > b) ? a : b;
  return (result);
}
```
</p>
</details>

**<details><summary>:large_orange_diamond: Function Template Main</summary>**
<p>

```C++
int main () {
  int i = 5, j = 6, k;
  long l = 10, m = 5, n;
  
  k = getMax<int>(i,j);
  n = getMax<long>(l,m);
  
  cout << "Int Max: " << k << endl;
  cout << "Long Max: " << n << endl;
  return 0;
}
```
</p>
</details>


**<details><summary>:large_orange_diamond: Function Template Output</summary>**
<p>
   
```C++
Int Max: 6
Long Max: 10
```
</p>
</details>

---
# Namespaces
