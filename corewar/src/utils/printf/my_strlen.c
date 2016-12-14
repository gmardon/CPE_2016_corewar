/*
** my_strlen.c for emacs in /home/aurelien.olibe/delivery/main
**
** Made by Aurelien Olibe
** Login   <aurelien.olibe@epitech.net>
**
** Started on  Thu Oct  6 10:09:00 2016 Aurelien Olibe
** Last update Sat Nov 19 00:56:58 2016 Aurelien Olibe
*/
#include <stdlib.h>

ssize_t		my_strlen(const char *str)
{
  ssize_t	i;

  i = 0;
  while (str[i] != '\0')
    {
      i++;
    }
  return (i);
}
