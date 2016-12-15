/*
** free.c for corewar in /home/aurelien/home/aurelien.olibe/delivery/CPE_2016_corewar/corewar
**
** Made by Aurelien
** Login   <aurelien.olibe@epitech.eu@epitech.net>
**
** Started on  Wed Dec 14 14:46:24 2016 Aurelien
** Last update Thu Dec 15 10:36:13 2016 Aurelien
*/
#include "core.h"
#include "read_core.h"

void	free_code_ch(t_code_champ *ch)
{
  free(ch->str);
  free(ch);
}

void		free_core_ch(t_corewar *core)
{
  t_champion	*ch;
  t_champion	*tmp;
  ssize_t	i;

  i = 1;
  ch = core->champions;
  while (ch != NULL)
    {
      if (ch->id == i++)
	free(ch->head);
      free(ch->reg);
      free(ch->instr);
      tmp = ch->next;
      free(ch);
      ch = tmp;
    }
  free(core->arena);
  free(core);
}
