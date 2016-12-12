/*
** instruction.c for asm in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/parser/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Wed Nov  9 14:56:18 2016 Guillaume MARDON
** Last update Mon Dec 12 17:41:54 2016 Guillaume MARDON
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
  int index;

  index = 0;
  label = malloc(label_index(line) * sizeof(char*));
  my_strcpy(label, line);
  while (label[index] != ':')
    index++;
  label[index] = 0;
  return (label);
}

args_t	*retrieve_args(char *line)
{
  int		index;
	char	**args_c;
  args_t *args;

  index = 0;
  while (line[index] != 32 && line[index] != '\t')
    index++;
  line = my_cleanstr(line + index);
  args = malloc(sizeof(args_t));
  index = 0;
  args_c = my_strsep(line, ',');
  while (args_c[index])
    {
      args->argv[index] = my_cleanstr(args_c[index]);
      if (*args->argv[index] == DIRECT_CHAR)
				args->type[index] = T_DIR;
      else if (*args->argv[index] == 'r')
				args->type[index] = T_REG;
      else
				args->type[index] = T_IND;
      index++;
    }
  return (args);
}

op_t	*retrieve_op(char *line)
{
  char	*op;
  int		index;
	op_t 	*opt;

  opt = malloc(sizeof(op_t));
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

instruction_t	*read_instruction(char *line)
{
  instruction_t *instruction;

  instruction = malloc(sizeof(instruction_t));
  line = my_cleanstr(line);
  if (label_index(line) != 0)
    {
      instruction->label = retrieve_label(line);
      line += label_index(line);
      line = my_cleanstr(line);
    }
  else
    instruction->label = NULL;
	instruction->op = retrieve_op(line);
  instruction->args = retrieve_args(line);
  instruction->next = NULL;

  return instruction;
}
