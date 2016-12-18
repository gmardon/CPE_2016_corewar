/*
** my_strsep.c for my_exec in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/PSU_2016_my_exec/src/utils/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Mon Nov 21 16:26:00 2016 Guillaume MARDON
** Last update Sun Dec 18 17:59:21 2016 Romain Goasdoue
*/

#include "../../include/asm.h"

int	my_next_(char *str)
{
  int	index;

  index = 0;
  while (str[index] != '\0' && str[index] != ' ' && str[index] != '\t')
    index++;
  return (index);
}

int	my_total_(char *str)
{
  int	count;
  int	total;

  count = total = 0;
  while (*(str + total) != '\0')
    {
      if (my_next_(str + total) != 0)
	count++;
      total += my_next_(str + total) + 1;
    }
  return (count);
}

char	**my_commandsep(char *str)
{
  int	index;
  int	index_word;
  int	index_char;
  int	next_chars;
  char	**result;

  index = index_word = 0;
  result = my_malloc((my_total_(str) + 1) * (sizeof(char*) + 1));
  while (*(str + index) != '\0')
    {
      next_chars = my_next_(str + index);
      if (next_chars != 0)
	{
	  result[index_word] = my_malloc(next_chars * (sizeof(char*) + 1));
      	  index_char = 0;
	  while (index_char < next_chars)
	    result[index_word][index_char++] = str[index++];
      	  index_word++;
	}
      result[index_word - 1][index_char] = '\0';
      if (*(str + index++) == 0)
	break;
    }
  result[index_word] = '\0';
  return (result);
}
