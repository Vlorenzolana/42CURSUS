# CPP02
C++ Exercises: class management, operators, constructors, copy semantics, and member functions.

## How to Build
Each exercise has its own `Makefile`. To compile, look up Makefile.

## Ex00
- Main files: `main.cpp`, `Fixed.cpp`, `Fixed.hpp`.
- Objective: implement a `Fixed` class with default constructor, copy constructor, assignment operator, destructor, and basic methods (`getRawBits`, `setRawBits`).
- Executable: `./fixed` (generated in the exercise folder).
- Observed behavior (example): calls to constructors/destructors and `getRawBits`/`setRawBits`.

## Ex01
- Main files: `main.cpp`, `Fixed.cpp`, `Fixed.hpp`.
- Objective: add constructors to create `Fixed` from `int` and `float`, proper conversion handling, and `toInt()` / `toFloat()` methods.
- Executable: `./fixed`.
- Observed behavior (example): printing values as float/int and correct use of constructors and operators.

## Ex02
- Main files: `main.cpp`, `Fixed.cpp`, `Fixed.hpp`.
- Objective: implement arithmetic operators (+, -, *, /), comparison operators, increment/decrement operators (pre and post), and static `min`/`max` functions.
- Executable: `./fixed`.
- Observed behavior (example): arithmetic operations, comparisons, and pre/post-increment behavior.

## Ex03
- Main files: `main.cpp`, `Fixed.cpp`, `Fixed.hpp`, `Point.cpp`, `Point.hpp`.
- Objective: add the `Point` class and the `bsp` program that determines whether a point is inside a triangle (using the `bsp` function).
- Executable: `./bsp`.
- Observed behavior (example): output like `Point (3,3) is INSIDE the triangle a-b-c`.

## Quality and Optional Testing
- Run `valgrind --leak-check=full ./fixed` (or the corresponding executable) to check for memory leaks.
- If you want to check code style, run your local linter/`norminette` (if applicable in your environment).

## AI Usage and Best Practices
This repository was developed with assistance (review/suggestions) from AI tools. Best practices followed:
- Manually review all AI suggestions before applying them.
- Test generated binaries and verify absence of memory leaks when applicable.
- Keep code compatible with `-std=c++98` as required by the course.
