/*
** alphabetic_format.h for my_printf in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/PSU_2016_my_printf/formats/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Sun Nov 13 21:33:07 2016 Guillaume MARDON
** Last update Sun Dec 18 18:31:44 2016 John Doe
*/
#ifndef _ALPHA_FORMAT_H
# define _ALPHA_FORMAT_H

int	format_string(const char *ptr, va_list args);
int	format_special_string(const char *ptr, va_list args);
int	format_char(const char *ptr, va_list args);

#endif
