/*
** main.c for asm in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Wed Nov  9 13:34:46 2016 Guillaume MARDON
** Last update Sun Dec 18 12:36:06 2016 Guillaume MARDON
*/
#include "../include/asm.h"

int	main(int argc, char **argv)
{
  int	index;
  buffer_t *buffer;
  int *size;

  size = my_malloc(sizeof(int));
  if (argc >= 2)
    {
      index = 0;

      while (argv[++index])
				{
	  			buffer = compile(size, parse_file(argv[index]));
	      	save(*size, buffer->data, filename_to_cor(argv[index]));
				  filename_to_cor(argv[index]));
				}
    }
  else
    {
      my_printf("Usage: ./asm file_name[.s] ....\n");
    }
}
