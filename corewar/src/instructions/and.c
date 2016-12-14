/*
** and.c for corewar in /home/aurelien/home/aurelien.olibe/delivery/CPE_2016_corewar/corewar
**
** Made by Aurelien
** Login   <aurelien.olibe@epitech.eu@epitech.net>
**
** Started on  Sat Dec 10 19:55:11 2016 Aurelien
** Last update Sat Dec 10 19:55:11 2016 Aurelien
*/
#include "core.h"

int and(t_corewar *core, t_champion *ch)
{
  char *arg;
  int dir;
  int dir2;
  ssize_t i;

  ch->carry = 0;
  arg = decode_octet(ch->instr[1]);
  i = 2;
  if (arg[0] != 1 && arg[0] != 2 && arg[0] != 4)
    return (INSTR_LEN_ARG);
  dir = get_dir_form_arg(core, ch, arg[0], &i);
  if (arg[1] != 1 && arg[1] != 2 && arg[1] != 4)
    return (INSTR_LEN_ARG);
  dir2 = get_dir_form_arg(core, ch, arg[1], &i);
  if (arg[2] == 1 && check_reg(ch->instr[i]) == 0)
    ch->reg[ch->instr[i]] = (dir & dir2);
  else
    return (INSTR_LEN_ARG);
  ch->PC = inc_PC(ch->PC, INSTR_LEN_ARG);
  ch->carry = 1;
  free(arg);
  return (0);
}

int get_dir_form_arg(t_corewar *core, t_champion *ch, char a, ssize_t *i)
{
  short ind;
  int dir;

  if (a == 1 && check_reg(ch->instr[*i]) == 0)
  {
    dir = ch->reg[ch->instr[*i]];
    *i = *i + 1;
  }
  else if (a == 2)
  {
    ind = read_ind(ch, i);
    dir = read_dir_pc(core, ch, ind);
  }
  else if (a == 4)
    dir = read_dir(ch, i);
  return (dir);
}
