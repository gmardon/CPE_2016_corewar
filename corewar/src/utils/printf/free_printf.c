/*
** free.c for printf in /home/aurelien.olibe/delivery/PSU_2016_my_printf
**
** Made by Aurelien Olibe
** Login   <aurelien.olibe@epitech.net>
**
** Started on  Mon Nov 14 15:54:26 2016 Aurelien Olibe
** Last update Mon Nov 14 16:14:38 2016 Aurelien Olibe
*/
#include "basic.h"
#include <stdlib.h>
#include <stdarg.h>

void		free_store(t_stockarg *store)
{
  free(store->start);
  free(store->p_len);
  free(store->all_arg);
  free(store->to_free);
  free(store);
}

void	free_avs(t_farg *avs)
{
  free(avs->flag);
  free(avs);
}

void	replace_free(t_stockarg *store, char *new)
{
  if (store->to_free[store->k] != NULL)
    {
      free(store->to_free[store->k]);
      store->to_free[store->k] = new;
    }
}
