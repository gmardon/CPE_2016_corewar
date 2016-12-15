/*
** lfork.c for corewar in /home/aurelien/home/aurelien.olibe/delivery/CPE_2016_corewar/corewar
**
** Made by Aurelien
** Login   <aurelien.olibe@epitech.eu@epitech.net>
**
** Started on  Tue Dec 13 17:00:44 2016 Aurelien
** Last update Thu Dec 15 10:48:49 2016 Aurelien
*/
#include "core.h"
#include "read_core.h"

int		lfrk(t_corewar *core, t_champion *ch)
{
  t_champion	*new;
  ssize_t	i;
  short		ind;

  i = 1;
  ch->carry = 0;
  ind = read_ind(ch, &i);
  new = ch_dup(core, ch);
  new->pc = inc_pc(new->pc, ind);
  ch->pc = inc_pc(ch->pc, 3);
  ch->carry = 1;
  new->carry = 1;
  return (0);
}
