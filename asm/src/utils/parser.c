/*
** parser.c for corewar in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/parser/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Wed Nov  9 13:25:17 2016 Guillaume MARDON
** Last update Tue Nov 22 15:52:49 2016 Guillaume MARDON
*/
#include "../../include/asm.h"

instruction_t	*parse(const int fd)
{
  char	*line;
  instruction_t *first_instruction;
  instruction_t *last_instruction;
  instruction_t *current_instruction;

  last_instruction = NULL;
  while (*(line = get_next_line(fd)) != '\0')
    {
      if (*line == '.')
				{

				}
      else
				{
	  			current_instruction = read_instruction(line);
          if (last_instruction)
            last_instruction->next = current_instruction;
	  			else
	    			first_instruction = current_instruction;
	  			last_instruction = current_instruction;
				}
    }
  return (first_instruction);
}

int	parse_file(char* file_name)
{
  int	fd;

  if ((fd = open(file_name, O_RDONLY)) == -1)
    {
      my_putstr("Error in function open: No such file or directory.\n");
      exit(84);
    }
  else
    {
      parse(fd);
    }
}
