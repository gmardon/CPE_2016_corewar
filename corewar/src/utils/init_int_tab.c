/*
** init_int_tab.c for corewar in /home/aurelien/home/aurelien.olibe/delivery/CPE_2016_corewar/corewar/src/utils
**
** Made by Aurelien
** Login   <aurelien.olibe@epitech.eu@epitech.net>
**
** Started on  Wed Dec  7 14:58:37 2016 Aurelien
** Last update Thu Dec 15 10:59:40 2016 Aurelien
*/
#include <stdlib.h>

void		init_int_tab(int *tab, ssize_t max)
{
  ssize_t	i;

  i = -1;
  while (++i < max)
    tab[i] = 0;
}
