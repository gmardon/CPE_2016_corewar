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
	char *name;

	name = NULL;
	id = alive_read_id(ch);
	tmp = core->champions;
	while (tmp != NULL)
	{
		if (tmp->id == id && tmp->is_dead == 0)
		{
			add_live_to_core(core, id);
			name = tmp->head->prog_name;
			tmp->cycle_to_die_cur = (CYCLE_TO_DIE - (CYCLE_DELTA * core->n_delta));
		}
		tmp = tmp->next;
	}
	if (name != NULL)
		my_printf("The Player %d (%s) is alive.\n", id, name);
	dec_nbr_live(core);
	//if (tmp == NULL)
	//	printf("%s (%d) is alive.\n", "YOLO", id);
	ch->PC = inc_PC(ch->PC, 5);
	return (0);
}

void add_live_to_core(t_corewar *core, int id)
{
	if (core->live_on_this_cycle == 0)
	{
		core->live_on_this_cycle = 1;
		core->last_live_id = id;
	}
}

void dec_nbr_live(t_corewar *core)
{
	core->nbr_live_cur--;
	if (core->nbr_live_cur == 0)
	{
		core->n_delta++;
		core->nbr_live_cur = NBR_LIVE;
	}
}

int alive_read_id(t_champion *ch)
{
	int id;
	ssize_t count;
	ssize_t i;
	ssize_t j;
	unsigned int value;

	id = 0;
	i = 1;
	count = 5;
	while (i < count)
	{
		j = (i - 1);
		value = ((j + 1) < 4) ? (1) : (0);
		while (++j < 4)
			value = (value * 256);
		if (value > 0)
			id = id + (int) (ch->instr[i] * value);
		else
			id += (int) ch->instr[i];
		i++;
	}
	return (id);
}
