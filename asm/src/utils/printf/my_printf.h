/*
** my_printf.c for my_printf in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/PSU_2016_my_printf/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Mon Nov  7 15:06:04 2016 Guillaume MARDON
** Last update Tue Nov 29 16:36:07 2016 Guillaume MARDON
*/
#include "../../../include/asm.h"

#include <stdarg.h>
#include <stdlib.h>

int my_printf(const char *format, ...);

typedef struct		formatter_s
{
  char			id;
  int 			(*fmt)(const char*, va_list);
}			formatter_t;

#include "formats/extra_format.h"
#include "formats/numeric_format.h"
#include "formats/alphabetic_format.h"
