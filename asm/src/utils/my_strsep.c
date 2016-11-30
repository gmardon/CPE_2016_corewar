/*
** my_strsep.c for my_exec in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/PSU_2016_my_exec/src/utils/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Mon Nov 21 16:26:00 2016 Guillaume MARDON
** Last update Wed Nov 30 15:07:37 2016 Guillaume MARDON
*/

int	my_next(char delimiter, char *str)
{
  int	index;

  index = 0;

  while (str[index] != '\0' && str[index] != delimiter)
      index++;

  return (index);
}

int	my_total(char delimiter, char *str)
{
  int	count;
  int	total;

  count = total = 0;
  while (*(str + total) != '\0')
    {
      if (my_next(delimiter, str + total) != 0)
				count++;
      total += my_next(delimiter, str + total) + 1;
    }
  return (count);
}

char	**my_strsep(char *str, char delim)
{
  int	index;
  int	index_word;
  int	index_char;
  int	next_chars;
  char	**result;

  index = index_word = 0;
  result = malloc((my_total(delim, str) + 1) * (sizeof(char*) + 2));
  while (*(str + index) != '\0')
    {
      next_chars = my_next(delim, str + index);
      if (next_chars != 0)
				{
    	    result[index_word] = malloc(next_chars * (sizeof(char*) + 1));
      	  index_char = 0;
    	    while (index_char < next_chars)
  	  			result[index_word][index_char++] = str[index++];
      	  index_word++;
	  		}
        if (*(str + index) == 0)
  				break;
        index++;
      }
    result[index_word] = '\0';
    return (result);
}
