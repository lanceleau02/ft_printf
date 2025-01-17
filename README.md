<div align="center">

![](https://raw.githubusercontent.com/ayogun/42-project-badges/refs/heads/main/badges/ft_printfe.png)

# **ft_printf**

**Because ft_putnbr() and ft_putstr() aren’t enough.**

</div>

## Features

- Implementation of a custom version of the standard C library's `printf` function.
- Supported conversions:
    - `%c`: Print a single character.
    - `%s`: Print a string of characters.
    - `%p`: Print a pointer address in hexadecimal format.
    - `%d`: Print a decimal (base 10) integer.
    - `%i`: Print an integer (identical to %d).
    - `%u`: Print an unsigned decimal (base 10) integer.
    - `%x`: Print a number in lowercase hexadecimal format.
    - `%X`: Print a number in uppercase hexadecimal format.
    - `%%`: Print a percent sign.

## Installation

Since this project is a C library, there’s nothing to install. Simply clone the repository and include the `libftprintf.a` file in your project.

1. Clone the repository:

```bash
git clone https://github.com/lanceleau02/ft_printf.git
```

2. Navigate to the project directory:

```bash
cd ft_printf
```

3. Compile the library:

```bash
make
```

Use the `libftprintf.a` file in your own C project by linking it during compilation.

## Usage

1. Include the header file:

In your C project, include the `ft_printf.h` header file to access the functions provided by the library.

```c
#include "ft_printf.h"
```

2. Link the library:

When compiling your C project, link the `libftprintf.a` library by using the `-L` flag to specify the path to `libftprintf.a` and `-lftprintf` to link the library.
For example, if you're using `gcc`, you can compile your project like this:

```bash
gcc -o my_project my_project.c -L./ft_printf -lftprintf
```

Where:

- `-L./ft_printf` specifies the directory where `libftprintf.a` is located.
- `-lftprintf` links the library.

3. Use the functions:

Once linked, you can use any of the library functions in your code.

## License

This project is licensed under the **42 School** License.

- **Educational Use Only**: This project is intended for educational purposes at the 42 School as part of the curriculum.
- **Non-commercial Use**: The code may not be used for commercial purposes or redistributed outside of the 42 School context.
- **No Warranty**: The project is provided "as-is", without any warranty of any kind.

For more details, see the [LICENSE](https://github.com/lanceleau02/ft_printf/blob/main/LICENSE) file.

## Resources

- [printfTester](https://github.com/Tripouille/printfTester)
- [ft_printf tester](https://github.com/paulo-santana/ft_printf_tester)
- [printf Manual](https://man7.org/linux/man-pages/man3/printf.3.html)
- [stdarg Manual](https://man7.org/linux/man-pages/man3/va_arg.3.html)
