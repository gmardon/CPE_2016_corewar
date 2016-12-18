/*
** print.c for corewar in /home/aurelien/home/aurelien.olibe/delivery/CPE_2016_corewar/corewar/src/core
**
** Made by Aurelien
** Login   <aurelien.olibe@epitech.eu@epitech.net>
**
** Started on  Thu Dec  1 15:21:14 2016 Aurelien
** Last update Thu Dec 15 10:37:06 2016 Aurelien
*/
#include "core.h"

void		print_arena(t_corewar *core)
{
  unsigned char	*hex;
  ssize_t	i;

  i = 0;
  while (i < MEM_SIZE)
    {
      hex = hex_conv(core->arena[i]);
      if ((i % 32) == 0 && i != 0)
	write(1, "\n", 1);
      if (core->arena[i] != 0)
	write(1, "\033[34m\033[1m", 10);
      else
	write(1, "\033[0m", 5);
      write(1, hex, 2);
      write(1, " ", 1);
      free(hex);
      i++;
    }
  write(1, "\n", 1);
}

unsigned char	*hex_conv(unsigned char c)
{
  ssize_t	base;
  unsigned char	*hex;

  base = 16;
  if ((hex = malloc(sizeof(char) * 3)) == NULL)
    print_err(MALLOC_FAIL);
  hex[2] = '\0';
  hex[1] = (c % base);
  c = c - (c % base);
  if (hex[1] > 9)
    hex[1] = (hex[1] - 10) + 'a';
  else
    hex[1] = hex[1] + '0';
  hex[0] = (c / base);
  if (hex[0] > 9)
    hex[0] = (hex[0] - 10) + 'a';
  else
    hex[0] = hex[0] + '0';
  return (hex);
}

void	print_err(char *str)
{
  write(1, "Error: ", 7);
  write(1, str, my_strlen(str));
  write(1, "\n", 1);
  exit(84);
}

void	print_err_no_exit(char *str)
{
  write(1, "Error: ", 7);
  write(1, str, my_strlen(str));
  write(1, "\n", 1);
}

void	print_usage()
{
  write(1, "USAGE\n", 6);
  write(1, "         ./corewar ", 19);
  write(1, "[-dump nbr_cycle] [[-n prog_number] [-a load_address] ", 54);
  write(1, "prog_name] ...\n\n", 16);
  write(1, "DESCRIPTION\n", 12);
  write(1, "        -dump nbr_cycle dumps the memory after the nbr_cycle", 60);
  write(1, " execution (if the\n                        round isn't", 54);
  write(1, " already over) with the following format:  \n", 44);
  write(1, "                        32 byte/line in hexadecimal ", 52);
  write(1, "(AOBCDEFE1DD3...)\n", 18);
  write(1, "        -n prog_number  sets the next program's number.", 55);
  write(1, "  By default, the first\n                        ", 48);
  write(1, "free number in the parameter order\n", 35);
  write(1, "        -a load_address sets the next program's loading ", 56);
  write(1, "address.  When no\n                        ", 42);
  write(1, "address is specified, optimize the addresses", 44);
  write(1, " so that the\n                        ", 37);
  write(1, "proccesses are as far away form each other as ", 46);
  write(1, "possible.\n                        ", 34);
  write(1, "The addresses are MEM_SIZE modulo\n", 34);
}
