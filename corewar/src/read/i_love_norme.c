/*
** i_love_norme.c for corewar in /home/aurelien/home/aurelien.olibe/delivery/CPE_2016_corewar/corewar
**
** Made by Aurelien
** Login   <aurelien.olibe@epitech.eu@epitech.net>
**
** Started on  Wed Dec 14 13:02:41 2016 Aurelien
** Last update Thu Dec 15 10:56:42 2016 Aurelien
*/
#include "read_core.h"

int	parse_arg_intro(t_corewar *core, int ac, char **av, ssize_t j)
{
  if (j < ac && av[j][0] == '-')
    j = parse_arg(core, ac, av, j);
  if (av[j] == NULL)
    return (-1);
  return (j);
}

void	do_dump(t_corewar *core)
{
  if (core->dump > 0)
    core->dump--;
  if (core->dump == 0)
    {
      print_arena(core);
      core->dump = -1;
    }
}
