/*
** my_strcmp.c for my_strcmp in /home/guillaume.mardon/delivery/CPool_Day06/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu>
**
** Started on  Mon Oct 10 08:58:41 2016 Guillaume MARDON
** Last update Mon Dec  5 20:54:35 2016 Guillaume MARDON
*/
#include "../../include/asm.h"

int 	my_strncmp(char *s1, char *s2, int size)
{
  int 	index;

  index = 0;
  while (s1[index] == s2[index])
    {
      if ((index + 1) == size)
				return (0);
      if (s1[index] == '\0' && s2[index] == '\0')
				{
	  			return (0);
				}
      index++;
    }
  return (s1[index] < s2[index] ? 1 : -1);
}
