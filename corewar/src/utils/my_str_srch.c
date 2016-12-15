/*
** my_str_srch.c for Corewar in /home/aurelien/home/aurelien.olibe/delivery/CPE_2016_corewar/corewar/src/utils
**
** Made by Aurelien
** Login   <aurelien.olibe@epitech.eu@epitech.net>
**
** Started on  Tue Dec  6 12:13:21 2016 Aurelien
** Last update Thu Dec 15 11:02:56 2016 Aurelien
*/
#include "core.h"

int		my_str_srch(char *to_search, char *str)
{
  ssize_t	i;
  ssize_t	j;
  int		bol;
  int		ret;
  int		cond;

  i = j = bol = ret = 0;
  while (bol == 0 && str[i] != '\0')
    {
      j = 0;
      cond = (to_search[j] != '\0' || str[i] != '\0');
      while (to_search[j] == str[i] && cond)
	{
	  bol = 1;
	  j++;
	  i++;
	  cond = (to_search[j] != '\0' || str[i] != '\0');
	}
      if (bol == 1 && to_search[j] == '\0')
	ret = 1;
      else
	bol = 0;
      i++;
    }
  return (ret);
}
