
/*
** ld.c for corewar in /home/aurelien/home/aurelien.olibe/delivery/CPE_2016_corewar/corewar
**
** Made by Aurelien
** Login   <aurelien.olibe@epitech.eu@epitech.net>
**
** Started on  Fri Dec  9 20:45:15 2016 Aurelien
** Last update Fri Dec  9 20:45:16 2016 Aurelien
*/
#include "core.h"

int ld(t_corewar *core, t_champion *ch)
{
  char *arg;
  int dir;
  short ind;
  ssize_t i;

  arg = decode_octet(ch->instr[1]);
  i = 2;
  if (arg[0] == 2)
    {
      ind = read_ind(ch, &i);
      dir = read_dir_pc(core, ch, ind);
    }
  else if (arg[0] == 4)
    dir = read_dir(ch, &i);
  else
    return (-1);
  if (arg[1] == 1 && check_reg(ch->instr[i]) == 0)
    ch->reg[ch->instr[i]] = dir;
  else
    return (-1);
  ch->PC = inc_PC(ch->PC, INSTR_LEN_ARG);
  return (0);
}

int check_reg(unsigned char r)
{
  if (r > 16)
    return (-1);
  else if (r <= 0)
    return (-1);
  else
    return (0);
}

int read_dir_pc(t_corewar *core, t_champion *ch, short ind)
{
  int dir;
  ssize_t j;
  ssize_t i;
  ssize_t k;
  unsigned int value;

  dir = 0;
  i = 1;
  k = inc_PC(ch->PC, (ind % IDX_MOD));
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

short read_ind(t_champion *ch, ssize_t *k)
{
  short ind;
  ssize_t count;
  ssize_t j;
  ssize_t i;
  unsigned int value;

  ind = 0;
  i = 1;
  count = 3;
  while (i < count)
  {
    j = (i - 1);
    value = ((j + 1) < 2) ? (1) : (0);
    while (++j < 2)
      value = (value * 256);
    if (value > 0)
      ind = ind + (int) (ch->instr[*k] * value);
    else
      ind += (int) ch->instr[*k];
    i++;
    *k = *k + 1;
  }
  return (ind);
}

int read_dir(t_champion *ch, ssize_t *k)
{
  int dir;
  ssize_t count;
  ssize_t j;
  ssize_t i;
  unsigned int value;

  dir = 0;
  i = 1;
  count = 5;
  while (i < count)
  {
    j = (i - 1);
    value = ((j + 1) < 4) ? (1) : (0);
    while (++j < 4)
      value = (value * 256);
    if (value > 0)
      dir = dir + (int) (ch->instr[*k] * value);
    else
      dir += (int) ch->instr[*k];
    i++;
    *k = *k + 1;
  }
  return (dir);
}
