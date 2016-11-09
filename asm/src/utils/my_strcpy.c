/*
** my_strcpy.c for asm in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/utils/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Wed Nov  9 14:38:57 2016 Guillaume MARDON
** Last update Wed Nov  9 14:39:06 2016 Guillaume MARDON
*/
#include "../../include/asm.h"

char 	*my_strcpy(char *dest, char *src)
{
  int	index;

  index = 0;
  while (src[index] != '\0')
  {
      dest[index] = src[index];
      index++;
    }
  dest[index] = '\0';
  return (dest);
}
