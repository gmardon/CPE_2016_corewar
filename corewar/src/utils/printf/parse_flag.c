/*
** parse_flag.c for printf in /home/aurelien.olibe/delivery/PSU_2016_my_printf
**
** Made by Aurelien Olibe
** Login   <aurelien.olibe@epitech.net>
**
** Started on  Sun Nov 13 22:52:44 2016 Aurelien Olibe
** Last update Mon Nov 14 12:59:04 2016 Aurelien Olibe
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "basic.h"

void		flag_override1(t_farg *avs, int *neg, int *zero)
{
  ssize_t	i;

  i = 0;
  if (*neg && *zero)
    *zero = 0;
  while (avs->flag[i] != FLAG_NULL)
    {
      if ((avs->flag[i] == 2 && *zero == 0) || (avs->flag[i] == 1 && *zero))
	{
	  avs->flag[i] = FLAG_NULL;
	  i++;
	  while (avs->flag[i] != FLAG_NULL)
	    {
	      avs->flag[i - 1] = avs->flag[i];
	      avs->flag[i] = FLAG_NULL;
	      i++;
	    }
	  i = -1;
	}
      i++;
    }
}

void		flag_override2(t_farg *avs, int *plus, int *space)
{
  ssize_t	i;

  i = 0;
  if (*plus)
    *space = 0;
  while (avs->flag[i] != FLAG_NULL)
    {
      if (avs->flag[i] == 5 && *space == 0)
	{
	  avs->flag[i] = FLAG_NULL;
	  i++;
	  while (avs->flag[i] != FLAG_NULL)
	    {
	      avs->flag[i - 1] = avs->flag[i];
	      avs->flag[i] = FLAG_NULL;
	      i++;
	    }
	  i = -1;
	}
      i++;
    }
}

void		flag_recon1(t_farg *avs, int *zero, int *neg, int *alt)
{
  ssize_t	i;

  i = 0;
  while (avs->flag[i] != FLAG_NULL)
    {
      if (avs->flag[i] == 2)
	*zero = 1;
      else if (avs->flag[i] == 3)
	*neg = 1;
      else if (avs->flag[i] == 1)
	*alt = 1;
      i++;
    }
  flag_override1(avs, neg, zero);
}

void		flag_recon2(t_farg *avs, int *plus, int *space)
{
  ssize_t	i;

  i = 0;
  while (avs->flag[i] != FLAG_NULL)
    {
      if (avs->flag[i] == 4)
	*plus = 1;
      else if (avs->flag[i] == 5)
	*space = 1;
      i++;
    }
  flag_override2(avs, plus, space);
}

void		flag_sort(t_farg *avs)
{
  int		neg;
  int		zero;
  int		plus;
  int		space;
  int		alt;
  ssize_t	i;

  neg = zero = plus = space = i = alt = 0;
  flag_recon1(avs, &zero, &neg, &alt);
  flag_recon2(avs, &plus, &space);
  sort(avs, &i, plus, 4);
  sort(avs, &i, space, 5);
  if (alt && zero)
    sort(avs, &i, 1, 9);
  else if (alt)
    sort(avs, &i, 1, 1);
  sort(avs, &i, neg, 3);
  sort(avs, &i, zero, 2);
  if (avs->n_o > 0 && (neg == 0 && zero == 0))
    sort(avs, &i, 1, 10);
  avs->flag[i] = FLAG_NULL;
}
