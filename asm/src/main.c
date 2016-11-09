/*
** main.c for asm in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Wed Nov  9 13:34:46 2016 Guillaume MARDON
** Last update Wed Nov  9 13:54:16 2016 Guillaume MARDON
*/
#include "../include/asm.h"

int	main(int argc, char **argv)
{
  int	index;

  if (argc >= 2)
    {
      index = 1;

      while (argv[index])
				{
	  				my_putstr("(");
	  				my_putstr(argv[index++]);
	  				my_putstr(") parsing... \n");
				}
    }
  else
    {
      my_putstr("Usage: ./asm file_name[.s] ....\n");
    }
}
