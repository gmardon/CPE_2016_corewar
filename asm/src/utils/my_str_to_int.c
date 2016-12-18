/*
** my_str_to_int.c for mysh in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/PSU_2016_minishell1/src/utils/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Wed Dec  7 16:07:34 2016 Guillaume MARDON
** Last update Sun Dec 18 18:02:14 2016 Romain Goasdoue
*/
#include "../../include/asm.h"

int my_str_to_int(char *str)
{
  int	nbr;
  int	pow;
  int	pow_i;
  int	length;

  if (*str == '-')
    return (my_str_to_int(str + 1) * -1);
  pow = 1;
  nbr = pow_i = 0;
  length = my_strlen(str);
  nbr = (*str - 48);
  while (pow_i++ < length)
    pow = pow * 10;
  nbr *= (pow / 10);
  if (length != 1)
    nbr += my_str_to_int(str + 1);
  return (nbr);
}

char	my_str_to_char(char *str)
{
  char	nbr;
  int	pow;
  int	pow_i;
  int	length;

  if (*str == '-')
    return (my_str_to_char(str + 1) * -1);
  pow = 1;
  nbr = pow_i = 0;
  length = my_strlen(str);
  nbr = (*str - 48);
  while (pow_i++ < length)
    pow = pow * 10;
  nbr *= (pow / 10);
  if (length != 1)
    nbr += my_str_to_int(str + 1);
  return (nbr);
}
