
---
**Key:** 
:large_orange_diamond: - **Code Example** 
:large_blue_diamond: - **Code Exercise** 
:red_circle: - **Code Warning**  
[**Previous**: C Basics - Function Pointers](https://github.com/ackirby88/CS107/blob/master/C-Basics/C-6-FunctionPointers.md)  
[**Next**: C++ Constructors](https://github.com/ackirby88/CS107/blob/master/C++/CPP-1-Constructors.md)

---
# C++ Function Defaults
Functions in C++ are allowed to have default arguments without providing one or more trailing arguments.  
Default arguments are used in place of the missing trailing arguments in a function call:  
```C++
void point(int x = 3, int y = 4);
 
point(1,2); // calls point(1,2)
point(1);   // calls point(1,4)
point();    // calls point(3,4)
```

**<details><summary>:large_orange_diamond: Arguments Defaults Example:</summary>**
<p>
  
```C++
double distance(double x, double y = 0.0){
  return sqrt((x-y)*(x-y));
}

int main(void){
  double x = 3.2;
  double y = 1.2;
  
  double d0 = distance(x);   // distance to origin
  double d1 = distance(x,y); // distance between x and y
  
  return 0;
}
```
</p>
</details>

**Note that default arguments must be trailing arguments in the list.**

# C++ Function Polymorphism
C++ allows mulitple functions with the same function name but with different arguments:
```C++
double average(double a, double b){
  return 0.5*(a + b);
}

double average(double a, double b, double c){
  return (a + b + c) / 3.0;
}
```
The functions declaration must differ in type or number of *input arguments*.

# C++ Classes
A **class** is in C++ is similar to a `struct` in that they can contain data members, but they can also contain functions as members, which we will call *methods*.

## Creating a C++ Class
To construct a class, we use the keyword `class` followed by the name of the class.  
The body of the class is contained between curly brackets `{}` and is terminated by a semicolon `;`.
```C++
class className {
  // data members
  // function members (i.e. methods)
};
```

**<details><summary>:large_orange_diamond: C++ Class Example:</summary>**
<p>

```C++
class Rectangle{
  public: 
    double length;
    double width;
    double height;
    
    double surfaceArea(){
      return 2.0*length*width + 2.0*length*height + 2.0*width*height;
    }
    
    double volume(){
      return length*width*height;
    }
};
```
Here, the **data members** are `length`, `width`, and `height`, and the **methods** are `surfaceArea` and `volume`.  
To use the data members and methods defined in the calss, we need to create objects.  
</p>
</details>

# C++ Objects 
An **object** is an instance of a **class**.  
To create an object from the example class `Rectangle`, we specify the class name, followed by the object name, e.g. `Rectangle rec0`.  

We can create multiple objects from our class as usual:  
```C++
int main(void){
  Rectangle rec0, rec1;
  return 0;
}
```
We can also create an array of objects using `new`:
```C++
int main(void){
  Rectangle my_rectangles = new Rectangle[5]; // creates 5 rectangle objects
  delete [] my_rectangles; // free the array
  return 0;
}
```
### `delete` vs `delete []`
To delete an *array of objects* created using `new`, we need to `delete []` to delete the array.  
If we had a single object, e.g. `Rectangle rec0;`, then we can use `delete rec0;`.  

## Accessing Data Members and Member Functions
We can access the data members and methods using the `.` operator (when the members are public):
```C++
Rectangle rect0;

rect0.length = 3.0;
rect0.width  = 1.2;
rect0.height = 5.4;

double surf_area = rect0.surfaceArea();
double volume = rect0.volume();
```

## Access Specifiers
Classes have *access specifiers* which is one of the three keywords: `private`, `public`, or `protected`.  
These specifiers modify the access rights for the members as follows:  
 - `private`: accessible only from within other members of the same class (or from their `friends`).
 - `protected`: accessible from other members of the same class (or from `friends`), and from members of their derived classes.
 - `public`: accessible from anywhere where the object is visible.

The default access specifier is `private` within a class. 

**<details><summary>:large_orange_diamond: Access Specifier Example:</summary>**
<p>

```C++
class Rectangle2D {
    int width, height; // private data members
  public:
    void setValues(int w,int h);
    int area(void);
};
```
</p>
</details>

It is recommended that you be explicit with access specifiers, e.g. putting `private:` as needed.

## Scope Operator `::`
We can seperate the function implementation from its declaration inside the class, as did the C source and header files.
We use the scope operator `::` to specify the class to which the member being defined belongs.


**<details><summary>:large_orange_diamond: Rectangle.h</summary>**
<p>

```C++
class Rectangle2D {
    double width, height; // private data members
  public:
    void setValues(double w, double h);
    double area(void);
};
```
</p>
</details>

**<details><summary>:large_orange_diamond: Rectangle.cxx</summary>**
<p>

```C
/* header files */
#include "Rectangle.h"

void Rectangle2D::setValues(double w, double h){
  width = w;
  height = h;
}

double Rectangle2D::area(){
  return width*height;
}
```
</p>
</details>

**<details><summary>:large_orange_diamond: main.cxx</summary>**
<p>

```C++
#include <iostream>
#include "Rectangle.h"

int main(){
  Rectangle2D rec1;
  rec1.setValues(3.3, 7.1);
  std::cout << "rec1 area: " << rec1.area() << std::endl;
  return 0;
}
```
</p>
</details>

---
[**Next**: C++ Constructors](https://github.com/ackirby88/CS107/blob/master/C++/CPP-1-Constructors.md)  
