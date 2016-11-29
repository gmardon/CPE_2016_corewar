/*
** my_putchar.c for asm in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/utils/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Wed Nov  9 13:42:48 2016 Guillaume MARDON
** Last update Tue Nov 29 16:44:45 2016 Guillaume MARDON
*/
#include "../../include/core.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
