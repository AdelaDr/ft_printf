*This project has been created as part of the 42 curriculum by adrahoto.*

[![C](https://img.shields.io/badge/language-C-555?style=flat&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![42 Project](https://img.shields.io/badge/42-Libft-blue)](https://www.42.fr)

# Table of Contents
- [Description](#description)
- [Instructions](#instructions)
- [Resources](#resources)
- [Feature list](#feature-list)
- [Usage Example](#usage-example)
- [Technical Choices](#technical-choices)

# Description
This project is a reimplementation of the standard C `printf` function. The goal is to understand how formatted output works at a low level by recreating its core behavior using only allowed system calls and standard C features.

The custom `ft_printf` function parses a format string, handles variadic arguments, and prints formatted output to standard output. It supports multiple format specifiers, such as characters, strings, signed and unsigned integers, hexadecimal numbers (both lowercase and uppercase), and memory addresses.

The project emphasizes:

- Working with variadic functions using `va_list`

- Parsing format strings manually

- Converting and printing different data types without using libc formatting functions

- Writing clean, modular, and reusable C code

This implementation serves as both a functional replacement for a subset of `printf` and a learning exercise in low-level I/O, recursion, and type handling in C.

# Instructions
## Automatic Compilation
Clone and compile:
```bash
git clone https://github.com/AdelaDr/ft_printf.git libftprintf
cd libftprintf
make
```

Generates `libftprintf.a` automatically.

## Usage in Projects

Include the header and link the library:

```bash
#include "libftprintf.h"
```

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o my_program
```

# Resources

- [C Standard Library Docs](https://man7.org/linux/man-pages/man3/)

- [W3Schools](https://www.w3schools.com)

- [TutorialsPoint](https://www.tutorialspoint.com)

- AI assistance: used for structuring code, logic explanation, and optimization suggestions, not direct function implementation.

# Feature List

Reimplementation of the `printf` function as `ft_printf`

- **Support for multiple format specifiers:**

    - `%c` – character

    - `%s` – string

    - `%d` / `%i` – signed integer

    - `%u` – unsigned integer

    - `%x` – lowercase hexadecimal

    - `%X` – uppercase hexadecimal

    - `%p` – pointer address

    - `%%` – literal percent sign

- Correct handling of variadic arguments using `va_list`

- Manual conversion of integers to decimal and hexadecimal representations

- Pointer address formatting with `0x` prefix

- Output written directly to standard output using `write`

- Return value matching the behavior of the original `printf` (number of printed characters)

- Modular implementation with separated helper functions for each conversion type

# Usage Example

```bash
#include "libftprintf.h"

ft_printf("Value: %d, Hex: %x, Pointer: %p\n", 42, 42, ptr);
```

# Technical Choices

- **Variadic Arguments Handling**
The implementation uses `va_list`, `va_start`, `va_arg`, and `va_end` from `<stdarg.h>` to access and process arguments dynamically.

- **Manual Parsing of Format String**
The format string is iterated character by character. When a `%` is encountered, the following character determines which conversion function is called.

- **Modular Design**
Each format specifier is handled by a dedicated function (e.g., integer printing, hexadecimal conversion, pointer handling). This improves readability and maintainability.

- **Recursive / Iterative Number Conversion**
Integer and hexadecimal conversions are implemented manually without using standard formatting functions. Base conversion logic is implemented using recursion or iterative division by base.

- **Low-Level Output**
The `write` system call is used for output to comply with project restrictions and to better understand low-level I/O behavior.

- **Character Count Tracking**
A counter is maintained to correctly return the total number of printed characters, matching the behavior of the original `printf`.

- **Error Handling Strategy**
The implementation ensures defined behavior for supported format specifiers and respects project constraints regarding undefined behavior.