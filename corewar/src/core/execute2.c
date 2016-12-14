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

void decide_winner(t_corewar *core)
{
  t_champion *ch;

  ch = core->champions;
  if (core->last_live_id == 0)
    my_printf("Game is draw.\n");
  else
  {
    while (ch != NULL)
    {
      if (ch->id == core->last_live_id)
        break;
      ch = ch->next;
    }
    if (ch == NULL)
      my_printf("Game is draw.\n");
    else
      my_printf("The Player %d (%s) has won.\n", ch->id, ch->head->prog_name);
  }
}

int is_already_in(t_champion *ch, int ch_id[5])
{
  int j;
  int bol;

  j = bol = 0;
  while (j < 4)
  {
    if (ch_id[j] == ch->id)
      bol = 1;
    j++;
  }
  return (bol);
}

void kill_all_child(t_corewar *core, int id)
{
  t_champion *tmp;

  tmp = core->champions;
  while (tmp != NULL)
  {
    if (tmp->id == id)
      tmp->is_dead = 1;
    tmp = tmp->next;
  }
}

void copy_next_instr(t_corewar *core, t_champion *ch)
{
  unsigned char instr;
  ssize_t len;
  ssize_t i;
  ssize_t tmp_pc;

  len = i = 0;
  tmp_pc = ch->pc;
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
    tmp_pc = inc_pc(tmp_pc, 1);
  }
}

ssize_t get_instr_len(t_corewar *core, ssize_t pc, unsigned char instr)
{
  char *arg;
  ssize_t len;
  ssize_t i;

  i = 0;
  arg = decode_octet(core->arena[inc_pc(pc, 1)]);
  len = 2;
  while (i < 4)
  {
    if (arg[i] == 4 && (instr == 10 || instr == 11 || instr == 14))
      len = len + 2;
    else
      len = len + arg[i];
    i++;
  }
  free(arg);
  return (len);
}
