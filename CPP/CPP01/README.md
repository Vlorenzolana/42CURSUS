# CPP01
Memory allocation, pointers to members, references and switch statements.
*NOTE: In CPP01 is not mandatory o use "Orthodox Canonical Class Form" or "Rule of Three/Four"*
## Ex00

- There is a `main.cpp` for testing: the program **compiles and runs correctly**, creating:
  - A `Zombie` on the **heap** with `newZombie`
  - A `Zombie` on the **stack** with `randomChump`
  - The heap `Zombie` is properly freed with `delete`

- The **Makefile** compiles with:
  - `c++`
  - Flags: `-Wall -Wextra -Werror -std=c++98`

- Binary execution:
  - `./brainz <zombie_name> <randomchump_name>`

- **Expected output**:
```
StackZombie: BraiiiiiiinnnzzzZ...
HeapZombie: BraiiiiiiinnnzzzZ...
Zombie HeapZombie destroyed
Zombie StackZombie destroyed
```

- The **Zombie** class:
  - Has a private attribute `name` (`_name`)
  - Implements **constructor** and **destructor**

- `announce()`:
  - Is **public**
  - Prints exactly the required format:  
    ```
    <name>: BraiiiiiiinnnzzzZ...
    ```

- The **constructor** automatically calls `announce()`

- The **destructor** prints a message with the zombie's name (debug message), as required by the subject

- Correctly demonstrates the difference between **heap** and **stack**:
  - `newZombie()`:
    - Allocates memory on the heap
    - Returns a pointer: `new Zombie(name)`
  - `randomChump()`:
    - Creates the object on the stack
    - Automatically destroyed when leaving the function

---

## Ex01

- There is a `main.cpp` for testing: the program **compiles and runs correctly**, creating a zombie horde

- The **Makefile** compiles with:
  - `c++`
  - Flags: `-Wall -Wextra -Werror -std=c++98`

- Binary execution:
  - `./horde 3 Walker`

- **Expected output**:
```
Walker: BraiiiiiiinnnzzzZ...
Walker: BraiiiiiiinnnzzzZ...
Walker: BraiiiiiiinnnzzzZ...
Zombie Walker destroyed
Zombie Walker destroyed
Zombie Walker destroyed
```

- The **Zombie** class:
  - Has a private attribute `name` (`_name`)
  - Implements **default constructor** and **destructor**
  - Has a `setName()` method to assign the name after creation

- `announce()`:
  - Is **public**
  - Prints exactly the required format:  
    ```
    <name>: BraiiiiiiinnnzzzZ...
    ```

- `zombieHorde(int N, std::string name)`:
  - Allocates **N Zombie objects** in a **single allocation** with `new Zombie[N]`
  - Assigns the name to each zombie with `setName()`
  - Each zombie announces itself with `announce()`
  - Returns a pointer to the first zombie of the horde

- The **destructor** prints a debug message when each zombie is destroyed

- **Memory management**:
  - Properly freed with `delete[]`
  - **0 memory leaks** verified with `valgrind --leak-check=full ./horde 3 Walker`

- **Input validation**:
  - Checks that the number of zombies is greater than 0
  - Returns `NULL` if creation fails

---

## Ex02

- Exercise to understand the difference between **pointers** and **references** in C++

- The **Makefile** compiles with:
  - `c++`
  - Flags: `-Wall -Wextra -Werror -std=c++98`

- Binary execution:
  - `./brain` (no arguments)

- **Variables created**:
  - `std::string string` → original variable with value `"HI THIS IS BRAIN"`
  - `std::string *stringPtr` → pointer to the variable
  - `std::string &stringRef` → reference to the variable

- **Expected output** (addresses will vary):
```
Memory address of string variable:       0x7ff...   
Memory address held by stringPtr:        0x7ff...   
Memory address pointed to by stringPtr:  0x7ff...   
Memory address held by stringRef:        0x7ff...   

Value of string variable:                HI THIS IS BRAIN
Value pointed to by stringPtr:           HI THIS IS BRAIN
Value pointed to by stringRef:           HI THIS IS BRAIN
```

- **Key concept**:
  - A **reference** is an **alias** of the original variable
  - Shares the same memory address as the variable
  - A **pointer** stores a memory address and has its own address

---

## Ex03

- Exercise to understand **when to use pointers and when to use references** in class attributes

- The **Makefile** compiles with:
  - `c++`
  - Flags: `-Wall -Wextra -Werror -std=c++98`

- Binary execution:
  - `./violence <name_1> <name_2>`

- **Expected output** (example):
```
Spawned HumanA Alice
Alice attacks with their sword
Spawned HumanB Bob
Bob attacks with their bare hands (no weapon equipped)
Sword has been dropped
HumanA Alice has fled the battle
HumanB Bob has fled the battle
```

- **Weapon class**:
  - Private attribute `_type` (weapon type)
  - `getType()` → returns the weapon type (const)
  - `setType()` → changes the weapon type

- **HumanA class**:
  - Attribute `Weapon &hitter` → **reference**
  - The weapon is passed in the **constructor** (mandatory)
  - **Always has a weapon** (cannot be NULL)
  - If the weapon changes externally, HumanA reflects it automatically

- **HumanB class**:
  - Attribute `Weapon *hitter` → **pointer**
  - The weapon is assigned with `setWeapon()` (optional)
  - **May not have a weapon** (can be NULL)
  - Must check if the weapon exists before using it

