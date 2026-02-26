*This project has been created as part of the 42 curriculum by masacco.*
***
# 📚 GET_NEXT_LINE
***
## Table of Contents
1. [Description](#Description)
2. [Instructions](#Instructions)
3. [Resources](#Resources)
4. [Structure](#Structure)
***
## 📝 Description
The get_next_line project is a project that involves creating a function capable of reading a line ending with a newline character (\n) from a file descriptor.

### Goal
The primary objective is to learn about static variables in C and to understand how memory allocation works when the size of the input is unknown. The function must be memory-efficient and handle multiple file descriptors without losing the reading thread.

### Key Features
- Reads from a file descriptor (file, standard input, etc.).
- Returns one line at a time.
- Works with a customizable BUFFER_SIZE defined at compilation.
- Manages memory diligently to avoid leaks.

---
## 🛠️ Instructions
To compile the project, you need to include the source files and define the BUFFER_SIZE. Use the following command:
```
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

```


## 🤖 Resources
- Understanding how files are handled in C.
- A guide on how static variables retain state.
- Official man pages for dynamic memory allocation.

## 🔗 Structure
The project is organized as follows:

### Mandatory Files
get_next_line.c: The main logic of the function.

get_next_line_utils.c: Helper functions (strlen, strjoin, strchr, bzero) required for string manipulation.

get_next_line.h: The header file containing function prototypes and necessary macros.

### Bonus Files
get_next_line_bonus.c: An enhanced version of the main logic. Unlike the mandatory version, this implementation uses an array of pointers or a linked list to manage multiple file descriptors.

get_next_line_bonus.h: The header for the bonus part, designed to support the multi-fd architecture.

get_next_line_utils_bonus.c: Specific utility functions optimized for the bonus requirements, ensuring that switching between different files doesn't lose the reading progress of any individual stream.
