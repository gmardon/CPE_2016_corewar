/*
** my_str_srch.c for Corewar in /home/aurelien/home/aurelien.olibe/delivery/CPE_2016_corewar/corewar/src/utils
**
** Made by Aurelien
** Login   <aurelien.olibe@epitech.eu@epitech.net>
**
** Started on  Tue Dec  6 12:13:21 2016 Aurelien
** Last update Tue Dec  6 12:13:21 2016 Aurelien
*/
#include "core.h"

int my_str_srch(char *to_search, char *str)
{
  ssize_t i;
  ssize_t j;
  int bol;
  int ret;

  i = j = bol = ret = 0;
  while (bol == 0 && str[i] != '\0')
  {
    while (to_search[j] == str[i] && (to_search[j] != '\0' || str[i] != '\0'))
    {
      bol = 1;
      j++;
      i++;
    }
    if (bol == 1 && to_search[j] == '\0')
      ret = 1;
    i++;
  }
  return (ret);
}
