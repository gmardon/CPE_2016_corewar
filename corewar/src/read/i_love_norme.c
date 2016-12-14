/*
** i_love_norme.c for corewar in /home/aurelien/home/aurelien.olibe/delivery/CPE_2016_corewar/corewar
**
** Made by Aurelien
** Login   <aurelien.olibe@epitech.eu@epitech.net>
**
** Started on  Wed Dec 14 13:02:41 2016 Aurelien
** Last update Wed Dec 14 13:02:42 2016 Aurelien
*/
#include "read_core.h"

int parse_arg_intro(t_corewar *core, int ac, char **av, ssize_t j)
{
  if (j < ac && av[j][0] == '-')
    j = parse_arg(core, ac, av, j);
  if (av[j] == NULL)
    return (-1);
  return (j);
}
