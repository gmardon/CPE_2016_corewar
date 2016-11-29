/*
** my_putstr.c for asm in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/utils/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Wed Nov  9 13:42:55 2016 Guillaume MARDON
** Last update Wed Nov  9 14:10:12 2016 Guillaume MARDON
*/
#include "../../include/asm.h"

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
