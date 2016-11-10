/*
** parser.c for corewar in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/parser/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Wed Nov  9 13:25:17 2016 Guillaume MARDON
** Last update Thu Nov 10 11:31:55 2016 Guillaume MARDON
*/
#include "../../include/asm.h"

int	parse(const int fd)
{
  char	*line;

  while (*(line = get_next_line(fd)) != '\0')
    {
      if (*line == '.')
				{

				}
      else
				{
	  			read_instruction(line);
				}
    }
}

int	parse_file(char* file_name)
{
  int	fd;

  if ((fd = open(file_name, O_RDONLY)) == -1)
    {
    		my_putstr("Error in function open: No such file or directory.\n");
    }
  else
    {
      parse(fd);
    }
}
