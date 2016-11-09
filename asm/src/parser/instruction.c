/*
** instruction.c for asm in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/parser/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Wed Nov  9 14:56:18 2016 Guillaume MARDON
** Last update Wed Nov  9 15:24:54 2016 Guillaume MARDON
*/
#include "../../include/asm.h"

int	is_label(char *line)
{
  int	index;

  index = 0;
  while (line[index])
    {
      if (line[index] == 32)
				return (0);

      if (line[index] == LABEL_CHAR)
        return (1);
      index++;
    }
  return (0);
}

t_instruction	read_instruction(char *line)
{
  int	index;
  char *op;
  op_t *opt;

  index = 0;
  while (line[index] != 32 && line[index] != '\t')
    index++;

	op = malloc(index * sizeof(char*));
  my_strcpy(op, line);
  op[index] = '\0';
  /*my_putstr("op : ");
  my_putstr(op);
  my_putstr("\n");*/
  index = 0;
  while (op_tab[index].code)
    {
      if (my_strcmp(op, op_tab[index].mnemonique) == 0)
				{
					opt = &op_tab[index];
	  			break;
				}
      index++;
    }
  /*
  my_putstr("Error: \"");
  my_putstr(command);
  my_putstr("\" command invalid.\n");
  exit(0);*/
  //my_putstr("find op: ");
  //my_putstr(op);
  //my_putstr("\n");
  if (opt)
    {
      my_putstr(opt->comment);
      my_putstr("\n");
    }

  t_instruction e;
  return e;
}
