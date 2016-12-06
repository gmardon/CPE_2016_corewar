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

	id = alive_read_id(ch);
	tmp = core->champions;
	while (tmp != NULL)
	{
		if (tmp->id_fork == id)
		{
			// write
			tmp->nbr_live_cur--;
			if (tmp->nbr_live_cur == 0)
			{
				tmp->n_delta++;
				tmp->nbr_live_cur = NBR_LIVE;
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

int alive_read_id(t_champion *ch)
{
	int id;
	int count;

	id = 0;
	count = ch->i + 5;
	while (ch->i < count)
	{
		if (id > 0 && ch->PC[ch->i][0] > 0)
			id = id * (int) ch->PC[ch->i][0];
		else if (id == 0 && ch->PC[ch->i][0] > 0)
			id += (int) ch->PC[ch->i][0];
		ch->i++;
	}
	return (id);
}
