/*
** my_cleanstr.c for asm in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/utils/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Wed Nov  9 19:49:36 2016 Guillaume MARDON
** Last update Wed Nov  9 19:59:04 2016 Guillaume MARDON
*/
#include "../../include/asm.h"

char	*my_cleanstr(char *str)
{
  while (*str == 32 || *str == 9)
    str++;

  return (str);
}
