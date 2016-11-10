/*
** instruction.c for asm in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/parser/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Wed Nov  9 14:56:18 2016 Guillaume MARDON
** Last update Thu Nov 10 11:39:16 2016 Guillaume MARDON
*/
#include "../../include/asm.h"

int	label_index(char *line)
{
  int	index;

  index = 0;
  while (line[index])
    {
      if (line[index] == 32)
				return (0);

      if (line[index] == LABEL_CHAR)
        break;
      index++;
    }
  index = 0;
  while (line[index])
    {
      if (line[index] == LABEL_CHAR)
        return (index + 1);

      index++;
    }
  return (0);
}

char	*retrieve_label(char *line)
{
  char *label;
  label = malloc(label_index(line) * sizeof(char*));
  my_strcpy(label, line);
  return (label);
}

args_t	*retrieve_args(char *line)
{
  int		index;
  while (line[index] != 32 && line[index] != '\t')
    index++;

  line = my_cleanstr(line + index);
//  my_putstr(line + index);
  //my_putchar('\n');

  args_t *e;

  return (e);
}

op_t	*retrieve_op(char *line)
{
  char	*op;
  int		index;
	op_t 	*opt;

  index = 0;
  while (line[index] != 32 && line[index] != '\t')
    index++;

	op = malloc(index * sizeof(char*));
  my_strcpy(op, line);
  op[index] = '\0';
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
  return (opt);
}

instruction_t	read_instruction(char *line)
{
  line = my_cleanstr(line);

  instruction_t instruction;

  if (label_index(line) != 0)
    {
      instruction.label = retrieve_label(line);
      line += label_index(line);
      line = my_cleanstr(line);
    }
	instruction.op = retrieve_op(line);
  instruction.args = retrieve_args(line);

/*
  if (instruction.op && instruction.label)
    {
    //  printf("instruction.op->mnemonique: %s, instruction.label: %s\n", instruction.op->mnemonique, instruction.label);
      my_putstr(instruction.op->comment);
      my_putstr("\n");
    }
*/
  return instruction;
}
