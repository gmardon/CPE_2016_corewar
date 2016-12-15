/*
** my_strlen.c for corewar in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/corewar/src/utils/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Tue Nov 29 16:43:31 2016 Guillaume MARDON
** Last update Wed Dec 14 18:56:22 2016 Guillaume MARDON
*/
#include "../../include/asm.h"

int	my_indexof(char c, char *str)
{
  int	index;

  index = 0;
  while (str[index] && str[index] != c)
    {
      index++;
    }
  return (index);
}
