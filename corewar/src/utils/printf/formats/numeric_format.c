/*
** numeric_format.c for my_printf in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/PSU_2016_my_printf/formats/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Sun Nov 13 21:19:38 2016 Guillaume MARDON
** Last update Sun Nov 27 16:08:31 2016 Guillaume MARDON
*/
#include "../my_printf.h"

int	format_number(const char *ptr, va_list args)
{
  int i;
  char *str;

  i = va_arg(args, int);
  str = malloc((my_nbrlen(i, 16) - 1) * sizeof(char*));
  my_itoa(i, str, 10);
  my_putstr(str);
  return ((my_nbrlen(i, 16) - 1) * sizeof(char*));
}

int	format_unsigned_number(const char *ptr, va_list args)
{
  unsigned int i;
  char *str;
  
  i = va_arg(args, unsigned int);
  str = malloc((my_nbrlen(i, 10)) * sizeof(char*));
  my_itoa(i, str, 10);
  str[ (my_nbrlen(i, 10))] = 0;
  my_putstr(str);
  return ((my_nbrlen(i, 10)) * sizeof(char*));
}

int	format_hexa(const char *ptr, va_list args)
{
  int i;
  char *str;

  i = va_arg(args, int);
  str = malloc((my_nbrlen(i, 16) - 1) * sizeof(char*));
  my_itoa(i, str, 16);
  my_putstr(*ptr == 'X' ? my_strlowcase(str) : str);
  return ((my_nbrlen(i, 16) - 1) * sizeof(char*));
}

int	format_octal(const char *ptr, va_list args)
{
  int i;
  char *str;

  i = va_arg(args, int);
  str = malloc((my_nbrlen(i, 16) - 1) * sizeof(char*));
  my_itoa(i, str, 8);
  my_putstr(str);
  return ((my_nbrlen(i, 16) - 1) * sizeof(char*));
}

int	format_binary(const char *ptr, va_list args)
{
  int i;
  char *str;

  i = va_arg(args, int);
  str = malloc((my_nbrlen(i, 16) - 1) * sizeof(char*));
  my_itoa(i, str, 2);
  my_putstr(str);
  return ((my_nbrlen(i, 16) - 1) * sizeof(char*));
}
