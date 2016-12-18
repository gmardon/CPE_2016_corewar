/*
** my_itoa.c for my_ls in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/PSU_2016_my_ls_boostrap/src/utils/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Tue Nov 15 15:49:43 2016 Guillaume MARDON
** Last update Sun Dec 18 18:00:38 2016 Romain Goasdoue
*/

#include "../../include/asm.h"

void	my_itoa(size_t input, char *buffer, unsigned int radix)
{
  size_t	i;

  i = my_nbrlen(input, radix) - 1;
  buffer[i] = '\0';
  if (input < 0)
    buffer[0] = '-';
  if (input == 0)
    buffer[0] = '0';
  while (input)
    {
      buffer[i] = RADIX[abs(input) % radix];
      input /= radix;
      --i;
    }
}
