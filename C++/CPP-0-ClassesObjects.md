
---
**Key:** 
:large_orange_diamond: - **Code Example** 
:large_blue_diamond: - **Code Exercise** 
:red_circle: - **Code Warning**  
[**Previous**: C Basics - Function Pointers](https://github.com/ackirby88/CS107/blob/master/C-Basics/C-6-FunctionPointers.md)  
[**Next**: C++ Inheritence](https://github.com/ackirby88/CS107/blob/master/C++/CPP-1-Inheritence.md)

---
# C++ Function Defaults
Functions in C++ can have default arguments:  
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
Note that default arguments must come at the end of the argument list in the function.

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
**Example:**
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
For example, 
```C++
class Rectangle2D {
    int width, height; // private data members
  public:
    void setValues(int w,int h);
    int area(void);
};
```
It is recommended that you be explicit with access specifiers, e.g. putting `private:` as needed.

## Scope Operator `::`
We can seperate the function implementation from its declaration inside the class, as did the C source and header files.
We use the scope operator `::` to specify the class to which the member being defined belongs.

**Rectangle.h**
```C++
class Rectangle2D {
    double width, height; // private data members
  public:
    void setValues(double w, double h);
    double area(void);
};
```
**Rectangle.cxx**
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
**main.cxx**
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

## Constructors
In the above example, what would happen if we didn't set the values of the rectangles before calling `area()`?  
We get an undetermined result since `height` and `width` are set.

To prevent this situation, a class can include a special function called a **constructor**, which is automatically called when a new object of the class is instantiated. The constructor can be used to allocate memory and initialize data members.

The **constructor** function is declared similarly to a member function, but its name matches the name of the class and without a return type.
```C++
class Rectangle2D {
    double width, height; // private data members
  public:
    /* constructor */
    Rectangle2D(double w, double h);
    
    /* methods */
    void setValues(double w, double h);
    double area(void);
};

Rectangle2D::Rectangle2D(double w, double h){
  width = w;
  height = h;
}
```

### Member Initialization in Constructors
When a constructor is used to initialize other members, these other members can be initialized directly, without using assignment statements inside the body. 
This is done by inserting, before the constructor's body, a single colon `:` and a list of initializations for class members. For example,  
- `Rectangle2D::Rectangle2D(double w, double h) : height(h), width(w) {}`, or  
- `Rectangle2D::Rectangle2D(double w, double h) : width(w) {height = h;}`, or  
- `Rectangle2D::Rectangle2D(double w, double h) : height(h) {width = w;}`, or 
- `Rectangle2D::Rectangle2D(double w, double h) {height = h; width = w;}`.

## Pointers to Classes
Objects can also be pointed to by pointers: `Rectangle2D *p_rec;`.
As we saw in C, the members of an object can be accessed directly from a pointer by using the arrow operator `->`.  

**Example:**
```C++
#include <iostream>
using std::cout;
using std::endl;

class Rectangle {
private:
  int width, height;
public:
  Rectangle(int x, int y) : width(x), height(y) {}
  int area(void) {return width * height;}
};

int main() {
  Rectangle obj(3,4);
  Rectangle *foo, *bar, *baz;
  
  foo = &obj;
  bar = new Rectangle(5,6);
  baz = new Rectangle[2] {{2,5}, {3,6}}; // can initialize via {}

  cout << "   obj's area: " << obj.area()    << endl;
  cout << "  *foo's area: " << foo->area()   << endl;
  cout << "  *bar's area: " << bar->area()   << endl;
  cout << "baz[0]'s area: " << baz[0].area() << endl;
  cout << "baz[1]'s area: " << baz[1].area() << endl;
  delete bar;
  delete[] baz;
  return 0;
}	
```

| **expression** | description     |
|:---------------|-----------------|
| `*x`           | pointed to by x |
| `&x`           | address of x |
| `x.y`          | member y of object x |
| `x->y`         | member y of object pointed to by x |
| `(*x).y`       | member y of object pointed to by x |
| `x[0]`         | first object pointed to by x |

## Operator Overloading
The C++ language was designed to define new types via calsses that are operate like the fundamental types: `int`, `double`, etc.  
To enable this behavior, we can define and implement operations such as add `+` or `<` even though it may not be obvious.  
For example, 
```C++
class apple {
  string color;
  float price;
} a, b, c;

a = b + c; // not obvious how to add apple objects...
```
C++ enables developers to overload most operators so that the behavior is well defined.  
Here is a list of all of the operators that can be overloaded:
| Overloadable Operators |
|------------------------|
| `+`  `-`  `*`  `/` `=`  `<`  `>`  `+=` `-=` `*=` `/=` `<<` `>>` |
| `<<=` `>>=`  `==`  `!=` `<=` `>=` `++` `--` `%`  `&`  `^`  `!`  `\|` |
| ` ~`  `&=`   `^=`  `\|=` `&&` `\|\|` `%=` `[]` `()` `,`  `->*` `->` |
| `new`  `delete`  `new[]`  `delete[]` |

### Operator Overloading Syntax
The syntax is as follows: `type operator sign (parameters) {/* body */}`.  

### Operator Overloading Example
To demonstrate operator overloading, we will look at a *3D Cartesian Vectors* class.  
```C++
#include <stdio.h>

class CVector {
  public:
    double x,y,z;
    CVector() {}; // default constructor
    CVector(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {} // initialization constructor

    CVector operator+(const CVector&);
};

CVector CVector::operator+(const CVector& param) {
  CVector vecsum;
  vecsum.x = x + param.x;
  vecsum.y = y + param.y;
  return vecsum;
}

int main () {
  CVector vec_a(3,1);
  CVector vec_b(1,2);
  CVector vec_c = vec_a + vec_b
  
  printf("Vector C = <%f, %f, %f>\n",vec_c.x, vec_c.y, vec_c.z);
  return 0;
}
```

---

Next , we will look at why C++ objects are so useful in an Object-Oriented Programming paradigm.

---
[**Next**: C++ Inheritence](https://github.com/ackirby88/CS107/blob/master/C++/CPP-1-Inheritence.md)
