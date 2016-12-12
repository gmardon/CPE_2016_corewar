/*
** header_compiler.c for asm in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/compiler/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Mon Dec  5 16:37:09 2016 Guillaume MARDON
** Last update Mon Dec 12 18:36:25 2016 Guillaume MARDON
*/
#include "../../include/asm.h"

void	add_magic(buffer_t *buffer)
{
  int magic = COREWAR_EXEC_MAGIC;
  char m1 = (magic >> 16) & 0xff;
  char m2 = (magic >> 8) & 0xff;
  char m3 = magic & 0xff;
  buffer->data[buffer->index++] = 0x00;
  buffer->data[buffer->index++] = m1;
  buffer->data[buffer->index++] = m2;
  buffer->data[buffer->index++] = m3;
}

buffer_t	*create_header(char *name, char *comment, int instruction_size, int *size)
{
  buffer_t *buffer;

  buffer = create_buffer(COMMENT_LENGTH + PROG_NAME_LENGTH + (4 * 3));

  if (!name)
    name = "";
  if (!comment)
    comment = "";

  add_magic(buffer);
  write_to_buffer(buffer,
		  right_padding(name, my_strlen(name),
				PROG_NAME_LENGTH), PROG_NAME_LENGTH);
  write_empty(4, buffer);
  write_int_4(instruction_size, buffer);
	write_to_buffer(buffer,
    	right_padding(comment, my_strlen(comment),
		      COMMENT_LENGTH), COMMENT_LENGTH);
  write_empty(4, buffer);
  *size = buffer->index;
  return (buffer);
}
