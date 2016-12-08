/*
** my_alive.c for corewar in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/corewar/src/instructions/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Fri Nov 11 10:28:11 2016 Guillaume MARDON
** Last update Fri Nov 11 11:39:12 2016 Guillaume MARDON
*/
#include "core.h"

int		alive(t_corewar *core, t_champion *ch)
{
	int id;
	t_champion *tmp;

	id = alive_read_id(core, ch);
	tmp = core->champions;
	while (tmp != NULL)
	{
		if (tmp->id == id && tmp->is_dead == 0)
		{
			my_printf("The Player %d (%s) is alive.", id, tmp->head->prog_name);
			tmp->cycle_to_die_cur = (CYCLE_TO_DIE - (CYCLE_DELTA * tmp->n_delta));
			tmp->nbr_live_cur--;
			if (tmp->nbr_live_cur == 0)
			{
				tmp->n_delta++;
				tmp->nbr_live_cur = NBR_LIVE;
			}
			break;
		}
		tmp = tmp->next;
	}
	if (tmp == NULL)
		my_printf("%s (%d) is alive.\n", "YOLO", id);
	return (0);
}

int alive_read_id(t_corewar *core, t_champion *ch)
{
	int id;
	ssize_t count;

	id = 0;
	count = inc_PC(ch->PC, 5);
	while (ch->PC < count)
	{
		if (id > 0 && core->arena[ch->PC] > 0)
			id = id * (int) core->arena[ch->PC];
		else if (id == 0 && core->arena[ch->PC] > 0)
			id += (int) core->arena[ch->PC];
		ch->PC = inc_PC(ch->PC, 1);
	}
	return (id);
}
