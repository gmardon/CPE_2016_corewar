/*
** char_conv.c for printf in /home/aurelien.olibe/delivery/PSU_2016_my_printf
**
** Made by Aurelien Olibe
** Login   <aurelien.olibe@epitech.net>
**
** Started on  Fri Nov 11 18:30:36 2016 Aurelien Olibe
** Last update Mon Nov 14 12:52:52 2016 Aurelien Olibe
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "basic.h"

char	*c_conv(va_list args, t_stockarg *store)
{
  char	*str;

  if ((str = malloc(sizeof(char) * 2)) == NULL)
    return (str);
  store->to_free[store->k] = str;
  str[0] = va_arg(args, int);
  str[1] = '\0';
  return (str);
}

char	*s_conv(va_list args)
{
  char	*str;

  str = va_arg(args, char *);
  return (str);
}
