/*
** my_printf.c for my_printf in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/PSU_2016_my_printf/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Mon Nov  7 15:06:04 2016 Guillaume MARDON
** Last update Sat Nov 26 15:12:26 2016 Guillaume MARDON
*/
#include "my_printf.h"
#include <stdarg.h>
#include <stdio.h>

formatter_t	format_type[] =
{
  {'s', format_string},
  {'c', format_char},
  {'p', format_pointer},
  {'i', format_number},
  {'d', format_number},
  {'X', format_hexa},
  {'x', format_hexa},
  {'o', format_octal},
  {'b', format_binary},
  {'u', format_unsigned_number},
  {0, 0}
};

int	get_formatter_index(char c)
{
  int formatter_index;

  formatter_index = 0;
  while (format_type[formatter_index].id)
    {
			if (format_type[formatter_index].id == c)
				return (formatter_index);
      formatter_index++;
    }
  return (-1);
}

int	my_printf(const char *format, ...)
{
  const char *ptr;
	int total_writed;
  int	formatter_index;
  va_list	args;

  va_start(args, format);
  ptr = format;
  total_writed = 0;
  while (*ptr != '\0')
    {
      if (*ptr != '%')
				my_putchar(*ptr);
      else
				{
				  ptr++;
          formatter_index = get_formatter_index(*ptr);
          if (formatter_index == -1)
            {
              my_putchar('%');
              my_putchar(*ptr);
            }
          else
              total_writed += format_type[formatter_index].fmt(ptr, args);
				}
      total_writed++;
      ptr++;
    }
	return (0);
}
