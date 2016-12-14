/*
** my_strdup.c for emacs in /home/aurelien.olibe/delivery/main
**
** Made by Aurelien Olibe
** Login   <aurelien.olibe@epitech.net>
**
** Started on  Wed Oct 12 14:39:44 2016 Aurelien Olibe
** Last update Wed Dec 14 14:30:36 2016 Aurelien
*/
#include <stdlib.h>

char	*my_strdup(char *src)
{
  char	*dest;
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      i++;
    }
  if ((dest = malloc(sizeof(char) * (i + 1))) == NULL)
    exit(84);
  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
