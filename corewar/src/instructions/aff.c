/*
** aff.c for corewar in /home/aurelien/home/aurelien.olibe/delivery/CPE_2016_corewar/corewar
**
** Made by Aurelien
** Login   <aurelien.olibe@epitech.eu@epitech.net>
**
** Started on  Mon Dec 12 13:43:29 2016 Aurelien
** Last update Mon Dec 12 13:43:30 2016 Aurelien
*/
#include "core.h"

int aff(t_corewar *core, t_champion *ch)
{
  char *arg;
  ssize_t i;
  unsigned char c;

  arg = decode_octet(ch->instr[1]);
  i = 2;
  if (arg[0] == 1 && arg[1] == 0 && arg[2] == 0 && arg[3] == 0)
  {
    if (check_reg(ch->instr[i]) == 0)
    {
      c = (unsigned char) (ch->reg[ch->instr[i]] % 256);
      my_printf("%c", c);
    }
    else
      return (INSTR_LEN_ARG);
  }
  else
    return (INSTR_LEN_ARG);
  ch->PC = inc_PC(ch->PC, INSTR_LEN_ARG);
  free(arg);
  return (0);
}
