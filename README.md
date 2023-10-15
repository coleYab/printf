# _printf  - one of the greatest functions of C.
## DESCRIPTION

The `_printf( )` function writes to stdout the arguments that make up the argument list as specified by the string pointed to by format. The `_printf( )` function returns the number of characters actually printed. A negative value is returns if it fails to print.

## FORMAT SPECIFIERS

The FORMAT argument is a string that may contain format specifiers, each beginning with a '%' character, followed by a specifier character.

- `%s`: Prints a string to the std output if no string is passed prints null insted of the sting.

- `%d`: Print a an integer in base 10.

- `%c`: Print a character that is passed by the user.

- `%%`: Print the '%' sign to the std output.

- `%r` : Prints a reverse of a string to the stdout.

- `%R` : Prints a string in Rot 13 version.

- `%b` : Prints the binary representation of a number.

- `%x` : Prints the hexadecimal representation of a number in lower case.

- `%X` : Prints the hexadecimal representation of a number in upper case.

- `%u` : Prints unsigned integer to the stdout.

- `%p` : Prints the memory location of a variable.

- `%S` : Prints a string after converting non printable char to their ascii value.

## ARGUMENTS

`_printf` takes one mandatory argument and other optional variadic arguments. This function requires a mandatory argument which is consists of a format specifier telling what `_printf` to extract from the argument list.

## EXAMPLES

1. Print a string and a number:
```c
#include "main.h"

int main(void)
{
    char str[] = "Name";
    int num = 12;
    const char \*format = "Hello %s you are %d years old.";

    printf(format, str age);

    return (0);
}
```

This code will result the following out put.
```
Hello Name you are 12 years old.
```
2. Print a reverse and rot 13 string:

```c
#include "main.h"

int main(void)
{
    char *str;
    char *str1;

    str = "Rotate string";
    str1 = "Reverse";
    _printf("ROT 13 of %s == %R\n", str, str);
    _printf("Reverse of %s == %r", str1, str1);

    return (0);
}
```
The output resulted will be:
```
ROT 13 of Rotate string == Ebgngr fgevat
Reverse of Reverse == esreveR
```

## AUTHORS

The `_printf` function was written by Farida Alshaama and Yeabsira Moges.

## REPORTING BUGS

You can report bugs for maintainancd by the following email adresses.

Yeabsira Moges - yabume123@gmail.com

Farida Alshaama - faridaalshamaa@gmail.com

## DISCLAIMER

This is a simplified man page for the `_printf` command and may not cover all options or behaviors. Refer to the official documentation of `printf` function for more details.

