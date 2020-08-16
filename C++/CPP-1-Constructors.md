
---
**Key:** 
:large_orange_diamond: - **Code Example** 
:large_blue_diamond: - **Code Exercise** 
:red_circle: - **Code Warning**  
[**Previous**: C++ Classes & Objects](https://github.com/ackirby88/CS107/blob/master/C++/CPP-0-ClassesObjects.md)  
[**Next**: C++ Inheritance](https://github.com/ackirby88/CS107/blob/master/C++/CPP-2-Inheritence.md)

---
# C++ Constructors
In the above example, what would happen if we didn't set the values of the rectangles before calling `area()`?  
We get an undetermined result since `height` and `width` are set.

To prevent this situation, a class can include a special function called a **constructor**, which is automatically called when a new object of the class is instantiated. The constructor can be used to allocate memory and initialize data members.

The **constructor** function is declared similarly to a member function, but its name matches the name of the class and without a return type.

**<details><summary>:large_orange_diamond: Constructor Example:</summary>**
<p>
    
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
</p>
</details>

We can have multiple constructors such as a default constructor or copy constructor.
**<details><summary>:large_orange_diamond: Multiple Constructors Example:</summary>**
<p>
    
```C++
class Rectangle2D {
    double width, height; // private data members
  public:
    /* constructors */
    Rectangle2D();
    Rectangle2D(double w, double h);
    
    /* methods */
    void setValues(double w, double h);
    double area(void);
};

// default constructor
Rectangle2D::Rectangle2D(){
  width = 1.0;
  height = 1.0;
}

Rectangle2D::Rectangle2D(double w, double h){
  width = w;
  height = h;
}
```
</p>
</details>

### Member Initialization in Constructors
When a constructor is used to initialize other members, these other members can be initialized directly, without using assignment statements inside the body. 
This is done by inserting, before the constructor's body, a single colon `:` and a list of initializations for class members. For example,  
- `Rectangle2D::Rectangle2D(double w, double h) : height(h), width(w) {}`, or  
- `Rectangle2D::Rectangle2D(double w, double h) : width(w) {height = h;}`, or  
- `Rectangle2D::Rectangle2D(double w, double h) : height(h) {width = w;}`, or 
- `Rectangle2D::Rectangle2D(double w, double h) {height = h; width = w;}`.

### Default Constructor
The default constructor is the constructor called when objects of a class are declared, but are not initialized with any arguments.  
If a class definition has no constructors, the compiler assumes the class to have an implicitly defined default constructor. 
```C++
class MyClass {
  public:
    int value;
    void setValue(int v){value = v;};
}
...
MyClass example; // implicit default constructor
```
As soon as any constructor is declared in the class definition, then the compiler no longer provides an implicit default constructor!  
But remember that we can have multiple constructors through function polymorphism.

### Deconstructor
Destructors are responsible for the necessary cleanup needed by a class when its lifetime ends.  
A destructor is a member function very similar to a default constructor: it takes no arguments and returns nothing. 
It also uses the class name as its own name, but preceded with a tilde sign `~`:
```C++
class MyClass2 {
  public:
    /* data members */
    int narray;
    double *darray;

    /* constructors */
    MyClass2(){darray = nullptr;}; // default constructor
    MyClass2(int n) : narray(n) {darray = new double[n];}
    
    /* deconstructor */
    ~MyClass2(){
      if (darray) {
        delete [] darray;
      }
    }
    
    /* member functions */
    void setNArray(int v){narray = v};    
}
```

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
**vectors.cxx:**
```C++
#include <stdio.h>

class CVector {
  public:
    double x,y,z;
    CVector() {}; // default constructor
    CVector(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {} // initialization constructor

    CVector operator+ (const CVector&); // function that returns a CVector
};

CVector CVector::operator+ (const CVector& param) {
  CVector vecsum; // default constructor
  vecsum.x = x + param.x;
  vecsum.y = y + param.y;
  vecsum.z = z + param.z;
  return vecsum;
}

int main () {
  CVector vec_a(3.1, 1.1, 0.0);
  CVector vec_b(1.0, 2.9, 8.7);
  CVector vec_c = vec_a + vec_b;
  
  printf("  Vector A = <%f, %f, %f>\n",vec_a.x, vec_a.y, vec_a.z);
  printf("+ Vector B = <%f, %f, %f>\n",vec_b.x, vec_b.y, vec_b.z);
  printf("= Vector C = <%f, %f, %f>\n",vec_c.x, vec_c.y, vec_c.z);
  return 0;
}
```
**Output:**
```bash
$ ./vectors 
  Vector A = <3.100000, 1.100000, 0.000000>
+ Vector B = <1.000000, 2.900000, 8.700000>
= Vector C = <4.100000, 4.000000, 8.700000>
```

We can even add the vectors directly calling the operator using member access:  
```C++
CVector vec_c = vec_a.operator+ vec_b;
```
:large_orange_diamond: [Vectors Addition Source](https://bit.ly/30x4STR)

### Operator Overloading Expressions
The operator overloads are just regular functions which can have any behavior!  
This is no requirement that the operation actually resembles the mathematical or usual meaning of the operator.  
For example, a class that overloads `operator+` to actually subtract is perfectly valid. Although, it's highly discouraged for readability.

The parameter expected for a member function overload for operations such as `operator+` is naturally the operand to the right hand side of the operator. 
This is common to all binary operators (those with an operand to its left and one operand to its right). But operators can come in diverse forms.  

Summary of the parameters needed for each of the different operators than can be overloaded:  
**Replace `@` by the operator (a is an object of A, b is an object B, and c is an object of C)**:  
| Expression | Operator                                                                               | Member Function       | Non-Member Function |
|------------|----------------------------------------------------------------------------------------|-----------------------|---------------------|
| @a         | `+` `-` `*` `&` `!` `~` `++` `--`                                                      | A::operator@()        | operator@(A)        |
| a@         | `++` `--`                                                                              | A::operator@(int)     | operator@(A,int)    |
| a@b        | `+` `-` `*` `/` `%` `^` `&` `\|` `<` `>` `==` `!=` `<=` `>=` `<<` `>>` `&&` `\|\|` `,` | A::operator@(B)       | operator@(A,B)      |
| a@b        | `=` `+=` `-=` `*=` `/=` `%=` `^=` `&=` `\|=` `<<=` `>>=` `[]`                          | A::operator@(B)       | -                   |
| a(b,c,...) | `()`                                                                                   | A::operator()(B,C,...)| -                   |
| a->b       | `->`                                                                                   | A::operator->()       | -                   |
| (TYPE) a   | TYPE, e.g. `int`                                                                       | A::operator TYPE()    | -                   |

Notice that some operators may be overloaded in two forms:  
- as a class member function (as seen in the above example for `operator+`)
- as a non-member function (not a function in the class definition)

In the second case, some operators can also be overloaded as non-member functions. 
The operator function takes an object of the proper class as first argument.

**Non-Member Function Operation Overload Example:**
```C++
#include <stdio.h>

class CVector {
  public:
    double x,y,z;
    CVector() {}; // default constructor
    CVector(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {} // initialization constructor
};

// Non-Member Function (not a part of the class definition): overload + operator
CVector operator+ (const CVector& lhs, const CVector& rhs) {
  CVector temp;
  temp.x = lhs.x + rhs.x;
  temp.y = lhs.y + rhs.y;
  temp.z = lhs.z + rhs.z;
  return temp;
}

int main () {
  CVector foo(3., 1., -1.);
  CVector bar(1., 2.,  2.);
  CVector result;
  result = foo + bar;
  
  printf("result = <%f, %f, %f>\n",result.x, result.y, result.z);
  return 0;
}
```

### The `this` Keyword
The keyword `this` represents a pointer to the object whose member function is being executed.  
It is used within a class's member function to refer to the object itself.

It can be used to check if a parameter passed to a member function is the object itself.
```C++
#include <iostream>

class Vec {
  public:
    double x, y, z;
    Vec(double x, double y, double z){
      this->x = x;
      this->y = y;
      this->z = z;
    }
    bool isitme(Vec &param);
};

bool Vec::isitme(Vec &param){
  if(&param == this) return true;
  return false;
}

int main () {
  Vec a;
  Vec *b = &a;
  if (b->isitme(a)) {
    std::cout << "yes, &a is b\n";
  }
  return 0;
}
```

### Const Member Functions
The `const` qualifier can be used in various scenarios:  
```C++
const Vector vec_a;                // data members read-only from outside the class
int getVec() const {return x;}     // const member function: enables a const object the ability to call getVec()
const int& get() {return x;}       // member function returning a const&
const int& get() const {return x;} // const member function returning a const&
```

### Copy Constructor
Now that we have some familiarity with operator overloading, we can introduce the **copy constructor**.  
When an object is passed a named object of its own type as argument, its *copy constructor* is invoked in order to construct a copy.  

There is an implicit *copy constructor* that performs a **shallow** copy:  
`Vec::Vec(const Vec &b) : x(b.x), y(b.y), z(b.z) {}`
```C++
Vec foo;       // default constructor
Vec bar(foo);  // object initialization: copy constructor called
Vec baz = foo; // object initialization: copy constructor called
foo = bar;     // object already initialized: copy assignment called
```
**Note that baz is initialized on construction using an equal sign, but this is not an assignment operation!**  
The assignment on `foo` is an assignment operation. No object is being declared here, but an operation is being performed on `foo`.  
The copy assignment operator is an overload of `operator=` which takes a value or reference of the class itself as parameter.  
The return value is generally a reference to `*this` (although not required).  

For example, for our class `Vec`, the copy assignment may have the following signature:  
```C++
// version 1
Vec& operator= (const Vec&);

// version 2
Vec& operator= (const Vec &b) {
  // optionally delete or allocate space and copy data
  return *this;
}
```

---

Next , we will look at why C++ objects are so useful in an Object-Oriented Programming paradigm.

---
[**Next**: C++ Inheritance](https://github.com/ackirby88/CS107/blob/master/C++/CPP-2-Inheritence.md)

