/*
** flag2.c for printf in /home/aurelien.olibe/delivery/PSU_2016_my_printf
**
** Made by Aurelien Olibe
** Login   <aurelien.olibe@epitech.net>
**
** Started on  Sat Nov 12 21:11:29 2016 Aurelien Olibe
** Last update Mon Nov 14 20:39:41 2016 Aurelien Olibe
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "basic.h"

char		*plus(char *str, t_stockarg *store, int plus)
{
  char		*new;
  ssize_t	i;

  if (str[0] == '-')
    return (str);
  i = 0;
  while (str[i] != '\0')
    i++;
  if ((new = malloc(sizeof(char) * (i + 2))) == NULL)
    return (str);
  new[i + 1] = '\0';
  if (plus)
    new[0] = '+';
  else
    new[0] = ' ';
  while (i >= 0)
    {
      new[i + 1] = str[i];
      i--;
    }
  replace_free(store, new);
  return (new);
}

void	neg_pad2(t_farg *avs, char *str, char *new, ssize_t i)
{
  int	j;

  i = j = 0;
  while (str[i] != '\0')
    {
      new[j] = str[i];
      i++;
      j++;
    }
  while (j < avs->n_o)
    {
      new[j] = ' ';
      j++;
    }
}

char		*neg_pad(t_farg *avs, char *str, t_stockarg *store)
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
  neg_pad2(avs, str, new, i);
  replace_free(store, new);
  return (new);
}


void	field_pad2(t_farg *avs, char *str, char *new, ssize_t i)
{
  int	j;

  j = avs->n_o - 1;
  i--;
  while (i >= 0)
    {
      new[j] = str[i];
      i--;
      j--;
    }
  i = 0;
  while (avs->n_o > 0)
    {
      new[j] = ' ';
      avs->n_o = avs->n_o - 1;
      j--;
    }
}

char		*field_pad(t_farg *avs, char *str, t_stockarg *store)
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
  field_pad2(avs, str, new, i);
  replace_free(store, new);
  return (new);
}
