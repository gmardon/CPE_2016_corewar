/*
** basic.c for emacs in /home/aurelien.olibe/delivery/PSU_2016_my_printf
**
** Made by Aurelien Olibe
** Login   <aurelien.olibe@epitech.net>
**
** Started on  Mon Nov  7 20:38:05 2016 Aurelien Olibe
** Last update Mon Nov 14 14:25:28 2016 Aurelien Olibe
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "basic.h"

int		my_printf(const char *format, ...)
{
  va_list	args;
  t_farg	*avs;
  t_stockarg	*store;
  int		i;

  va_start(args, format);
  if ((avs = init_avs(format)) == NULL || (store = init_stock(format)) == NULL)
    return (-1);
  i = 0;
  while (format[i] != '\0')
    {
      if (format[i] == '%')
	{
	  store->start[store->k] = i;
	  percent(format, &i, avs);
	  store->p_len[store->k] = (i + 1) - store->start[store->k];
	  store->all_arg[store->k] = fmanag(avs, args, store, format);
	  clear_avs(avs);
	  store->k++;
	}
      i++;
    }
  va_end(args);
  free_avs(avs);
  return (gen_string(store, format));
}

void		gen_string2(t_stockarg *store, ssize_t *i, ssize_t *j,
			    char *str)
{
  ssize_t	l;

  l = 0;
  *i = *i + store->p_len[store->k] - 1;
  while (store->all_arg[store->k][l] != '\0')
    {
      str[*j] = store->all_arg[store->k][l];
      l = l + 1;
      *j = *j + 1;
    }
  *j = *j - 1;
  store->k++;
}

ssize_t		gen_string(t_stockarg *store, const char *format)
{
  ssize_t	i;
  ssize_t	j;
  ssize_t	l;
  char		*str;
  ssize_t	max;

  i = j = store->k = l = max = 0;
  max = (my_strlen(format) + my_wtlen(store->all_arg) - intlen(store->p_len));
  if ((str = malloc(sizeof(char) * (max + 1))) == NULL)
    return (-1);
  while (format[i] != '\0')
    {
      if (store->start[store->k] == i && store->all_arg[store->k] != NULL)
	gen_string2(store, &i, &j, str);
      else
	str[j] = format[i];
      i++;
      j++;
    }
  write(1, str, max);
  free(str);
  free_store(store);
  if (format[i] == '\0' && format[i - 1] == '%')
    return (-1);
  return (max);
}

void	percent(const char *format, int *i, t_farg *avs)
{
  int	k;
  int	old_k;
  int	nothing;

  k = old_k = 0;
  *i = *i + 1;
  nothing = 1;
  while (avs->form == 0 && format[*i] != '\0')
    {
      old_k = k;
      if ((avs->flag[k] = flags(format[*i])) > 0)
	k++;
      if ((avs->modif = modifiers(format[*i], format[*i + 1])) > 0)
        nothing = 0;
      avs->form = format1(format[*i]);
      if (avs->n_o == 0)
	avs->n_o = numeric(format, i);
      if (nothing == 1 && avs->form == 0 && (old_k == k))
        if (numeric(format, i) == 0)
          break;
      *i = *i + 1;
      nothing = 1;
    }
  flag_sort(avs);
  *i = *i - 1;
}
