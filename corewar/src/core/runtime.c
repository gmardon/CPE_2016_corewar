/*
** runtime.c for corewar in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/corewar/src/core/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Fri Nov 11 10:31:57 2016 Guillaume MARDON
** Last update Tue Dec  6 15:46:44 2016 Aurelien
*/
#include "../../include/core.h"

t_instruction	tab_instruction[] =
{
  {1, alive, 10},
  {2, ld, 5},
  {3, st, 5},
  {4, add, 10},
  {5, sub, 10},
  {6, and, 6},
  {7, or, 6},
  {8, xor, 6},/*
  {9, zjmp, 20},
  {10, ldi, 25},
  {11, sti, 25},
  {12, fork, 800},
  {13, lld, 10},
  {14, lldi, 50},
  {15, lfork, 1000},
  {16, aff, 2},*/
  {0, 0, 0}
};
