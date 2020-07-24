
---
**Key:** 
:large_orange_diamond: - **Code Example** 
:large_blue_diamond: - **Code Exercise** 
:red_circle: - **Code Warning**  
[**Previous**: C Data Types](https://github.com/ackirby88/CS107/blob/master/C-Basics/C-3-CDataTypes.md)  
[**Next**: Memory, Pointers, References](https://github.com/ackirby88/CS107/blob/master/C-Basics/C-5-Memory.md)

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

#### Fall-through

# Loops
### `for`

### `while`

### `do`

### `continue`, `break`

# Functions
## Variadic Functions

---
[**Next**: Memory, Pointers, References](https://github.com/ackirby88/CS107/blob/master/C-Basics/C-5-Memory.md)
