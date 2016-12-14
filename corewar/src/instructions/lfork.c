/*
** lfork.c for corewar in /home/aurelien/home/aurelien.olibe/delivery/CPE_2016_corewar/corewar
**
** Made by Aurelien
** Login   <aurelien.olibe@epitech.eu@epitech.net>
**
** Started on  Tue Dec 13 17:00:44 2016 Aurelien
** Last update Tue Dec 13 17:00:45 2016 Aurelien
*/
#include "core.h"
#include "read_core.h"

int lfrk(t_corewar *core, t_champion *ch)
{
  t_champion *new;
  ssize_t i;
  short ind;

  i = 1;
  ch->carry = 0;
  ind = read_ind(ch, &i);
  new = ch_dup(core, ch);
  new->PC = inc_PC(new->PC, ind);
  ch->PC = inc_PC(ch->PC, 3);
  ch->carry = 1;
  new->carry = 1;
  return (0);
}
