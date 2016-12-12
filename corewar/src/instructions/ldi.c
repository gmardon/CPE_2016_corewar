/*
** ldi.c for corewar in /home/aurelien/home/aurelien.olibe/delivery/CPE_2016_corewar/corewar
**
** Made by Aurelien
** Login   <aurelien.olibe@epitech.eu@epitech.net>
**
** Started on  Sun Dec 11 18:42:54 2016 Aurelien
** Last update Sun Dec 11 18:42:55 2016 Aurelien
*/
#include "core.h"

int ldi(t_corewar *core, t_champion *ch)
{
  char *arg;
  int sum;
  ssize_t i;

  arg = decode_octet(ch->instr[1]);
  i = 2;
  sum = 0;
  if (get_sum(core, ch, &i, &sum) == -1)
    return (instr_len_exception(arg));
  if (arg[1] == 1 && check_reg(ch->instr[i]) == 0)
    sum = sum + ch->reg[ch->instr[i++]];
  else if (arg[1] == 4)
    sum = sum + read_ind(ch, &i);
  else
    return (-1);
  if (arg[2] == 1 && check_reg(ch->instr[i]) == 0)
    ch->reg[ch->instr[i]] = read_dir_pc_int(core, ch, sum);
  else
    return (instr_len_exception(arg));
  ch->PC = inc_PC(ch->PC, instr_len_exception(arg));
  return (0);
}

int instr_len_exception(char *arg)
{
  int result;
  int i;

  result = 2;
  i = 0;
  while (i < 4)
  {
    if (arg[i] == 4)
      result = result + 2;
    else
      result = result + (int) arg[i];
    i++;
  }
  return (result);
}

int read_dir_pc_int(t_corewar *core, t_champion *ch, int sum)
{
  int dir;
  ssize_t j;
  ssize_t i;
  ssize_t k;
  unsigned int value;

  dir = 0;
  i = 1;
  k = inc_PC(ch->PC, (sum % IDX_MOD));
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

int get_sum(t_corewar *core, t_champion *ch, ssize_t *i, int *sum)
{
  char *arg;
  short ind;

  arg = decode_octet(ch->instr[1]);
  if (arg[0] == 1 && check_reg(ch->instr[*i]) == 0)
  {
    *sum = ch->reg[ch->instr[*i]];
    *i = *i + 1;
  }
  else if (arg[0] == 2)
    {
      ind = read_ind(ch, i);
      *sum = (int) read_ind_pc(core, ch, ind);
    }
  else if (arg[0] == 4)
    *sum = read_ind(ch, i);
  else
    return (-1);
  return (0);
}

short read_ind_pc(t_corewar *core, t_champion *ch, short ind)
{
  short result;
  ssize_t j;
  ssize_t k;
  ssize_t i;
  unsigned int value;

  ind = 0;
  i = 1;
  k = inc_PC(ch->PC, (ind % IDX_MOD));
  while (i < 3)
  {
    j = (i - 1);
    value = ((j + 1) < 2) ? (1) : (0);
    while (++j < 2)
      value = (value * 256);
    if (value > 0)
      result = result + (int) (core->arena[k] * value);
    else
      result += (int) core->arena[k];
    i++;
    k = inc_PC(k, 1);
  }
  return (result);
}
