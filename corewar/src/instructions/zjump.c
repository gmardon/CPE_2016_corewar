/*
** zjump.c for corewar in /home/aurelien/home/aurelien.olibe/delivery/CPE_2016_corewar/corewar
**
** Made by Aurelien
** Login   <aurelien.olibe@epitech.eu@epitech.net>
**
** Started on  Sun Dec 11 18:35:28 2016 Aurelien
** Last update Sun Dec 11 18:35:28 2016 Aurelien
*/
#include "core.h"

int zjmp(t_corewar *core, t_champion *ch)
{
  ssize_t i;
  short ind;

  i = 1;
  if (ch->carry == 1)
  {
    ind = read_ind(ch, &i);
    ch->pc = inc_pc(ch->pc, (ind % IDX_MOD));
  }
  else
    ch->pc = inc_pc(ch->pc, 3);
  return (0);
}
