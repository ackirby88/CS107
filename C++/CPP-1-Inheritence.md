
---
**Key:** 
:large_orange_diamond: - **Code Example** 
:large_blue_diamond: - **Code Exercise** 
:red_circle: - **Code Warning**  
[**Previous**: C++ Classes and Objects](https://github.com/ackirby88/CS107/blob/master/C++/CPP-0-ClassesObjects.md)  
[**Next**: C++ Polymorphism](https://github.com/ackirby88/CS107/blob/master/C++/CPP-2-Ploymorphism.md)

---
# C++ Class Inheritance
One of the most important concepts in object-oriented programming is **inheritance**!  
Inheritance allows classes to be defined in terms of another class, which makes it easier to create and maintain an application.  

When creating a class, instead of writing completely new data members and member functions, the programmer can designate that the new class should inherit the members of an existing class. This existing class is called the **base** class, and the new class is referred to as the **derived** class.

#### ``` class derived-class: access-specifier base-class 1, access-specifier base-class 2, ... ```
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
