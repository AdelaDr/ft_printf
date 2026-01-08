*This project has been created as part of the 42 curriculum by adrahoto.*

[![C](https://img.shields.io/badge/language-C-555?style=flat&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![42 Project](https://img.shields.io/badge/42-Libft-blue)](https://www.42.fr)

# Table of Contents
- [Description](#description)
- [Instructions](#instructions)
- [Resources](#resources)
- [Library Details](#library-details)
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
gcc -Wall -Wextra -Werror main.c libftprintf.a -o my_program
```
