/*
** parser.c for corewar in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/parser/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Wed Nov  9 13:25:17 2016 Guillaume MARDON
** Last update Sun Dec 18 17:43:57 2016 Romain Goasdoue
*/

#include "../../include/asm.h"

void	parse_extra(char *line, program_t *program)
{
  if (my_strncmp(NAME_CMD_STRING, line, my_strlen(NAME_CMD_STRING)) == 0)
    {
      line = line + (my_strlen(NAME_CMD_STRING));
      line = my_cleanstr(line);
      line++;
      line[my_indexof('\"', line)] = 0;
      program->name = line;
    }
  else if (my_strncmp(COMMENT_CMD_STRING, line,
		      my_strlen(COMMENT_CMD_STRING)) == 0)
    {
      line = line + (my_strlen(COMMENT_CMD_STRING));
      line = my_cleanstr(line);
      line++;
      line[my_indexof('\"', line)] = 0;
      program->comment = line;
    }
}

program_t	*parse(const int fd)
{
  char		*line;
  program_t	*program;
  instruction_t	*first_instruction;
  instruction_t *last_instruction;
  instruction_t *current_instruction;

  last_instruction = NULL;
  program = my_malloc(sizeof(program_t));
  while (line = get_next_line(fd))
    {
      line = my_cleanstr(line);
      if (!*line) continue;
      if (*line == '.' || *line == COMMENT_CHAR) parse_extra(line, program);
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
  program->first_instruction = first_instruction;
  return (program);
}

program_t	*parse_file(char* file_name)
{
  int	fd;

  if ((fd = open(file_name, O_RDONLY)) == -1)
    {
      my_putstr("Error in function open: No such file or directory.\n");
      exit(84);
    }
  else
    return (parse(fd));
}
