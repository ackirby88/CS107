
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
**Namespaces** allow grouping of entities like classes, objects, and functions under a name.  
This way the global scope can be divided in "sub-scopes", each one with its own name.

## Namespace Format
```C++
namespace identifier {
  //entities
}
```

---
### Scope Operator `::`
Recall the scope operator `::` which allows us to access entities from namespaces or specifies class functions when we are outside of the namespace scope:  
```C++
myNameSpace::a 
myNameSpace::b
```

## Namespace Examples
**<details><summary>:large_orange_diamond: Namespace Example</summary>**
<p>
   
```C++
// namespaces
#include <iostream>
using namespace std;

namespace first {
  int var = 5;
}

namespace second {
  double var = 3.1416;
}

int main () {
  cout << first::var << endl;
  cout << second::var << endl;
  return 0;
}
```
</p>
</details>

---
### `using` Keyword
The keyword `using` is used to introduce a name from a namespace into the current declarative region.

**<details><summary>:large_orange_diamond: `using` Example 1</summary>**
<p>

```C++
#include <iostream>
using namespace std;

namespace first {
  int x = 5;
  int y = 10;
}

namespace second {
  double x = 3.1416;
  double y = 2.7183;
}

int main(){
  using first::x;
  using second::y;
  
  cout << x << endl;
  cout << y << endl;
  
  cout << first::y << endl;
  cout << second::x << endl;
  return 0;
}
```
</p>
</details>


**<details><summary>:large_orange_diamond: `using` Example 2</summary>**
<p>

```C++
#include <iostream>
using namespace std;

namespace first {
  int x = 5;
  int y = 10;
}

namespace second {
  double x = 3.1416;
  double y = 2.7183;
}

int main(){
  using namespace first;
  
  cout << x << endl;
  cout << y << endl;
  
  cout << second::x << endl;
  cout << second::y << endl;
  return 0;
}
```
</p>
</details>

# C++ Standard Template Library (STL)
The C++ STL is a powerful set of C++ template classes to provide general-purpose classes and functions with templates that implement many popular and commonly used algorithms and data structures like vectors, lists, queues, and stacks.

**<details><summary>:large_orange_diamond: STL Vector Example</summary>**
<p>

```C++
#include <iostream>
#include <vector>
using namespace std;
 
int main(){
   // create a vector to store int
   vector<int> vec; 
   int i;

   // display the original size of vec
   cout << "vector size = " << vec.size() << endl;

   // push 5 values into the vector
   for (i = 0; i < 5; i++) {
      vec.push_back(i);
   }

   // display extended size of vec
   cout << "extended vector size = " << vec.size() << endl;

   // access 5 values from the vector
   for (i = 0; i < 5; i++) {
      cout << "value of vec [" << i << "] = " << vec[i] << endl;
   }

   // use iterator to access the values
   vector<int>::iterator v = vec.begin();
   while (v != vec.end()) {
      cout << "value of v = " << *v << endl;
      v++;
   }

   return 0;
}
```
</p>
</details>

**<details><summary>:large_orange_diamond: STL Vector Example Output</summary>**
<p>
   
```C++
vector size = 0
extended vector size = 5
value of vec [0] = 0
value of vec [1] = 1
value of vec [2] = 2
value of vec [3] = 3
value of vec [4] = 4
value of v = 0
value of v = 1
value of v = 2
value of v = 3
value of v = 4
```
</p>
</details>

Learn about the Standard Template Library: [C++ STL Tutorial](https://www.geeksforgeeks.org/cpp-stl-tutorial/)
