/*
** my_strlen.c for corewar in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/corewar/src/utils/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Tue Nov 29 16:43:31 2016 Guillaume MARDON
** Last update Tue Nov 29 16:43:34 2016 Guillaume MARDON
*/
#include "../../include/core.h"

size_t	my_strlen(char *str)
{
  size_t	i;

  i = 0;
  while (str[i] != '\0')
    {
      i++;
    }
  return (i);
}
