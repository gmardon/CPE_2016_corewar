/*
** fork.c for corewar in /home/aurelien/home/aurelien.olibe/delivery/CPE_2016_corewar/corewar
**
** Made by Aurelien
** Login   <aurelien.olibe@epitech.eu@epitech.net>
**
** Started on  Tue Dec 13 16:59:52 2016 Aurelien
** Last update Thu Dec 15 10:45:47 2016 Aurelien
*/
#include "core.h"
#include "read_core.h"

int		frk(t_corewar *core, t_champion *ch)
{
  t_champion	*new;
  ssize_t	i;
  short		ind;

  i = 1;
  ind = read_ind(ch, &i);
  new = ch_dup(core, ch);
  new->pc = inc_pc(new->pc, (ind % IDX_MOD));
  ch->pc = inc_pc(ch->pc, 3);
  return (0);
}

t_champion	*ch_dup(t_corewar *core, t_champion *ch)
{
  t_champion	*new;
  t_champion	*tmp;
  ssize_t	i;

  i = 1;
  tmp = core->champions;
  new = init_champ(ch->id);
  new->id = ch->id;
  new->is_dead = ch->is_dead;
  new->head = ch->head;
  new->pc = ch->pc;
  new->carry = ch->carry;
  new->is_exec = 0;
  new->c_to_wait = ch->c_to_wait;
  new->cycle_to_die_cur = ch->cycle_to_die_cur;
  while (i < 17)
    {
      new->reg[i] = ch->reg[i];
      i++;
    }
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new;
  return (new);
}
