/*
** new_forest.c for printf in /home/aurelien.olibe/delivery/PSU_2016_my_printf
**
** Made by Aurelien Olibe
** Login   <aurelien.olibe@epitech.net>
**
** Started on  Fri Nov 11 18:26:14 2016 Aurelien Olibe
** Last update Wed Nov 16 18:16:43 2016 Aurelien Olibe
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "basic.h"

char	*no_form(t_stockarg *store)
{
  store->start[store->k] = INT_NULL;
  store->p_len[store->k] = INT_NULL;
  store->k--;
  return (NULL);
}

char	*perc(t_stockarg *store)
{
  char	*str;

  if ((str = malloc(sizeof(char) * 2)) == NULL)
    return (str);
  str[0] = '%';
  str[1] = '\0';
  store->to_free[store->k] = str;
  return (str);
}

char	*is_nothing()
{
  char	*str;

  if ((str = malloc(sizeof(char) * 1)) == NULL)
    return (str);
  str[0] = '\0';
  return (str);
}

char *fmanag2(t_farg *avs, va_list args, t_stockarg *store)
{
  if (avs->form == 18)
    return (ls_conv(args, store));
  else if (avs->form == 19)
    return (lx_conv(avs, args, 16, store));
  else
    return (NULL);
}

char	*fmanag(t_farg *avs, va_list args, t_stockarg *store,
		const char *format)
{
  if (avs->form == 0 && (format[store->start[store->k] + 1] == '\0'))
    return (is_nothing());
  else if (avs->form == 1)
    return (d_conv(avs, args, store));
  else if (avs->form == 3)
    return (udx_conv(avs, args, 8, store));
  else if (avs->form == 4)
    return (udx_conv(avs, args, 10, store));
  else if (avs->form == 5)
    return (udx_conv(avs, args, 16, store));
  else if (avs->form == 6)
    return (udx_conv(avs, args, -16, store));
  else if (avs->form == 15)
    return (c_conv(args, store));
  else if (avs->form == 16)
    return (s_conv(args));
  else if (avs->form == 22)
    return (udx_conv(avs, args, 2, store));
  else if (avs->form == 23)
    return (perc(store));
  else if (avs->form == 0)
    return (no_form(store));
  else
    return (fmanag2(avs, args, store));
}
