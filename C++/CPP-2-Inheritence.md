
---
**Key:** 
:large_orange_diamond: - **Code Example** 
:large_blue_diamond: - **Code Exercise** 
:red_circle: - **Code Warning**  
[**Previous**: C++ Constructors](https://github.com/ackirby88/CS107/blob/master/C++/CPP-1-Constructors.md)  
[**Next**: C++ Polymorphism](https://github.com/ackirby88/CS107/blob/master/C++/CPP-2-Polymorphism.md)

---
# C++ Class Inheritance
One of the most important concepts in object-oriented programming is **inheritance**!  
Inheritance allows classes to be defined in terms of another class, which makes it easier to create and maintain an application.  

When creating a class, instead of writing completely new data members and member functions, the programmer can designate that the new class should inherit the members of an existing class. This existing class is called the **base** class, and the new class is referred to as the **derived** class.

#### ``` class derived-class: access-specifier base-class```
 A class derivation list names one or more base classes given the above form where `access-specifier` is one of the following:
 - `public`
 - `protected`
 - `private`  
 
If the access-specifier is not defined, then it is *private* by default.

**Class Inheritance Example:**
```C++
#include <stdio.h>

// Base Class
class Shape {
   public:
      void setWidth(double w){
         width = w;
      }
      void setHeight(double h){
         height = h;
      }
      
   protected:
      double width;
      double height;
}

// Derived Class
class Rectangle : public Shape {
   public:
      double area(){ 
         return (width * height); 
      }
}

// Derived Class
class Triangle : public Shape {
  public:
    double area(){
      return (0.5 * width * height);
    }
};

int main(void) {
   Rectangle rec;
   Triangle tri;
 
   rec.setWidth(5.0);
   rec.setHeight(7.2);
   
   tri.setWidth(5.0);
   tri.setHeight(7.2);

   // Print the area of the object
   printf("Rectangle total area: %f\n",rec.area());
   printf("Triangle  total area: %f\n",tri.area());

   return 0;
}
```
The objects of the classes `Rectangle` and `Triangle` each contain members inherited from Shape. These are: `width`, `height`, `setWidth`, and `setHeight`.

The `protected` access specifier used in class `Shape` is similar to `private`:  
When a class inherits another one, the members of the derived class can access the protected members inherited from the base class, but not its private members.  

By declaring `width` and `height` as `protected` instead of `private`, these members are also accessible from the derived classes `Rectangle` and `Triangle`, instead of just from members of `Shape`. If they were `public`, they could be accessed anywhere.

## Access Control and Inheritance
The different access types can be summarized according to which functions can access them in the following way:  
| Access        | **public** | **protected** | **private**|
|---------------|:----------:|:-------------:|:----------:|
| Same Class    | yes        | yes           | yes        |
| Derived Class | yes        | yes           | no         |
| Outside Class | yes        | no            | no         |

Where `Outside Class` represents any access from outside the class, such as from `main`, from another class, or from a function.

In the example above, the members inherited by `Rectangle` and `Triangle` have the same access permissions as they had in their base class `Shape`: 
**A derived class can access all the non-private members of its base class.**

## What's Inherited from the Base Class?
In principle, a publicly derived class inherits access to every member of a base class except:  
- its constructors and its destructor
- its assignment operator members (operator=)
- its friends (`friend` class whose members have access to the private or protected members of another class)
- its private members

Even though access to the constructors and destructor of the base class is not inherited, they are *automatically* called by the constructors and destructor of the derived class.

Unless otherwise specified, the *constructors of a derived class calls the default constructor of its base classes* (i.e., the constructor taking no arguments). Calling a different constructor of a base class is possible, using the same syntax used to initialize member variables in the initialization list:
```
derived_constructor_name (parameters) : base_constructor_name (parameters) {...}
```

**Calling Base-Class Constructor in Derived-Class Constuctor Example:**  
```C++
#include <iostream>

class Polygon {
  protected:
    int a;
  public:
    // default constructor
    Polygon() : a(0) {
      std::cout << "Polygon default contructor called!\n";
    }
    // constructor with input argument
    Polygon(int a_) : a(a_) {
      std::cout << "Polygon input contructor called!\n";
    }
};

class Circle : public Polygon {
  public:
    // default constructor
    Circle() {
      std::cout << "Circle default contructor called!\n";
    }
    // constructor with input argument
    Circle(int a_) : Polygon(a_) {
      std::cout << "Circle intput contructor called!\n";
    }
};

int main(){
  Polygon shape(1); std::cout << std::endl;
  Circle circ1(2); std::cout << std::endl;
  Circle circ2;
  return 0;
}
```
:large_orange_diamond: [Constructor Inheritance Demo](https://bit.ly/3fBPZDR)  

### :question: **Question** :question: What's the output of the above `main` function?
<details><summary>Answer</summary>
<p>
 
```
Polygon input contructor called!

Polygon input contructor called!
Circle intput contructor called!

Polygon default contructor called!
Circle default contructor called!
```
</p>
</details>

## Multiple Inheritance
A class may inherit from more than one class by simply specifying more base classes, separated by commas, in the list of a class's base classes (i.e., after the colon). 

For example, if the program had a specific class to print on screen called `Output`, and we wanted our class `Circle` to also inherit its members in addition to those of `Polygon`:  
**Multiple Inheritance Example:**  
```C++
#include <iostream>

class Polygon {
  protected:
    int a;
  public:
    Polygon() : a(999) {}
    Polygon(int a_) : a(a_) {}
};

class Output {
  public:
    void print(int v){
      std::cout << "Value: " << v << std::endl;
    }
};

class Circle : public Polygon, public Output {
  public:
    Circle() {}
    Circle(int a_) : Polygon(a_) {}
    
    // method
    int get_a(){return a;}
};

int main(){
  Circle circ1(2);
  Circle circ2;
  
  circ1.print(circ1.get_a());
  circ2.print(circ2.get_a());
  return 0;
}
```

<details><summary>Output</summary>
<p>
 
```
Value: 2
Value: 999
```
</p>
</details>

---
[**Next**: C++ Polymorphism](https://github.com/ackirby88/CS107/blob/master/C++/CPP-2-Polymorphism.md)


