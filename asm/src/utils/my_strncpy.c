/*
** my_strcpy.c for asm in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/utils/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Wed Nov  9 14:38:57 2016 Guillaume MARDON
** Last update Mon Dec 12 23:02:58 2016 Guillaume MARDON
*/
#include "../../include/asm.h"

char 	*my_strncpy(char *dest, char *src, size_t size)
{
  int	index;

  index = 0;
  while (index < size)
    {
      dest[index] = src[index];
      index++;
    }
  dest[index] = '\0';
  return (dest);
}
