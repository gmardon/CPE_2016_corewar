/*
** header_compiler.c for asm in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/compiler/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Mon Dec  5 16:37:09 2016 Guillaume MARDON
** Last update Tue Dec  6 09:43:27 2016 Guillaume MARDON
*/
#include "../../include/asm.h"

void	add_magic(char* buffer, int *index)
{
  int magic = COREWAR_EXEC_MAGIC;
  char m1 = (magic >> 16) & 0xff;
  char m2 = (magic >> 8) & 0xff;
  char m3 = magic & 0xff;
  buffer[*index] = 0x00;
  *index += 1;
  buffer[*index] = m1;
  *index += 1;
  buffer[*index] = m2;
  *index += 1;
  buffer[*index] = m3;
  *index += 1;
}

char	*create_header(char *name, char *comment, int instruction_size, int *size)
{
  char *buffer;
  int index;

  index = 0;
  buffer = my_malloc(sizeof(char *) * (COMMENT_LENGTH + PROG_NAME_LENGTH + 4));

  if (!name)
    name = "";
  if (!comment)
    comment = "";

  add_magic(buffer, &index);
  write_to_buffer(buffer, &index,
		  right_padding(name, my_strlen(name),
				PROG_NAME_LENGTH), PROG_NAME_LENGTH);

	write_to_buffer(buffer, &index,
    	right_padding(comment, my_strlen(comment),
		      COMMENT_LENGTH), COMMENT_LENGTH);

  *size = index;
  return (buffer);
}
