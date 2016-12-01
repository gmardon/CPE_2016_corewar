/*
** main.c for corewar in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/vm/src/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Wed Nov  9 18:45:17 2016 Guillaume MARDON
** Last update Wed Nov  9 19:15:47 2016 Guillaume MARDON
*/
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <stdlib.h>
#include "op.h"
#include "core.h"
#include "read_core.h"

int main(int ac, char **av)
{
  t_corewar *core;

  if (ac > 1)
  {
    core = read_core(ac, av);
    print_arena(core);
  }
  else
    write(1, "Too few arguments.\n", 19); // to replace by Usage:
  return (0);
}
