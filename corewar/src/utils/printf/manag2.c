/*
** manag2.c for printf in /home/aurelien.olibe/delivery/PSU_2016_my_printf
**
** Made by Aurelien Olibe
** Login   <aurelien.olibe@epitech.net>
**
** Started on  Sat Nov 12 15:52:00 2016 Aurelien Olibe
** Last update Mon Nov 14 16:15:38 2016 Aurelien Olibe
*/
#include "basic.h"
#include <stdlib.h>
#include <stdarg.h>

ssize_t		intlen(int *tab)
{
  ssize_t	i;
  ssize_t	count;

  i = count = 0;
  while (tab[i] != INT_NULL)
    {
      count = count + tab[i];
      i++;
    }
  return (count);
}

void	sort(t_farg *avs, ssize_t *i, int bol, int nb)
{
  if (bol)
    {
      avs->flag[*i] = nb;
      *i = *i + 1;
    }
}

t_stockarg	*init_stockarg2(t_stockarg *store, ssize_t count)
{
  ssize_t	i;

  i = 0;
  while (i <= count)
    {
      store->all_arg[i] = NULL;
      store->start[i] = INT_NULL;
      store->p_len[i] = INT_NULL;
      i++;
    }
  if ((store->to_free = malloc(sizeof(char *) * (count + 1))) == NULL)
    return (NULL);
  while (i < count)
    {
      store->to_free[i] = NULL;
      i++;
    }
  return (store);
}
