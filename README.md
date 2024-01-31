<h1 align="center">
ft_printf
</h1>

<p align="center">
printf() recoded
</p>

ft_printf is a custom implementation of the printf() function written in the C language.
This project serves as an exploration of variadic functions through the handling of variable arguments such as the printf()'s format specifiers.

| Format  | Description                                                |
|---------|------------------------------------------------------------|
| `%c`    | Prints a single character.                                 |
| `%s`    | Prints a string (as defined by the common C convention).  |
| `%p`    | Prints a void * pointer in hexadecimal format.             |
| `%d`    | Prints a decimal (base 10) number.                         |
| `%i`    | Prints an integer in base 10.                              |
| `%u`    | Prints an unsigned decimal (base 10) number.               |
| `%x`    | Prints a number in hexadecimal (base 16) lowercase.       |
| `%X`    | Prints a number in hexadecimal (base 16) uppercase.       |
| `%%`    | Prints a percent sign.                                     |

**Bonus Features:**
- Manages any combination of the following flags: `'-0.'` and the field minimum width under all conversions.
- Manages all the following flags: `'# + '` (Yes, one of them is a space).

