/*
** numeric_format.h for my_printf in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/PSU_2016_my_printf/formats/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Sun Nov 13 21:19:38 2016 Guillaume MARDON
** Last update Sun Dec 18 18:32:59 2016 John Doe
*/
#ifndef _NUM_FORMAT_H
# define _NUM_FORMAT_H

int	format_number(const char *ptr, va_list args);
int	format_unsigned_number(const char *ptr, va_list args);
int	format_hexa(const char *ptr, va_list args);
int	format_octal(const char *ptr, va_list args);
int	format_binary(const char *ptr, va_list args);

#endif
