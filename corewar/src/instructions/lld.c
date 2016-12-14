/*
** lld.c for corewar in /home/aurelien/home/aurelien.olibe/delivery/CPE_2016_corewar/corewar
**
** Made by Aurelien
** Login   <aurelien.olibe@epitech.eu@epitech.net>
**
** Started on  Mon Dec 12 18:57:20 2016 Aurelien
** Last update Mon Dec 12 18:57:20 2016 Aurelien
*/
#include "core.h"

int lld(t_corewar *core, t_champion *ch)
{
  char *arg;
  int dir;
  short ind;
  ssize_t i;

  ch->carry = 0;
  arg = decode_octet(ch->instr[1]);
  i = 2;
  if (arg[0] == 2)
    {
      ind = read_ind(ch, &i);
      dir = read_dir_pc_l(core, ch, ind);
    }
  else if (arg[0] == 4)
    dir = read_dir(ch, &i);
  else
    return (INSTR_LEN_ARG);
  if (arg[1] == 1 && check_reg(ch->instr[i]) == 0)
    ch->reg[ch->instr[i]] = dir;
  else
    return (INSTR_LEN_ARG);
  ch->PC = inc_PC(ch->PC, INSTR_LEN_ARG);
  ch->carry = 1;
  return (0);
}

int read_dir_pc_l(t_corewar *core, t_champion *ch, short ind)
{
  int dir;
  ssize_t j;
  ssize_t i;
  ssize_t k;
  unsigned int value;

  dir = 0;
  i = 1;
  k = inc_PC(ch->PC, ind);
  while (i < 5)
  {
    j = (i - 1);
    value = ((j + 1) < 4) ? (1) : (0);
    while (++j < 4)
      value = (value * 256);
    if (value > 0)
      dir = dir + (int) (core->arena[k] * value);
    else
      dir += (int) core->arena[k];
    i++;
    k = inc_PC(k, 1);
  }
  return (dir);
}
