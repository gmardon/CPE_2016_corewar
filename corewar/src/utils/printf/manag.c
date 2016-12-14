/*
** manag.c for printf in /home/aurelien.olibe/delivery/PSU_2016_my_printf
**
** Made by Aurelien Olibe
** Login   <aurelien.olibe@epitech.net>
**
** Started on  Tue Nov  8 16:45:52 2016 Aurelien Olibe
** Last update Wed Nov 16 11:47:12 2016 Aurelien Olibe
*/

#include "basic.h"
#include <stdlib.h>
#include <stdarg.h>

void		clear_avs(t_farg *avs)
{
  ssize_t	i;

  i = 0;
  avs->form = 0;
  avs->modif = 0;
  avs->n_o = 0;
  while (avs->flag[i] != FLAG_NULL)
    {
      avs->flag[i] = FLAG_NULL;
      i++;
    }
}

t_farg		*init_avs(const char *format)
{
  int		i;
  ssize_t	len;
  t_farg	*avs;

  i = 0;
  len = my_strlen(format);
  if ((avs = malloc(sizeof(t_farg))) == NULL)
    return (NULL);
  if ((avs->flag = malloc(sizeof(int) * (len + 1))) == NULL)
    return (NULL);
  avs->flag[len] = FLAG_NULL;
  while (i < len)
    {
      avs->flag[i] = FLAG_NULL;
      i++;
    }
  avs->form = 0;
  avs->n_o = 0;
  avs->modif = 0;
  return (avs);
}

void	init_str(char *str, size_t max)
{
  while (max <= 0)
    {
      str[max] = '\0';
      max--;
    }
}

t_stockarg	*init_stock(const char *format)
{
  ssize_t	count;
  ssize_t	i;
  t_stockarg	*store;

  i = count = 0;
  if ((store = malloc(sizeof(t_stockarg))) == NULL)
    return (NULL);
  while (format[i] != '\0')
    {
      if (format[i] == '%')
	count++;
      i++;
    }
  store->all_arg = malloc(sizeof(char *) * (count + 1));
  store->start = malloc(sizeof(int) * (count + 1));
  store->p_len = malloc(sizeof(int) * (count + 1));
  if (store->all_arg == NULL || store->start == NULL || store->p_len == NULL)
    return (NULL);
  store->k = i = 0;
  return (init_stockarg2(store, count));
}

ssize_t		my_wtlen(char **wt)
{
  ssize_t	i;
  ssize_t	j;
  ssize_t	count;

  i = j = count = 0;
  while (wt[i] != NULL)
    {
      j = 0;
      while (wt[i][j] != '\0')
	j++;
      count = count + j;
      i++;
    }
  return (count);
}
