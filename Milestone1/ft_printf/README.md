This project has been created as part of the 42 curriculum by masacco.
***
# 📚 FT_PRINTF
***
## Table of Contents
1. [Description](#Description)
2. [Instructions](#Instructions)
3. [Resources](#Resources)
4. [Structure](#Structure)
***
## 📝 Description
The **ft_printf** project is a fundamental challenge in the 42 school. The objective is to recode the standard C library `printf` function. This project is crucial as it introduces the concept of **variadic functions** in C and reinforces the understanding of character output and string manipulation.

The goal is to create a library that contains the function `ft_printf`, which mimics the original's ability to format and print data to the standard output.

The function handles the following format specifiers:
* `%c` Prints a single character.
* `%s` Prints a string.
* `%p` The void * pointer argument has to be printed in hexadecimal format.
* `%d` Prints a decimal (base 10) number.
* `%i` Prints an integer in base 10.
* `%u` Prints an unsigned decimal (base 10) number.
* `%x` Prints a number in hexadecimal (base 16) lowercase format.
* `%X` Prints a number in hexadecimal (base 16) uppercase format.
* `%%` Prints a percent sign.

---
## 🛠️ Instructions
The project is managed by a `Makefile` which compiles the source files into a static library `libftprintf.a`. 

To compile, navigate to the project root and run:
```bash
make

```
## 🤖 Resources
Man printf(3): The official documentation for the standard function.
Variadic Functions in C: Understanding stdarg.h.

## 🔗 Structure

The project is organized into modular functions, each responsible for a specific part of the formatting process:

| Function | Purpose |
| :--- | :--- |
| `ft_printf` | Main entry point; parses the format string and dispatches tasks. |
| `ft_putchar` | Handles the `%c` specifier and prints single characters. |
| `ft_putstr` | Handles the `%s` specifier and prints strings. |
| `ft_putnbr` | Manages the conversion and display of integers (`%d`, `%i`) and unsigned (`%u`). |
| `ft_hex` | Converts and prints numbers in hexadecimal base for `%x` and `%X`. |
| `ft_pointer` | Handles the `%p` specifier, printing memory addresses in hex format. |