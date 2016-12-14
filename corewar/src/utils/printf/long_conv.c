/*
** long_conv.c for printf in /home/aurelien.olibe/delivery/PSU_2016_my_printf
**
** Made by Aurelien Olibe
** Login   <aurelien.olibe@epitech.net>
**
** Started on  Wed Nov 16 14:19:44 2016 Aurelien Olibe
** Last update Wed Nov 16 18:12:30 2016 Aurelien Olibe
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "basic.h"

char	*long_int2char_base(unsigned long int d, int bol, int *i, int base)
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

char			*lx_conv(t_farg *avs, va_list args, int base,
				 t_stockarg *store)
{
  unsigned long int	d;
  int			i;
  char			*str;
  int			bol;

  bol = 0;
  d = (unsigned long int) va_arg(args, void *);
  if ((str = long_int2char_base(d, bol, &i, base)) == NULL)
    return (str);
  store->to_free[store->k] = str;
  str = str + (i + 1);
  i = 0;
  while (avs->flag[i] != FLAG_NULL && avs->flag[i] != 1)
    i++;
  avs->flag[i] = 1;
  str = gest_flag(avs, str, 1, store);
  return (str);
}

void		put_unchar_base(unsigned char c, char *new, ssize_t *j)
{
  ssize_t	start;

  start = *j;
  new[*j] = 92;
  *j = *j + 3;
  while (c != 0)
    {
      new[*j] = ((c % 8) + 48);
      c = c - (c % 8);
      c = c / 8;
      *j = *j - 1;
    }
  while (*j != start)
    {
      new[*j] = '0';
      *j = *j - 1;
    }
  *j = *j + 3;
}

char		*unchar2char(unsigned char *str, t_stockarg *store)
{
  char		*new;
  ssize_t	i;
  ssize_t	j;

  i = 0;
  while (str[i] != '\0')
    i++;
  new = malloc(sizeof(char) * ((i * 4) + 1));
  init_str(new, (i * 4));
  i = j = 0;
  while (str[i] != '\0')
    {
      if (str[i] <= 32 || str[i] >= 127)
	put_unchar_base(str[i], new, &j);
      else
	new[j] = str[i];
      i++;
      j++;
    }
  store->to_free[store->k] = new;
  return (new);
}

char			*ls_conv(va_list args, t_stockarg *store)
{
  unsigned char		*str;
  char			*new;

  str = va_arg(args, unsigned char *);
  new = unchar2char(str, store);
  return (new);
}
