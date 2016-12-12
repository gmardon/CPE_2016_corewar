/*
** xor.c for corewar in /home/aurelien/home/aurelien.olibe/delivery/CPE_2016_corewar/corewar
**
** Made by Aurelien
** Login   <aurelien.olibe@epitech.eu@epitech.net>
**
** Started on  Sat Dec 10 20:56:47 2016 Aurelien
** Last update Sat Dec 10 20:56:48 2016 Aurelien
*/
#include "core.h"

int xor(t_corewar *core, t_champion *ch)
{
  char *arg;
  short ind;
  int dir;
  int dir2;
  ssize_t i;

  arg = decode_octet(ch->instr[1]);
  i = 2;
  if (arg[0] != 1 && arg[0] != 2 && arg[0] != 4)
    return (-1);
  dir = get_dir_form_arg(core, ch, arg[0], &i);
  if (arg[1] != 1 && arg[1] != 2 && arg[1] != 4)
    return (-1);
  dir2 = get_dir_form_arg(core, ch, arg[1], &i);
  if (arg[2] == 1 && check_reg(ch->instr[i]) == 0)
    ch->reg[ch->instr[i]] = (dir ^ dir2);
  else
    return (-1);
  ch->PC = inc_PC(ch->PC, INSTR_LEN_ARG);
  return (0);
}
