/*
** compiler.c for corewar in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/compiler/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Tue Nov 15 11:27:08 2016 Guillaume MARDON
** Last update Mon Dec 12 18:46:32 2016 Guillaume MARDON
*/
#include "../../include/asm.h"

buffer_t	*compile(int *size, program_t *program)
{
  buffer_t *header_buffer;
  buffer_t *instructions_buffer;
  buffer_t *buffer;
  int instructions_size;
  int header_size;

  instructions_size = 0;
  header_size = 0;
  instructions_buffer = create_instructions(program->first_instruction,
					    &instructions_size);
  header_buffer = create_header(program->name, program->comment,
				instructions_size, &header_size);

  buffer = create_buffer(instructions_size + header_size);
  write_to_buffer(buffer, header_buffer->data, header_size);
  write_to_buffer(buffer, instructions_buffer->data, instructions_size);

  *size = buffer->index;
  return (buffer);
}
