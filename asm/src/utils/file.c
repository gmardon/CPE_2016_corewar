/*
** file.c for asm in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/utils/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Mon Dec  5 15:57:13 2016 Guillaume MARDON
** Last update Sun Dec 18 18:28:13 2016 Aurelien
*/

#include "../../include/asm.h"

char	*filename_to_cor(char *file_path)
{
  int	index;
  int	last_index;
  char	*new;

  index = last_index = 0;
  while (file_path[index] != '\0')
    {
      if (file_path[index++] == '.')
	last_index = index;
    }
  if (last_index == 0)
    last_index = (my_strlen(file_path) + 1);
  new = malloc((last_index + 3) * sizeof(char*));
  my_strcpy(new, file_path);
  new[last_index - 1] = '.';
  new[last_index] = 'c';
  new[last_index + 1] = 'o';
  new[last_index + 2] = 'r';
  return (new);
}

void	save(int length, char* buffer, char* filepath)
{
  int	fd;

  fd = open(filepath, O_CREAT | O_WRONLY | O_TRUNC);
  if (fd == -1)
    {
      my_printf("Error in function open: No such file or directory.\n");
      exit(84);
    }
  write(fd, buffer, length);
  close(fd);
}
