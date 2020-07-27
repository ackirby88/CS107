
---
**Key:** 
:large_orange_diamond: - **Code Example** 
:large_blue_diamond: - **Code Exercise** 
:red_circle: - **Code Warning**  
[**Previous**: C Data Types](https://github.com/ackirby88/CS107/blob/master/C-Basics/C-3-CDataTypes.md)  
[**Next**: Arrays, Pointers, Memory, References](https://github.com/ackirby88/CS107/blob/master/C-Basics/C-5-Memory.md)

---
# Operators
## Unary Operators
- minus `-`, plus `+`
- logical negation `!`
- prefix increment `++` and decrement `--`
- address operator `&` and indirection `*`
- bitwise negation `~`
- cast operator
- `sizeof` operator

## Binary Operators
- multiplication `*`, remainder `%`, and division `/`
- addition `+` and subtraction `-`
- left shift `<<` and right shift `>>`
- less than `<`, less than or equal to `<=`, greater than `>`, and greater than or equal to `>=`
- equality `==` and inequality `!=`
- bitwise operators: AND `&`, OR `|`, and XOR `^`
- logical operators: AND `&&` and OR `||`

## Conditional (Ternary) Operator
The conditional operator `(expression) ? (val1):(val2)` takes three operands. It tests the result of the first operand and then evaluates one of the other two operands based on the result of the first.
```C
if (expression == true) {
  ret = (val1);
} else {
  ret = (val2);
}

// ternary operator
ret = (expression) ? (val1):(val2) ;
```

Example:
```C
int a = (x < y) ? x : y; // a = min(x, y)
```

# Logic
## `if`
```C
// with braces
if (x == 100) {
  cout << "x is 100";
}

// indented, no braces
if (x == 100)
  cout << "x is 100";

// inline
if(x == 100) cout << "x is 100";
```
Note that for inline conditionals, the first expression is only subject to the conditional.  
In the following example, only `free(my_ptr)` is subject to the conditional statement, and `my_ptr = NULL;` is **always** executed.
```C
if(my_ptr != NULL) free(my_ptr); my_ptr = NULL;
```

## `else`
We can have more conditionals using `else if` and `else`. Again, **braces are optional but highly recommended!**
```C
if (x > 0)
  cout << "x is positive";
else if (x < 0)
  cout << "x is negative";
else
  cout << "x is 0";
```

## `switch`
The `switch` control structure can simplify `else if` statements. The general structure is as follows:
```C
switch (expression) {
  case constant1:
     group of statements 1;
     break;
  case constant2:
     group of statements 2;
     break;
  .
  .
  .
  default:
     default group of statements
}
```

Notice the use of `break;` statements within the `case` options.  
If we don't include the `break`, it will execute that case **and** the next case, resulting in *fall-through*.  
Example:
```C
switch (x) {
  case 1: group of statements 1; // fall-through to also execute case 2.
  case 2: group of statements 2; break;
  .
  default:
     default group of statements
}
```
If `x = 1`, then the statements for `case 1` **and** `case 2` are executed.  
:large_orange_diamond:[Switch Case Demo](https://bit.ly/2OWazEm)

# Loops
## The `for` Loop
Format:
```C
for (initialization; condition; increase) statement;
```
Example:
```C++
for (int i = 0; i < 100; ++i) {
  i *= 10;
}
```

Optionally, we can add more arguments inside the `for` loop arguments:
```C
for (n = 0, i = 100; n != i; n++, i--) {
   // whatever here...
}
```

## The `while` Loop
Format:
```C
while (expression) statement
```
Example:
```C++
#include <iostream>
using namespace std;

int main(void){
  int n;
  cout << "Enter the starting number > ";
  cin >> n;

  while (n>0) {
    cout << n << ", ";
    --n;
  }

  cout << "FIRE!\n";
  return 0;
}
```
## The `do-while` Loop
Format:
```C
do statement while (condition);
```
Example:
```C++
#include <iostream>
using namespace std;

int main(void){
  unsigned long n;
  do {
    cout << "Enter number (0 to end): ";
    cin >> n;
    cout << "You entered: " << n << "\n";
  } while (n != 0);
  return 0;
}
```

# Jump Statements
## The `break` Statement
Using `break` we can leave a loop even if the condition for its end is not fulfilled.  
It can be used to end an infinite loop, or to force it to end before its natural end.  
```C++
#include <iostream>
using namespace std;

int main(void){
  for (int n = 10; n > 0; n--) {
    cout << n << ", ";
    if (n == 3){
      cout << "countdown aborted!";
      break;
    }
  }
  return 0;
}
```
Result: `10, 9, 8, 7, 6, 5, 4, 3, countdown aborted!`  

## The `continue` Statement
The `continue` statement causes the program to skip the rest of the loop in the current iteration as if the end of the statement block had been reached, causing it to jump to the start of the following iteration.
```C++
// continue loop example
#include <iostream>
using namespace std;

int main(void){
  for (int n = 10; n > 0; n--) {
    if (n == 5) continue;
    cout << n << ", ";
  }
  cout << "FIRE!\n";
  return 0;
}
```
Result: `10, 9, 8, 7, 6, 4, 3, 2, 1, FIRE!`  

# Functions
```C
return_type function_name (argument list){
    Set of statements – Block of code
}
```

## Variadic Functions
Variadic functions are functions (e.g. printf) which take a variable number of arguments.
```C
#include <stdio.h>
#include <stdarg.h>

void simple_printf(const char* fmt, ...){
    va_list args;
    va_start(args, fmt);
 
    while (*fmt != '\0') {
        if (*fmt == 'd') {
            int i = va_arg(args, int);
            printf("%d\n", i);
        } else if (*fmt == 'c') {
            // A 'char' variable will be promoted to 'int'
            // A character literal in C is already 'int' by itself
            int c = va_arg(args, int);
            printf("%c\n", c);
        } else if (*fmt == 'f') {
            double d = va_arg(args, double);
            printf("%f\n", d);
        }
        ++fmt;
    }
    va_end(args);
}

int main(void){
    simple_printf("dcff", 3, 'a', 1.999, 42.5); 
}
```

---
[**Next**: Arrays, Pointers, Memory, References](https://github.com/ackirby88/CS107/blob/master/C-Basics/C-5-Memory.md)
