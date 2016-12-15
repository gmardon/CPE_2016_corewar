/*
** alphabetic_format.c for my_printf in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/PSU_2016_my_printf/formats/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Sun Nov 13 21:33:07 2016 Guillaume MARDON
** Last update Wed Nov 23 15:16:38 2016 Guillaume MARDON
*/
#include "../my_printf.h"

int	format_string(const char *ptr, va_list args)
{
  char	*str;

  str = va_arg(args, char *);
  my_putstr(str);
  return (my_strlen(str));
}

int	format_special_string(const char *ptr, va_list args)
{
  char	*str;

  str = va_arg(args, unsigned char *);
  my_putstr(str);
  return (my_strlen(str));
}

int	format_char(const char *ptr, va_list args)
{
  char	c;

  c = va_arg(args, int);
  my_putchar(c);
  return (1);
}
