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
  int ret;

  ret = 0;
  if (ch->is_exec == 1)
  {
    index = 0;
    ch->is_exec = 0;
    while (tab_instruction[index].id)
    {
      if (tab_instruction[index].id == ch->instr[0])
      {
	     ret = tab_instruction[index].function(core, ch);
	     break;
      }
      index++;
    }
  }
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
  copy_next_instr(core, ch);
  ch->is_exec = 1;
}

/*
** for arg :
** 1 is reg
** 2 is ind
** 4 is dir
*/
char *decode_octet(unsigned char c)
{
  char *arg;
  char bits[8];
  ssize_t i;
  ssize_t j;

  i = 0;
  j = 3;
  if ((arg = malloc(sizeof(char) * 4)) == NULL)
    exit(84);
  while (i < 8)
  {
    bits[i] = (c & (1 << i)) >> i;
    i++;
  }
  i = 0;
  while (i < 4)
  {
    arg[j] = decode_bit(arg[j], bits[(i * 2) + 1], bits[(i * 2)]);
    i++;
    j--;
  }
  return (arg);
}

char decode_bit(char arg, char bit1, char bit2)
{
  if (bit1 == 0 && bit2 == 1)
    arg = 1;
  else if (bit1 == 1 && bit2 == 1)
    arg = 2;
  else if (bit1 == 1 && bit2 == 0)
    arg = 4;
  else
    arg = 0;
  return (arg);
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
