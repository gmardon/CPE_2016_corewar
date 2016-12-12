/*
** main.c for asm in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Wed Nov  9 13:34:46 2016 Guillaume MARDON
** Last update Mon Dec 12 18:38:29 2016 Guillaume MARDON
*/
#include "../include/asm.h"

int	main(int argc, char **argv)
{
  int	index;
  buffer_t *buffer;
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
	      		save(*size, buffer->data, filename_to_cor(argv[index]));
	      		my_printf("(%s) saved to %s...\n", argv[index],
				  filename_to_cor(argv[index]));
				}
    }
  else
    {
      my_putstr("Usage: ./asm file_name[.s] ....\n");
    }
}