- **Key concept**:
  - Use **reference** when the object **must always exist**
  - Use **pointer** when the object **can be optional** (NULL)

---

## Ex04

- File and string manipulation exercise **without using `std::string::replace`**

- The **Makefile** compiles with:
  - `c++`
  - Flags: `-Wall -Wextra -Werror -std=c++98`

- Binary execution:
  - `./sed <filename> <s1> <s2>`

- **How it works**:
  - Reads the file `<filename>`
  - Replaces all occurrences of `<s1>` with `<s2>`
  - Writes the result to `<filename>.replace`

- **std::string methods used**:
  - `find()` → search for the string to replace
  - `erase()` → remove the found string
  - `insert()` → insert the new string
  - `length()` → get string length

- **File handling**:
  - `std::ifstream` → input file reading
  - `std::ofstream` → output file writing
  - `std::getline()` → read line by line
  - `.close()` → close files (like closing fds)

- **Validations**:
  - Checks number of arguments (exactly 3)
  - Checks that `s1` is not empty
  - Checks that files can be opened

- **Expected output**:
  - On incorrect invocation:
```
Error: Must take exactly 3 args
Usage: ./sed <filename> <to_be_replaced> <to_replace_with>
```
  - If `s1` is empty:
```
Error: Cannot extract an empty string
```
  - If a file cannot be opened (example):
```
Error: Cannot open <filename>
```
  - On success: no stdout is produced; the transformed file is written to `<filename>.replace`.
  - *For example: ./sed inputfile bat REPLACED*
    *Begirada bat kalean(...) -> Begirada REPLACED kalean (...)*

---

## Ex05

- Exercise to use **pointers to member functions** of a class

- The **Makefile** compiles with:
  - `c++`
  - Flags: `-Wall -Wextra -Werror -std=c++98`

- Binary execution:
  - `./harl <level>` where level is: `DEBUG`, `INFO`, `WARNING` or `ERROR`

- **Harl class**:
  - 4 private methods: `debug()`, `info()`, `warning()`, `error()`
  - Public method `complain(std::string level)` that calls the corresponding method

- **Pointers to member functions**:
  ```cpp
  typedef void (Harl::*method_pointer)(void);
  method_pointer functions[] = {&Harl::debug, &Harl::info, ...};
  (this->*functions[index])();
  ```

- **Using enum**:
  - `switch` in C++98 does not accept strings
  - `enum` is used to convert string to int
  - `getComplaintLevel()` does the conversion

- **Output**:
  - Shows **only** the indicated level

- **Expected output** (examples):
  - `./harl DEBUG`
```
Harl object constructed
DEBUG: This is a generic complaint. I just love complaining.
Harl object destroyed
```
  - `./harl WARNING`
```
Harl object constructed
WARNING: I am an entitled and bossy Harl and I will treat you like scum
Harl object destroyed
```

---

## Ex06

- Variant of ex05: **Harl filter** (log level filter)

- The **Makefile** compiles with:
  - `c++`
  - Flags: `-Wall -Wextra -Werror -std=c++98`

- Binary execution:
  - `./harlFilter <level>` where level is: `DEBUG`, `INFO`, `WARNING` or `ERROR`

- **Difference from ex05**:
  - Shows the indicated level **and all higher levels**
  - Works like a log filter (higher level logs are always shown)

- **Behavior**:
  | Input   | Output                         |
  |---------|--------------------------------|
  | DEBUG   | DEBUG + INFO + WARNING + ERROR |
  | INFO    | INFO + WARNING + ERROR         |
  | WARNING | WARNING + ERROR                |
  | ERROR   | ERROR                          |

- **Implementation**:
  - Uses `switch` to determine the starting index
  - `for` loop from that index to the end of the function array

- **Expected output** (filter behavior examples):
  - `./harlFilter DEBUG`
```
Harl object constructed
DEBUG: This is a generic complaint. I just love complaining.
INFO: Not getting over-the-top quality at half price will make me angry
WARNING: I am an entitled and bossy Harl and I will treat you like scum
ERROR: I want to speak to your manager!
Harl object destroyed
```
  - `./harlFilter INFO`
```
Harl object constructed
INFO: Not getting over-the-top quality at half price will make me angry
WARNING: I am an entitled and bossy Harl and I will treat you like scum
ERROR: I want to speak to your manager!
Harl object destroyed
```

---

## AI Usage & Best Practices

This project was developed with AI assistance (GitHub Copilot). Here are the best practices followed:

### How AI was used:

- **Code review**: AI helped identify bugs and suggest improvements
- **Memory leak detection**: Verified with `valgrind` after AI suggestions
- **Documentation**: AI assisted in generating README documentation
- **Concept explanation**: AI explained C++ concepts (Canonical Orthodoxal, pointers vs references, member function pointers)
- **Syntax verification**: Checked C++98 compliance
- **Always understand the code**: Never copy-paste without understanding
- **Test everything**: AI suggestions were always tested manually
- **Follow the subject**: AI suggestions were adapted to match 42's requirements
- **Learn the concepts**: Used AI as a teaching tool, not just a code generator

### Key learnings from this project:

1. **Heap vs Stack**: Understanding when to use dynamic allocation
2. **Pointers vs References**: When each is appropriate
3. **Member function pointers**: Advanced C++ feature
4. **File I/O in C++**: Using streams instead of C-style file handling
5. **C++98 limitations**: Working within the standard's constraints
6. **NOTE: In CPP01 is not mandatory o use "Orthodox Canonical Class Form" o "Rule of Three/Four"**
