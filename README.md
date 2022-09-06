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
