
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
template <class type> class class_name {
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
### Class Template Example
**<details><summary>:large_orange_diamond: Class Template</summary>**
<p>
   
```C++
template <class T>
class mypair {
  private:
    T values[2];
  public:
    mypair(T first, T second){
      values[0] = first;
      values[1] = second;
    }
};
```
</p>
</details>

**<details><summary>:large_orange_diamond: Class Template Usage</summary>**
<p>
   
```C++
// int class
mypair<int> myobject(115, 36);

// double class 
mypair<double> myfloats (3.0, 2.18); 
```
</p>
</details>

**<details><summary>:large_orange_diamond: Class Template Example</summary>**
<p>
   
```C++
// class templates
#include <iostream>
using namespace std;

template <class T>
class mypair {
  private:
    T a, b;
  public:
    // contructor
    mypair(T first, T second){
      a = first;
      b = second;
    }
    
    // class method declaration
    T getMax();
};

// class method implementation
template <class T>
T mypair<T>::getMax(){
  T retval;
  retval = (a > b) ? a : b;
  return retval;
}

int main () {
  mypair<int> myobject(100, 75);
  cout << myobject.getMax() << endl;
  return 0;
}
```
</p>
</details>

---
# Namespaces
