
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
The functions declaration must differ in type or number of input arguments.

# C++ Classes

# C++ Objects

---
[**Next**: C++ Inheritence](https://github.com/ackirby88/CS107/blob/master/C++/CPP-1-Inheritence.md)
