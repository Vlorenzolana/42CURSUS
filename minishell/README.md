# Minishell
```bash

./minishell
 )(  ) ##   ##  ###  ##   ##  ###        (  )( 
(  )(  ### ###   #   ###  ##   #          )(  )
 )(  ) ## # ##   #   #### ##   #         (  )( 
(  )(  ##   ##   #   ## ####   #          )(  )
 )(  ) ##   ##  ###  ##   ##  ###        (  )( 
 )(  ) █████  █   █  █████  █      █      )(  )
(  )(  █      █   █  █      █      █     (  )( 
 )(  ) █████  █████  █████  █      █      )(  )
(  )(      █  █   █  █      █      █     (  )( 
 )(  ) █████  █   █  █████  █████  █████  )(  )

minishell>> echo as beautiful as a seashell
minishell>> as beautiful as a seashell

´´´

This project is a simplified Unix shell developed in C. It replicates the basic behavior of Bash: command input, parsing, execution, redirections, pipes, environment variables, built-ins, and signal handling. The goal is to understand how a shell works internally and manage memory, file descriptors, and system calls at a low level.

## Features

- Prompt and line reading
- Command parsing with support for:
  - Quotes (`'`, `"`)
  - Pipes (`|`)
  - Redirections (`>`, `>>`, `<`, `<<`)
  - Environment variable expansion (`$VAR`, `$?`)
- Execution of system binaries and built-in commands
- Built-ins implemented:
  - `echo`
  - `cd`
  - `pwd`
  - `export`
  - `unset`
  - `env`
  - `exit`
- Heredocs (`<<`) with temporary file management
- Signal handling (`SIGINT`, `SIGQUIT`, etc.)
- History support via readline

## Requirements

- GCC and Make
- GNU Readline library

## Compilation

```bash
make

## Running the Shell

./minishell

Use the prompt to enter commands like you would in Bash. To exit:

exit

## Examples

echo "Hello World"
ls -l | grep txt > result.txt
cat < result.txt
export NAME=Vanessa
echo $NAME

## File Structure

    src/ – Source files grouped by logic (parsing, execution, utils...)

    inc/ – Header files

    libft/ – Custom implementation of common C library functions

    Makefile – Compilation rules

    .minishell_history – Saved command history (created at runtime)
    
# Installation

## Compilation: Make rules

Compile the project by running `make` in your Terminal. The following rules are also available:

| Command            | Description                                                 |
|--------------------|-------------------------------------------------------------|
| `make`             | Compiles the project and generates the `minishell` binary.  |
| `make re`          | Equivalent to `fclean` followed by `make`.                  |
| `make run`         | Equivalent to `fclean` followed by `make re` and ./minishell|
| `make gdb`         | Compiles the project with debugging symbols (`-g3`).        |
| `make valgrind`    | Compiles with `-g3` and flags useful for running Valgrind.  |
| `make clean`       | Removes `.o` files.                                         |
| `make fclean`      | Removes executables and `.o` files.                         |
|--------------------|-------------------------------------------------------------|
---

## Execution: how to use our mini

Once compiled, you can start the minishell with:

```bash
make run
```

or

```bash
./minishell
```

## Made with elove by

Dalabrad
Vlorenzolana
