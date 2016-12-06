/*
** execute.c for corewar in /home/aurelien/home/aurelien.olibe/delivery/CPE_2016_corewar/corewar/src/core
**
** Made by Aurelien
** Login   <aurelien.olibe@epitech.eu@epitech.net>
**
** Started on  Tue Dec  6 14:40:03 2016 Aurelien
** Last update Tue Dec  6 15:19:05 2016 John Doe
*/
#include "core.h"

void exec_champ(t_corewar *core, t_champion *ch)
{
  int index;

  if (ch->PC[ch->i] == NULL)
    return ;
  index = 0;
  while (tab_instruction[index].id)
  {
    if (tab_instruction[index].id == ch->PC[ch->i][0])
    {
	    tab_instruction[index].function(core, ch);
	    break;
    }
    index++;
  }
  index = 0;
  while (tab_instruction[index].id && ch->PC[ch->i] != NULL)
  {
    if (tab_instruction[index].id == ch->PC[ch->i][0])
    {
      ch->c_to_wait = tab_instruction[index].nbr_cycle;
      break;
    }
    index++;
  }
}
