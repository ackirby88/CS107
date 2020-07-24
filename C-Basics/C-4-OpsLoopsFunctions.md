
---
**Key:** 
:large_orange_diamond: - **Code Example** 
:large_blue_diamond: - **Code Exercise** 
:red_circle: - **Code Warning**  
[Previous: C Data Types](https://github.com/ackirby88/CS107/blob/master/C-Basics/C-3-CDataTypes.md)

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
### `if/elseif/else`
### `switch`
#### Fall-through

# Loops
### `for`

### `while`

### `continue`, `break`

# Functions
## Variadic Functions

---
[Next: Memory, Pointers, References](https://github.com/ackirby88/CS107/blob/master/C-Basics/C-5-Memory.md)
