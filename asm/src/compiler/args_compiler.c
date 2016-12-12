/*
** args_compiler.c for asm in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/compiler/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Mon Dec  5 16:27:42 2016 Guillaume MARDON
** Last update Mon Dec 12 17:15:01 2016 Guillaume MARDON
*/
#include "../../include/asm.h"

void	write_args(instruction_t *instruction, int *index, char *buffer)
{
  int	args_index;
  op_t *op;
  args_t *args;

  args_index = 0;
  args = instruction->args;
  op = instruction->op;
  while (args->type[args_index])
    {
      if (args->type[args_index] == T_REG)
				write_register(op, *(args->argv[args_index] + 1) - 48,
					       index, buffer);
      if (args->type[args_index] == T_DIR)
				write_direct(op, args->argv[args_index] + 1, index, buffer);
      if (args->type[args_index] == T_IND)
				write_indirect(op, args->argv[args_index], index, buffer);
      args_index++;
    }
}

void	write_register(op_t *op, char value, int *index, char *buffer)
{
	buffer[*index] = value;
  *index += 1;
}

void	write_direct(op_t *op, char *value, int *index, char *buffer)
{
  if (op->code == 11 || op->code == 10 || op->code == 9
      || op->code == 12 || op->code == 14 || op->code == 15)
    {
      if (*value == ':')
        {
          write_empty(2, index, buffer);
        }
      else
				write_int_2(my_str_to_int(value), index, buffer);
    }
  else
    {
      if (*value == ':')
        {
          write_empty(4, index, buffer);
        }
      else
				write_int_4(my_str_to_int(value), index, buffer);
    }
}

void	write_indirect(op_t *op, char *value, int *index, char *buffer)
{
  if (*value == ':')
    {
      write_empty(2, index, buffer);
    }
  else
    write_int_2(my_str_to_int(value), index, buffer);
}
