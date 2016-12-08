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

  //if (core->arena[ch->PC] == NULL)
  //  return ;
  if (ch->is_exec == 1)
  {
    index = 0;
    ch->is_exec = 0;
    while (tab_instruction[index].id)
    {
      if (tab_instruction[index].id == core->arena[ch->PC])
      {
	     tab_instruction[index].function(core, ch);
	     break;
      }
      index++;
    }
  }
  //get c to wait
  else
    set_next_exec(core, ch);
}

void set_next_exec(t_corewar *core, t_champion *ch)
{
  int index;

  index = 0;
  while (tab_instruction[index].id)
  {
    if (tab_instruction[index].id == core->arena[ch->PC])
    {
      ch->c_to_wait = tab_instruction[index].nbr_cycle;
      break;
    }
    index++;
  }
  // copy next instruction
  ch->is_exec = 1;
}

ssize_t inc_PC(ssize_t PC, int inc)
{
  ssize_t i;

  i = 0;
  if ((PC + inc) < 0)
  {
    while ((PC + inc + (MEM_SIZE * i)) < 0)
      i++;
    PC = PC + inc + (MEM_SIZE * i);
  }
  else
    PC = (PC + inc) % MEM_SIZE;
  return (PC);
}
