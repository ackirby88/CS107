
---
**Key:** 
:large_orange_diamond: - **Code Example** 
:large_blue_diamond: - **Code Exercise** 
:red_circle: - **Code Warning**  
[**Previous**: C++ Inheritence](https://github.com/ackirby88/CS107/blob/master/C++/CPP-2-Inheritence.md)  
[**Next**: C++ Templates and Namespaces](https://github.com/ackirby88/CS107/blob/master/C++/CPP-4-Templates.md)  

---
# Class Polymorphism
One of the key features of class inheritance is that a pointer to a derived class is type-compatible with a pointer to its base class.  
**Polymorphism** means that a call to a member function will cause a different function to be executed depending on the type of object that invokes the function.

**<details><summary>:large_orange_diamond: Pointer to Class: Base Class</summary>**
<p>
  
```C++
#include <iostream>
using namespace std;

class Polygon {
  protected:
    int width, height;
  public:
    void set_values(int a, int b){
      width = a;
      height = b;
    }
};
```
</p>
</details>

**<details><summary>:large_orange_diamond: Pointer to Class: Derived Classes</summary>**
<p>
  
```C++
class Rectangle: public Polygon {
  public:
    int area(){
      return width*height;
    }
};

class Triangle: public Polygon {
  public:
    int area(){
      return width*height/2;
    }
};
```
</p>
</details>

**<details><summary>:large_orange_diamond: Pointer to Class: Main</summary>**
<p>
  
```C++
int main () {
  Rectangle rect;
  Triangle trgl;
  
  Polygon *ppoly1 = &rect;
  Polygon *ppoly2 = &trgl;
  
  ppoly1->set_values(4,5);
  ppoly2->set_values(4,5);
  
  cout << "Rectangle area: " << rect.area() << endl;
  cout << "Triangle area: " << trgl.area() << endl;
  return 0;
}
```
</p>
</details>

**<details><summary>:large_orange_diamond: Pointer to Class: Output</summary>**
<p>
  
```C++
Rectangle area: 20
Traingle area: 10
```
</p>
</details>

---
## :red_circle: Non-Virtual Base Class Functions
Consider the following example (three code blocks):  
**<details><summary>:large_orange_diamond: Non-Virtual Function: Base Class</summary>**
<p>
  
```C++
#include <iostream>
using namespace std;

class Polygon {
  protected:
    int width, height;
  public:
    void set_values(int a, int b){
      width = a;
      height = b;
    }
    
    // base-class area function
    int area(){
      cout << "Parent class area: " << endl;
      return 0;
    }
};
```
</p>
</details>

**<details><summary>:large_orange_diamond: Non-Virtual Function: Derived Classes</summary>**
<p>
  
```C++
class Rectangle: public Polygon {
  public:
    int area(){
      cout << "Rectangle class area: " << endl;
      return width*height;
    }
};

class Triangle: public Polygon {
  public:
    int area(){
      cout << "Triangle class area: " << endl;
      return width*height/2;
    }
};
```
</p>
</details>

**<details><summary>:large_orange_diamond: Non-Virtual Function: Main</summary>**
<p>

```C++
int main () {
  Rectangle rect;
  Triangle trgl;
  
  Polygon *ppoly1 = &rect;
  Polygon *ppoly2 = &trgl;
  
  ppoly1->set_values(4,5);
  ppoly2->set_values(4,5);
  
  cout << rect.area() << endl;
  cout << trgl.area() << endl;
  return 0;
}
```
</p>
</details>

**<details><summary>:red_circle: Non-Virtual Function: Output</summary>**
<p>
 
```
Parent class area: 
Parent class area: 
```
</p>
</details>

:red_circle: Be careful though with assigning the same pointer to multiple derived classes! Without the keyword **virtual** we can get **static resolution** or **static linkage** meaning the function call is fixed before the program is executed.

---
### What's the fix?
**<details><summary>:large_orange_diamond: Virtual Functions</summary>**
<p>
 
To fix this behavior, we introduce the keyword **virtual**:
```C++
class Polygon {
  protected:
    int width, height;
  public:
    void set_values(int a, int b){
      width = a;
      height = b;
    }
    
    // virtual base-class area function
    virtual int area(){
      cout << "Parent class area: " << endl;
      return 0;
    }
};
```
</p>
</details>

**<details><summary>:large_orange_diamond: Fix: Virtual Output</summary>**
<p>
 
```
Rectangle class area: 
Triangle class area: 
```
</p>
</details>

Now, the compiler looks at the contents of the pointer rather than its type. Hence the expected `area()` functions being called from each of the derived-classes. 

---
As you can see, each of the child classes has a separate implementation for the function area(). This is how **polymorphism** is generally used. You have different classes with a function of the same name, and even the same parameters, but with different implementations.

## Virtual Functions
A **virtual** function is a function in a base class that is declared using the keyword `virtual`.  
Defining in a base class a virtual function, with another version in a derived class, signals to the compiler not to perform **static linkage** for this function.
This sort of operation is referred to as **dynamic linkage** or **late binding**.

### Pure Virtual Functions
It is possible to include a virtual function in a base class such that it must be redefined in a derived class, but that has no meaningful definition in the context of the base class.

Suppose we wanted `area()` to be implemented by every derived class and also prevent the base class from assigning a value of 0 as we saw above:
```C++
class Shape {
   protected:
      int width, height;
   public:
      Shape(int a = 0, int b = 0){
         width = a;
         height = b;
      }
      
      // pure virtual function
      virtual int area() = 0;
};
```
In `virtual int area() = 0;`, the `= 0` signals to the compiler that the function has no body and **must** be redefined by any derived class. 
This is known as a **pure virtual function**.

## Abstract Base Classes
Our `Polygon` or `Shape` classes are really *abstractions*, and should only serve as base classes which cannot instantiate objects.  
:heavy_exclamation_mark: Classes that contain at least one pure virtual function are known as **abstract base classes**.

When we include ` virtual int area() = 0;`, we have converted the `Shape` class into an abstract base class. Thus:
```C++
Shape myShapeObj;      // ERROR: Shape is an abstract base class
Shape *myShapePointer; // VALID: Pointers to abstract base classes are advantageous
```
---
[**Next**: C++ Templates and Namespaces](https://github.com/ackirby88/CS107/blob/master/C++/CPP-4-Templates.md)  
