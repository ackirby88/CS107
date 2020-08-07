
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
      double getArea(){ 
         return (width * height); 
      }
}

int main(void) {
   Rectangle rec;
 
   rec.setWidth(5.0);
   rec.setHeight(7.2);

   // Print the area of the object
   printf("Total area: %f\n",rec.getArea());

   return 0;
}
```
