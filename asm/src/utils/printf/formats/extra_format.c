/*
** extra_format.c for my_printf in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/PSU_2016_my_printf/formats/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Thu Nov 17 11:29:31 2016 Guillaume MARDON
** Last update Sun Nov 27 16:01:28 2016 Guillaume MARDON
*/
#include "../my_printf.h"

int	format_pointer(const char *ptr, va_list args)
{
  size_t i;
  char *str;

  i = va_arg(args, size_t);
  str = malloc((my_nbrlen(i, 16) - 1) * sizeof(char*));
  my_itoa(i, str, 16);
  my_putstr("0x");
  my_putstr(str);
  return (2 + (my_nbrlen(i, 16) - 1) * sizeof(char*));
}
