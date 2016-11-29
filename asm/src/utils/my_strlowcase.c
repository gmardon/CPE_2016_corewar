/*
** my_strlowcase.c for my_strlowcase in /home/guillaume.mardon/delivery/CPool_Day06/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu>
**
** Started on  Mon Oct 10 08:58:41 2016 Guillaume MARDON
** Last update Tue Nov 29 16:39:11 2016 Guillaume MARDON
*/
#include "../../include/asm.h"

char 	*my_strlowcase(char *str)
{
  int	index;
  char *substr;

  index = 0;
  substr = malloc(my_strlen(str) * sizeof(char *));
  while (str[index] != '\0')
    {
      if (str[index] >= 'A' && str[index] <= 'Z')
				{
	  			substr[index] = str[index] + 32;
				}
      else
				substr[index] = str[index];
      index++;
    }
  substr[index] = '\0';
  return (substr);
}
