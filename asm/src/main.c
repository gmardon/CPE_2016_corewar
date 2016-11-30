/*
** main.c for asm in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Wed Nov  9 13:34:46 2016 Guillaume MARDON
** Last update Wed Nov 30 12:15:35 2016 Guillaume MARDON
*/
#include "../include/asm.h"

char *filename_to_cor(char *file_path)
{
  int	index;
	int last_index;
  char *new;

  index = last_index = 0;
  while (file_path[index] != '\0')
    if (file_path[index++] == '.')
			last_index = index;

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
  int fd;

  fd = open(filepath, O_CREAT | O_WRONLY | O_TRUNC);
  if (fd == -1)
		{
      my_printf("Error in function open: No such file or directory.\n");
      exit(84);
		}
  write(fd, buffer, length);

  close(fd);
}

int	main(int argc, char **argv)
{
  int	index;
  char *buffer;
  int *size;

  size = malloc(sizeof(int));
  if (argc >= 2)
    {
      index = 0;

      while (argv[++index])
				{
	  				my_printf("(%s) compiling...\n", argv[index]);
	      		buffer = compile(size, parse_file(argv[index]));
	      		my_printf("(%s) buffer size: %d\n", argv[index], *size);
	      		save(*size, buffer, filename_to_cor(argv[index]));
	      		my_printf("(%s) saved to %s...\n", argv[index], filename_to_cor(argv[index]));
				}
    }
  else
    {
      my_putstr("Usage: ./asm file_name[.s] ....\n");
    }
}
