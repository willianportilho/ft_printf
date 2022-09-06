<h1 align="center"> ft_printf </h1>

<p align="center"> A 42 project written in C language</p>

<p align="center">
  <img alt="status completed" src="https://img.shields.io/badge/STATUS-COMPLETED-green">
  <img alt="made with c language" src="https://img.shields.io/badge/MADE%20WITH-C-blue">
</p>

---

## Introduction

This project had the purpose to replicate the printf function, which belongs to &lt;stdio.h&gt; lib, and learning about **_variadic functions_** in C.

---

### Explanation
This mimic encompasses the following conversions: <br>
`%c` - Prints a single ASCII character; <br>
`%s` - Prints a string; <br>
`%p` - Prints the void *pointer argument in hexadecimal format; <br>
`%d` - Prints a decimal _(base 10)_ number; <br>
`%i` - Prints an integer _(base 10)_ number; <br>
`%u` - Prints an unsigned decimal _(base 10)_ number; <br>
`%x` - Prints a number in hexadecimal _(base 16)_ _lowercase_ format. <br>
`%X` - Prints a number in hexadecimal _(base 16)_ _UPPERCASE_ format. <br>
`%%` - Prints a percent sign _(%)_. <br>

---

### Example

_Original function:_
``` c
#include <stdio.h>

int	main(void)
{
  int	num;

  num = 10;
  printf("Hello, World!\n");
  printf("num: %d\n", num);
  return (0);
}
```

_Replica:_
``` c
#include "./inc/ft_printf.h"

int	main(void)
{
  int	num;

  num = 10;
  ft_printf("Hello, World!\n");
  ft_printf("num: %d\n", num);
  return (0);
}
```
_Both outputs:_
```
Hello, World!
num = 10
```

## 🛠️ Usage
<p> For use this lib, follow these steps:</p>

- Clone this repository:
```
https://github.com/willianportilho/ft_printf.git
```

- `make` for compiling the libftprintf.a.

- Include this header on you code:
``` c
#include "./ft_printf.h"
```
_*If necessary, change the location. Remember that the include location depends on where your another files are._


- Finally, compile the program whith this line:
```
gcc your_program_here.c libftprintf.a -o name_of_you_choice_here
```
_or:_
```
gcc your_program_here.c -L. -lftprintf -o name_of_you_choice_here
```
_*If necessary, change the location. Remember that the libftprintf.a location depends on where your file program are._

## 🤖 Makefile Commands
- `make` to create *.o objects and compile the libftprintf.a;
- `make bonus` to include bonus functions (lists) in the libftprintf.a;
- `make clean` to erase *.o objects;
- `make fclean` to erase *.o objects and libftprintf.a;
- `make re` to erase *.o objects and libftprintf.a, and recriate *.o and libftprintf.a;
