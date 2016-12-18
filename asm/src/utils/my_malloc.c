/*
** my_malloc.c for asm in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/utils/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Tue Dec  6 09:30:22 2016 Guillaume MARDON
** Last update Sun Dec 18 18:00:58 2016 Romain Goasdoue
*/

#include "../../include/asm.h"

void	*my_malloc(int size)
{
  void	*ref;

  if (!(ref = malloc(size)))
    exit(84);
  return (ref);
}
