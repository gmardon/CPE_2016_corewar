/*
** execute2.c for corewar in /home/aurelien/home/aurelien.olibe/delivery/CPE_2016_corewar/corewar
**
** Made by Aurelien
** Login   <aurelien.olibe@epitech.eu@epitech.net>
**
** Started on  Fri Dec  9 17:46:55 2016 Aurelien
** Last update Fri Dec  9 17:46:56 2016 Aurelien
*/
#include "core.h"

void copy_next_instr(t_corewar *core, t_champion *ch)
{
  unsigned char instr;
  ssize_t len;
  ssize_t i;
  ssize_t tmp_pc;

  len = i = 0;
  tmp_pc = ch->PC;
  instr = core->arena[tmp_pc];
  if (instr == 1)
    len = 5;
  else if (instr == 9 || instr == 12 || instr == 15)
    len = 3;
  else
    len = get_instr_len(core, tmp_pc, instr);
  while (i < len)
  {
    ch->instr[i] = core->arena[tmp_pc];
    i++;
    tmp_pc = inc_PC(tmp_pc, 1);
  }
}

ssize_t get_instr_len(t_corewar *core, ssize_t PC, unsigned char instr)
{
  char *arg;
  ssize_t len;
  ssize_t i;

  i = 0;
  arg = decode_octet(core->arena[inc_PC(PC, 1)]);
  len = 2;
  while (i < 4)
  {
    if (arg[i] == 4 && (instr == 10 || instr == 11 || instr == 14))
      len = len + 2;
    else
      len = len + arg[i];
    i++;
  }
  return (len);
}
