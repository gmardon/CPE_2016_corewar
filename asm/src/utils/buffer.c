/*
** buffer.c for asm in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/utils/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Mon Dec  5 17:10:27 2016 Guillaume MARDON
** Last update Mon Dec 12 16:42:39 2016 Guillaume MARDON
*/
#include "../../include/asm.h"

char	*right_padding(char *data, int base_size, int requested_size)
{
  char *newdata;
  int index;

  newdata = malloc((requested_size) * sizeof(char*));
  index = 0;
  while (index < requested_size)
    {
      if (index < base_size)
				{
	  			newdata[index] = data[index];
				}
      else
				newdata[index] = 0;

      index++;
    }
  return (newdata);
}

void	write_to_buffer(char *buffer, int *index, char *to_write, int size)
{
  int aindex;

  aindex = 0;
  while (aindex < size)
    {
      buffer[*index] = to_write[aindex++];
      *index += 1;
    }
}

void write_int_2(int value, int *index, char *buffer)
{
  char bytes[4];

  bytes[0] = (value >> 24) & 0xFF;
  bytes[1] = (value >> 16) & 0xFF;
  bytes[2] = (value >> 8) & 0xFF;
  bytes[3] = value & 0xFF;

  buffer[*index] = bytes[2];
  *index += 1;
  buffer[*index] = bytes[3];
  *index += 1;
}

void	write_int_4(int value, int *index, char *buffer)
{
  char bytes[4];

  bytes[0] = (value >> 24) & 0xFF;
  bytes[1] = (value >> 16) & 0xFF;
  bytes[2] = (value >> 8) & 0xFF;
  bytes[3] = value & 0xFF;

  buffer[*index] = bytes[0];
  *index += 1;
  buffer[*index] = bytes[1];
  *index += 1;
  buffer[*index] = bytes[2];
  *index += 1;
  buffer[*index] = bytes[3];
  *index += 1;
}

void	write_empty(int count, int *index, char *buffer)
{
  int actual_index;

  actual_index = 0;
  while (actual_index < count)
    {
      buffer[*index] = 0x00;
      *index += 1;
      actual_index++;
    }
}
