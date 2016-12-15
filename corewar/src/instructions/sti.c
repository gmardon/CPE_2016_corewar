/*
** sti.c for corewar in /home/aurelien/home/aurelien.olibe/delivery/CPE_2016_corewar/corewar
**
** Made by Aurelien
** Login   <aurelien.olibe@epitech.eu@epitech.net>
**
** Started on  Mon Dec 12 18:35:56 2016 Aurelien
** Last update Thu Dec 15 10:52:27 2016 Aurelien
*/
#include "core.h"

int		sti(t_corewar *core, t_champion *ch)
{
  char		*arg;
  ssize_t	i;
  int		sum;
  int		dir;

  arg = decode_octet(ch->instr[1]);
  i = 2;
  sum = 0;
  if (arg[0] == 1 && check_reg(ch->instr[i]) == 0)
    dir = ch->reg[ch->instr[i++]];
  else
    return (instr_len_exception(arg));
  if (get_sum2(core, ch, &i, &sum) == -1)
    return (instr_len_exception(arg));
  if (arg[2] == 1 && check_reg(ch->instr[i]) == 0)
    sum = sum + ch->reg[ch->instr[i++]];
  else if (arg[2] == 4)
    sum = sum + read_ind(ch, &i);
  else
    return (instr_len_exception(arg));
  st_dir_pc(core, (inc_pc(ch->pc, (sum % IDX_MOD))), dir);
  ch->pc = inc_pc(ch->pc, instr_len_exception(arg));
  free(arg);
  return (0);
}

int	get_sum2(t_corewar *core, t_champion *ch, ssize_t *i, int *sum)
{
  char	*arg;
  short	ind;

  arg = decode_octet(ch->instr[1]);
  if (arg[1] == 1 && check_reg(ch->instr[*i]) == 0)
    {
      *sum = ch->reg[ch->instr[*i]];
      *i = *i + 1;
    }
  else if (arg[1] == 2)
    {
      ind = read_ind(ch, i);
      *sum = (int) read_ind_pc(core, ch, ind);
    }
  else if (arg[1] == 4)
    *sum = read_ind(ch, i);
  else
    return (-1);
  free(arg);
  return (0);
}
