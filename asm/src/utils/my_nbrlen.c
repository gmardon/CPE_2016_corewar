/*
** my_nbrlen.c for my_ls in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/PSU_2016_my_ls_boostrap/src/utils/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Tue Nov 15 15:51:39 2016 Guillaume MARDON
** Last update Tue Nov 29 16:38:14 2016 Guillaume MARDON
*/
#include "../../include/asm.h"

size_t	my_nbrlen(size_t input, unsigned int radix)
{
  size_t	i;

  i = 1;
  if (input < 0)
    ++i;
  while (radix > 1 && (input /= radix))
    ++i;
  return (i);
}
