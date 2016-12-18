/*
** args_compiler.c for asm in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/compiler/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Mon Dec  5 16:27:42 2016 Guillaume MARDON
** Last update Sun Dec 18 12:32:36 2016 Guillaume MARDON
*/
#include "../../include/asm.h"

void	write_args(instruction_t *instruction, buffer_t *buffer, labelref_t *refs)
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
				write_register(op,
					       my_str_to_char(args->argv[args_index] + 1), buffer);
      if (args->type[args_index] == T_DIR)
				write_direct(op, args->argv[args_index] + 1, buffer, refs);
      if (args->type[args_index] == T_IND)
				write_indirect(op, args->argv[args_index], buffer, refs);
      args_index++;
    }
}

void	write_register(op_t *op, char value, buffer_t *buffer)
{
	buffer->data[buffer->index++] = value;
}

void	write_direct(op_t *op, char *value, buffer_t *buffer, labelref_t *refs)
{
  labelref_t *ref;

  ref = my_malloc(sizeof(labelref_t));
  ref->name = value + 1;
  ref->is_direct = 1;
  ref->index = buffer->index;
  if (op->code == 11 || op->code == 10 || op->code == 9
      || op->code == 12 || op->code == 14 || op->code == 15)
    {
      if (*value == ':')
				write_empty(ref->size = 2, buffer);
      else
				write_int_2(my_str_to_int(value), buffer);
    }
  else
    {
      if (*value == ':')
        write_empty(ref->size = 4, buffer);
      else
				write_int_4(my_str_to_int(value), buffer);
    }
  	if (*value == ':')
    	add_ref(refs, ref);
  	else
    	free(ref);
}

void	write_indirect(op_t *op, char *value, buffer_t *buffer, labelref_t *refs)
{
  labelref_t *ref;
  if (*value == ':')
    {
      ref = my_malloc(sizeof(labelref_t));
      ref->name = value + 1;
      ref->is_direct = 1;
      ref->index = buffer->index;
      ref->size = 2;

      add_ref(refs, ref);
      write_empty(2, buffer);
    }
  else
    write_int_2(my_str_to_int(value), buffer);
}
