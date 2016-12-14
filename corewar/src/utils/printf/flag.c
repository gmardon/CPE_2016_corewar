/*
** flag.c for printf in /home/aurelien.olibe/delivery/PSU_2016_my_printf
**
** Made by Aurelien Olibe
** Login   <aurelien.olibe@epitech.net>
**
** Started on  Fri Nov 11 19:28:54 2016 Aurelien Olibe
** Last update Mon Nov 14 20:39:58 2016 Aurelien Olibe
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "basic.h"

void	zero_pad2(t_farg *avs, char *str, char *new, ssize_t i)
{
  int	j;
  int	neg;

  j = avs->n_o - 1;
  i--;
  neg = 0;
  while (i >= 0 && neg == 0)
    {
      new[j] = str[i];
      i--;
      j--;
      if (str[i] == '-')
	neg = 1;
    }
  i = 0;
  while (avs->n_o > 0)
    {
      new[j] = '0';
      avs->n_o = avs->n_o - 1;
      j--;
    }
  if (neg == 1)
    new[0] = '-';
}

char		*zero_pad(t_farg *avs, char *str, int alt, t_stockarg *store)
{
  ssize_t	i;
  char		*new;

  i = 0;
  while (str[i] != '\0')
    i++;
  if (avs->n_o > i)
    {
      if ((new = malloc(sizeof(char) * (avs->n_o + 1))) == NULL)
	return (str);
    }
  else
    return (str);
  new[avs->n_o] = '\0';
  zero_pad2(avs, str, new, i);
  if (alt > 0)
    {
      if (avs->form == 5)
	new[1] = 'x';
      else if (avs->form == 6)
	new[1] = 'X';
    }
  replace_free(store, new);
  return (new);
}

void		alt_form2(char *str, char *new, ssize_t i)
{
  ssize_t	j;

  j = 0;
  while (str[j] != '\0')
    {
      new[i] = str[j];
      j++;
      i++;
    }
}

char		*alt_form(t_farg *avs, char *str, t_stockarg *store)
{
  ssize_t	i;
  char		*new;

  i = my_strlen(str);
  if (avs->form == 3)
    {
      if ((new = malloc(sizeof(char) * (i + 2))) == NULL)
        return (str);
      new[0] = '0';
      i = 1;
    }
  else if (avs->form == 5 || avs->form == 6 || avs->form == 19)
    {
      if ((new = malloc(sizeof(char) * (i + 3))) == NULL)
        return (str);
      new[0] = '0';
      if (avs->form == 5 || avs->form == 19)
	new[1] = 'x';
      else if (avs->form == 6)
	new[1] = 'X';
      i = 2;
    }
  alt_form2(str, new, i);
  replace_free(store, new);
  return (new);
}

char		*gest_flag(t_farg *avs, char *str, int d, t_stockarg *store)
{
  size_t	i;

  i = 0;
  while (avs->flag[i] != FLAG_NULL)
    {
      if (avs->flag[i] == 1 && d != 0)
	str = alt_form(avs, str, store);
      else if (avs->flag[i] == 2)
	str = zero_pad(avs, str, 0, store);
      else if (avs->flag[i] == 3)
	str = neg_pad(avs, str, store);
      else if (avs->flag[i] == 9)
	str = zero_pad(avs, str, 1, store);
      else if (avs->flag[i] == 10)
	str = field_pad(avs, str, store);
      else if (avs->flag[i] == 4 && avs->form == 1)
	str = plus(str, store, 1);
      else if (avs->flag[i] == 5 && avs->form == 1)
	str = plus(str, store, 0);
      i++;
    }
  return (str);
}
