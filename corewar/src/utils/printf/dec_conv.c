/*
** dec_conv.c for printf in /home/aurelien.olibe/delivery/PSU_2016_my_printf
**
** Made by Aurelien Olibe
** Login   <aurelien.olibe@epitech.net>
**
** Started on  Thu Nov 10 15:30:30 2016 Aurelien Olibe
** Last update Sat Nov 19 00:51:50 2016 Aurelien Olibe
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "basic.h"

char	*int2char_base(unsigned int d, int bol, int *i, int base)
{
  char	*str;

  if (base == -16)
    {
      bol = 1;
      base = base * -1;
    }
  if ((str = malloc(sizeof(char) * (12 * 4))) == NULL)
    return (str);
  str[47] = '\0';
  *i = 46;
  init_str(str, (*i + 1));
  while (d != 0)
    {
      if ((d % base) < 10)
	str[*i] = (d % base) + '0';
      else if ((d % base) >= 10 && bol == 0)
	str[*i] = (d % base) + ('a' - 10);
      else if ((d % base) >= 10 && bol == 1)
	str[*i] = (d % base) + ('A' - 10);
      d = d - (d % base);
      d = d / base;
      *i = *i - 1;
    }
  return (str);
}

char		*udx_conv(t_farg *avs, va_list args, int base,
			  t_stockarg *store)
{
  unsigned int	d;
  int		i;
  char		*str;
  int		bol;

  bol = 0;
  d = va_arg(args, int);
  if ((str = int2char_base(d, bol, &i, base)) == NULL)
    return (str);
  store->to_free[store->k] = str;
  str = str + (i + 1);
  str = gest_flag(avs, str, d, store);
  return (str);
}


char	*int2char(int d, int *i, t_stockarg *store)
{
  char	*str;

  if ((str = malloc(sizeof(char) * 12)) == NULL)
    return (str);
  store->to_free[store->k] = str;
  str[11] = '\0';
  *i = 10;
  init_str(str, (*i + 1));
  while (d != 0)
    {
      if (d == -2147483648)
      {
        d = (d + 1) * -1;
        str[*i] = ((d % 10) + 1) + '0';
      }
      else
        str[*i] = (d % 10) + '0';
      d = d - (d % 10);
      d = d / 10;
      *i = *i - 1;
    }
  return (str);
}

char	*d_conv(t_farg *avs, va_list args, t_stockarg *store)
{
  int	d;
  int	i;
  int	neg;
  char	*str;

  d = va_arg(args, int);
  neg = 0;
  if (d < 0)
    {
      neg = 1;
      d = d * -1;
    }
  if ((str = int2char(d, &i, store)) == NULL)
    return (str);
  if (neg)
    {
      str[i] = '-';
      str = str + i ;
    }
  else
    str = str + (i + 1);
  str = gest_flag(avs, str, 0, store);
  return (str);
}
