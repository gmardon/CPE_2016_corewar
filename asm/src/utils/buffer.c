/*
** buffer.c for asm in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/utils/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Mon Dec  5 17:10:27 2016 Guillaume MARDON
** Last update Sun Dec 18 10:57:47 2016 Guillaume MARDON
*/
#include "../../include/asm.h"

void	write_to_buffer(buffer_t *buffer, char *to_write, int size)
{
  int aindex;

  aindex = 0;
  while (aindex < size)
    {
      buffer->data[buffer->index++] = to_write[aindex++];
    }
}

void write_int_2(int value, buffer_t *buffer)
{
  char bytes[4];

  bytes[0] = (value >> 24) & 0xFF;
  bytes[1] = (value >> 16) & 0xFF;
  bytes[2] = (value >> 8) & 0xFF;
  bytes[3] = value & 0xFF;

  buffer->data[buffer->index++] = bytes[2];
  buffer->data[buffer->index++] = bytes[3];
}

void	write_int_4(int value, buffer_t *buffer)
{
  char bytes[4];

  bytes[0] = (value >> 24) & 0xFF;
  bytes[1] = (value >> 16) & 0xFF;
  bytes[2] = (value >> 8) & 0xFF;
  bytes[3] = value & 0xFF;

  buffer->data[buffer->index++] = bytes[0];
  buffer->data[buffer->index++] = bytes[1];
  buffer->data[buffer->index++] = bytes[2];
  buffer->data[buffer->index++] = bytes[3];
}

void	write_empty(int count, buffer_t *buffer)
{
  int actual_index;

  actual_index = 0;
  while (actual_index < count)
    {
      buffer->data[buffer->index++] = 0x00;
      actual_index++;
    }
}

buffer_t	*create_buffer(int size)
{
  buffer_t *buffer;

  buffer = my_malloc(sizeof(buffer_t));
  buffer->index = 0;
  buffer->data = my_malloc(size * sizeof(char*));

  return (buffer);
}
