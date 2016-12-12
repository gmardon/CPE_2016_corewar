/*
** compiler.c for corewar in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/compiler/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Tue Nov 15 11:27:08 2016 Guillaume MARDON
** Last update Mon Dec 12 17:14:50 2016 Guillaume MARDON
*/
#include "../../include/asm.h"

char	*compile(int *size, program_t *program)
{
  char *header_buffer;
  char *instructions_buffer;
  char *buffer;
  int instructions_size;
  int header_size;
  int index;

  index = 0;
  instructions_size = 0;
  header_size = 0;
  instructions_buffer = create_instructions(program->first_instruction,
					    &instructions_size);
  header_buffer = create_header(program->name, program->comment,
				instructions_size, &header_size);

  buffer = malloc(sizeof(char*) * (instructions_size + header_size));
  write_to_buffer(buffer, &index, header_buffer, header_size);
  write_to_buffer(buffer, &index, instructions_buffer, instructions_size);

  *size = index;
  return (buffer);
}
