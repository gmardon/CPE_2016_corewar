/*
** my_malloc.c for asm in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/utils/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Tue Dec  6 09:30:22 2016 Guillaume MARDON
** Last update Tue Dec  6 10:35:52 2016 Guillaume MARDON
*/
#include "../../include/asm.h"

void	*my_malloc(int size)
{
  int trying;
  void *ref;

  trying = 0;
  ref = NULL;
  while (trying < 50 && !ref)
    {
      ref = malloc(size);
      trying++;
    }
  if (!ref)
    exit(84);

  return (ref);
}
