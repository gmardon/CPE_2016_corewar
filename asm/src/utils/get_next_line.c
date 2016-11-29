/*
** get_next_line.c for asm in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/utils/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Wed Nov  9 13:26:44 2016 Guillaume MARDON
** Last update Wed Nov  9 14:44:57 2016 Guillaume MARDON
*/
#include "../../include/asm.h"

char *get_next_line(const int fd)
{
  char	buffer[BUFF_SIZE];
	char	*resized_buffer;
  size_t	total_readed = 0;

  while ((read(fd, (buffer + total_readed), 1)) != 0
	 && buffer[total_readed] != '\n')
    {
      if ((total_readed + 1) > BUFF_SIZE)
			{
	  			break;
			}
      total_readed++;
    }
  buffer[total_readed] = '\0';
  resized_buffer = malloc(total_readed * sizeof(char*));
  my_strcpy(resized_buffer, buffer);
  resized_buffer[total_readed] = '\0';
  return (resized_buffer);
}
