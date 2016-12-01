/*
** print.c for corewar in /home/aurelien/home/aurelien.olibe/delivery/CPE_2016_corewar/corewar/src/core
** 
** Made by Aurelien
** Login   <aurelien.olibe@epitech.eu@epitech.net>
** 
** Started on  Thu Dec  1 15:21:14 2016 Aurelien
** Last update Thu Dec  1 15:21:19 2016 Aurelien
*/
#include "core.h"

void print_arena(t_corewar *core)
{
  char *hex;
  ssize_t i;

  i = 0;
  while (i < MEM_SIZE)
  {
    hex = hex_conv(core->arena[i]);
    if ((i % 24) == 0 && i != 0)
      write(1, "\n", 1);
    if (core->arena[i] != 0)
      write(1, "\033[34m\033[1m", 10);
    else
      write(1, "\033[0m", 5);
    write(1, hex, 2);
    write(1, " ", 1);
    i++;
  }
  write(1, "\n", 1);
}

unsigned char *hex_conv(unsigned char c)
{
  ssize_t base;
  ssize_t i;
  char *hex;
  unsigned char tmp;

  base = 16;
  i = 0;
  if ((hex = malloc(sizeof(char) * 3)) == NULL)
    exit(84);
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
