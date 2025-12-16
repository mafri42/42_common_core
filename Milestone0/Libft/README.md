This project has been created as part of the 42 curriculum by masacco.
***
# 📚 LIBFT
***
## Table of Contents
1. [Description](#Description)
2. [Instructions](#Instructions)
3. [Resources](#Resources)
4. [Structure](#Structure)

---

## 📝 Description

The **`libft`** project is the first major task in the 42 curriculum. Its primary **goal** is to implement a personal static C library (`libft.a`) containing a diverse collection of self-written functions.

The project requires recreating many essential standard C library (`libc`) functions and developing several useful utility functions (like string splitting, number-to-string conversion, and linked list management).

* **Memory Mastery:** Confirms proficiency in dynamic memory allocation (`malloc`/`free`) and manipulation (`memcpy`, `memmove`).
* **String Handling:** Provides expertise in the core mechanics of null-terminated strings.
* **Code Structure:** Teaches the proper methods for creating, compiling, and linking a reusable **static library**.

---

## 🛠️ Instructions

To compile the library, navigate to the root directory and use the provided `Makefile`:

```bash
make
```
This command will compile all source files (.c) into object files (.o) and archive them into the static library file: libft.a.

Compile your program and link the library using the following command:
```bash
cc -Wall -Wextra -Werror -lbsd your_file.c libft.a
```
---

## 🤖 Resources

The official Man Pages for standard C library functions (man 3 <function_name>) were the definitive source for understanding expected behavior and return values.


## 🔗 Structure

The libft.a contains over 50 functions, categorized by their purpose:

| Category | Functions (Examples) | Description |
| :--- | :--- | :--- |
| **Character Testing** | `ft_isalpha`, `ft_isdigit`, `ft_isprint` | Tests if a character belongs to a specific type. |
| **Memory Manipulation** | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove` | Fills, clears, copies, or safely moves memory blocks. |
| **String Utilities** | `ft_strlen`, `ft_strdup`, `ft_strnstr`, `ft_atoi` | Calculates length, duplicates, searches, and converts strings to integers. |

### Part 2: Additional Utility Functions

| Function | Purpose |
| :--- | :--- |
| `ft_substr` | Returns a new string from a given start index and length. |
| `ft_strjoin` | Concatenates two strings into a new, dynamically allocated one. |
| `ft_strtrim` | Trims specified characters from the start and end of a string. |
| `ft_split` | **Splits** a string into an array of strings using a delimiter. |
| `ft_itoa` | Converts an integer (`int`) into its string representation. |
| `ft_put..._fd` | Writes characters, strings, or numbers to a specified **file descriptor** (`0`, `1`, `2`). |
| `ft_str...i` | Iterates through a string to apply a function, optionally passing the index. |

### Linked Lists

These functions are used to manage and manipulate the structure `t_list`. 

| Function(s) | Purpose |
| :--- | :--- |
| `ft_lstnew` | Creates and returns a new list element (node). |
| `ft_lstadd_front` | Adds a new element to the beginning of the list. |
| `ft_lstadd_back` | Adds a new element to the end of the list. |
| `ft_lstsize`, `ft_lstlast` | Counts the number of elements or retrieves the pointer to the last element. |
| `ft_lstdelone` | Takes one element, frees its content, and frees the element itself. |
| `ft_lstclear` | Frees all the memory associated with the list (content and elements) starting from a given head. |
| `ft_lstiter` | Applies a specific function to the content of every element in the list. |
| `ft_lstmap` | Applies a function to the content of every element and creates a **new list** with the results. |