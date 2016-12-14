/*
** get_next_line.c for get_next_line in /home/aurelien.olibe/delivery/CPE_2016_getnextline
**
** Made by Aurelien
** Login   <aurelien.olibe@epitech.eu@epitech.net>
**
** Started on  Tue Nov 22 11:10:18 2016 Aurelien
** Last update Fri Dec  2 22:07:20 2016 Aurelien
*/
#include <unistd.h>
#include "get_next_line.h"

char			*get_next_line(const int fd)
{
  static char		buffer[READ_SIZE + 1] = {'\0'};
  static ssize_t	i = 0;
  ssize_t		readed;
  char			*new;

  new = NULL;
  while (buffer[i] != '\0')
    {
      if ((new = buffer2str(buffer, &i, new)) == NULL)
	return (NULL);
      if (buffer[i] == '\n')
	{
	  i++;
	  return (new);
	}
      if ((readed = read(fd, buffer, READ_SIZE)) == 0 || readed == -1)
	return (new);
      i = 0;
      buffer[readed] = '\0';
    }
  i = 0;
  if ((readed = read(fd, buffer, READ_SIZE)) == 0 || readed == -1)
    return (NULL);
  buffer[readed] ='\0';
  return (get_next_line(fd));
}

char		*my_realloc(char *str, ssize_t aloc, ssize_t *j)
{
  char		*new;
  ssize_t	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  if ((new = malloc(sizeof(char) * (i + aloc))) == NULL)
    return (NULL);
  new[i + aloc - 1] = '\0';
  i = 0;
  while (str[i] != '\0')
    {
      new[i] = str[i];
      i++;
    }
  *j = i;
  free(str);
  return (new);
}

char		*buffer2str(char *buffer, ssize_t *i, char *new)
{
  ssize_t	j;
  ssize_t	k;

  j = *i;
  k = 0;
  while (buffer[j] != '\n' && buffer[j] != '\0')
    j++;
  if (new != NULL)
    {
      if ((new = my_realloc(new, (j - *i + 2), &k)) == NULL)
	return (NULL);
    }
  else if ((new = malloc(sizeof(char) * (j - *i + 2))) == NULL)
    return (NULL);
  while (buffer[*i] != '\n' && buffer[*i] != '\0')
    {
      new[k] = buffer[*i];
      k++;
      *i = *i + 1;
    }
  new[k] = '\0';
  return (new);
}
