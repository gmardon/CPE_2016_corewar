/*
** my_strlen.c for my_strlen in /home/victor.le-dantec/CPool_Day04
**
** Made by Victor Le Dantec
** Login   <victor.le-dantec@epitech.net>
**
** Started on  Thu Oct  6 13:48:22 2016 Victor Le Dantec
** Last update Wed Nov  9 13:44:12 2016 Guillaume MARDON
*/

#include <stdlib.h>

size_t	my_strlen(char *str)
{
  size_t	i;

  i = 0;
  while (str[i] != '\0')
    {
      i++;
    }
  return (i);
}
