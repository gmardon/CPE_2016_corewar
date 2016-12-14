/*
** st.c for corewar in /home/aurelien/home/aurelien.olibe/delivery/CPE_2016_corewar/corewar
**
** Made by Aurelien
** Login   <aurelien.olibe@epitech.eu@epitech.net>
**
** Started on  Sat Dec 10 15:29:31 2016 Aurelien
** Last update Sat Dec 10 15:29:32 2016 Aurelien
*/
#include "core.h"

int st(t_corewar *core, t_champion *ch)
{
  char *arg;
  short ind;
  ssize_t i;
  ssize_t cp_pc;

  arg = decode_octet(ch->instr[1]);
  i = 2;
  if (arg[0] != 1 || check_reg(ch->instr[i]) != 0)
    return (INSTR_LEN_ARG);
  i++;
  if (arg[1] == 1 && check_reg(ch->instr[i]) == 0)
    ch->reg[ch->instr[i]] = ch->reg[ch->instr[i - 1]];
  else if (arg[1] == 2)
  {
    ind = read_ind(ch, &i);
    cp_pc = inc_pc(ch->pc, (ind % IDX_MOD));
    st_dir_pc(core, cp_pc, (ch->reg[ch->instr[i - 3]]));
  }
  else
    return (INSTR_LEN_ARG);
  ch->pc = inc_pc(ch->pc, INSTR_LEN_ARG);
  free(arg);
  return (0);
}

int st_dir_pc(t_corewar *core, ssize_t pc, int dir)
{
  unsigned char *b;
  ssize_t i;

  i = 3;
  b = (unsigned char *) &dir;
  while (i >= 0)
  {
    core->arena[pc] = b[i];
    i--;
    pc = inc_pc(pc, 1);
  }
  return (0);
}
