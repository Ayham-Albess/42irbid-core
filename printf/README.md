*This activity has been created as part of the 42 curriculum by aalbess*

# ft_printf

## Description
`ft_printf` is a custom implementation of the C standard library function `printf`.
The goal of this project is to handle formatted output, variadic arguments,
and reproduce the behavior of the original `printf` function.

---

## Supported Conversions
The following format specifiers are implemented:

- `%c` : Print a single character
- `%s` : Print a string
- `%d` / `%i` : Print a signed integer
- `%u` : Print an unsigned integer
- `%x` : Print a number in lowercase hexadecimal
- `%X` : Print a number in uppercase hexadecimal
- `%p` : Print a pointer address in hexadecimal format
- `%%` : Print a percent sign

---

## Project Structure

├── ft_printf.c
├── ft_printf_str.c
├── ft_printf_int.c
├── ft_printf_hex.c
├── ft_printf_point.c
├── ft_printf.h
├── Makefile
└── README.md

---

## Algorithm

The algorithm scans the format string character by character:
1-Print normal characters directly.
2-When % is encountered, identify the format specifier.
3-Retrieve the corresponding argument using va_arg.
4-Convert and print the argument based on its type.
5-Count and return the total number of printed characters.

---

## Justification

-Single-pass parsing ensures efficiency.
-Each format specifier is handled by a dedicated function.
-Minimal memory usage and no unnecessary allocations.

---

## Data Structures

-va_list for handling variadic arguments.
-Primitive data types and strings.
-Recursive or iterative number conversion for base handling.

---

## Resources

-42 pages
-GNU C Library Documentation
-man 3 printf

---

### Compilation

To compile the project, run:

```bash
make
