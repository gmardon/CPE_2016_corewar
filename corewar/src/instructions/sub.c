/*
** sub.c for corewar in /home/aurelien/home/aurelien.olibe/delivery/CPE_2016_corewar/corewar
**
** Made by Aurelien
** Login   <aurelien.olibe@epitech.eu@epitech.net>
**
** Started on  Sat Dec 10 17:48:32 2016 Aurelien
** Last update Sat Dec 10 17:48:33 2016 Aurelien
*/
#include "core.h"

int sub(t_corewar *core, t_champion *ch)
{
  char *arg;
  ssize_t i;
  int sum;

  arg = decode_octet(ch->instr[1]);
  i = 2;
  if (arg[0] == 1 && arg[1] == 1 && arg[2] == 1)
  {
    if (check_reg(ch->instr[i]) == 0 && check_reg(ch->instr[i + 1]) == 0)
      sum = ch->reg[ch->instr[i]] - ch->reg[ch->instr[i + 1]];
    else
      return (INSTR_LEN_ARG);
    i += 2;
    if (check_reg(ch->instr[i]) == 0)
      ch->reg[ch->instr[i]] = sum;
    else
      return (INSTR_LEN_ARG);
  }
  else
    return (INSTR_LEN_ARG);
  ch->PC = inc_PC(ch->PC, INSTR_LEN_ARG);
  return (0);
}
