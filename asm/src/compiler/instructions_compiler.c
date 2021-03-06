/*
** instructions_compiler.c for asm in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/compiler/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Mon Dec  5 20:21:45 2016 Guillaume MARDON
** Last update Sun Dec 18 17:26:06 2016 Romain Goasdoue
*/

#include "../../include/asm.h"

void	resolve_labels(buffer_t *buffer, labelref_t *refs)
{
  int		index;
  labelref_t	*target;

  index = 0;
  while (refs[index].name != NULL)
    {
      if (refs[index].is_label == 0)
	{
	  target = find_label(refs, refs[index].name);
	  if (target->name)
	    {
	      buffer->index = refs[index].index;
	      if (target->index <= (refs[index].index + 2))
		write_int_2(65536 - (refs[index].index - target->index - 1), buffer);
	      else
		write_int_2((target->index + 3) - refs[index].index, buffer);
	    }
	}
      index++;
    }
}

buffer_t	*create_instructions(instruction_t *first_instruction, int *size)
{
  buffer_t	*buffer;
  instruction_t *instruction;
  int		args_index;
  labelref_t	*labelrefs;

  buffer = create_buffer(BUFF_SIZE);
  labelrefs = create_refs_stack();
  instruction = first_instruction;
  while (instruction)
    {
      if (instruction->label)
	add_label_ref(buffer->index, instruction->label, labelrefs);
      buffer->data[buffer->index++] = instruction->op->code;
      if (need_encode_args_type(instruction->op->code))
	buffer->data[buffer->index++] =
	  get_encoded_args_type(instruction->args->type);
      write_args(instruction, buffer, labelrefs);
      instruction = instruction->next;
    }
  resolve_labels(buffer, labelrefs);
  *size = buffer->index;
  return (buffer);
}
