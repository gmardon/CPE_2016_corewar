/*
** my_strcmp.c for emacs in /home/aurelien.olibe/delivery/main
**
** Made by Aurelien Olibe
** Login   <aurelien.olibe@epitech.net>
**
** Started on  Mon Oct 10 17:16:51 2016 Aurelien Olibe
** Last update Tue Oct 11 12:44:08 2016 Aurelien Olibe
*/

int	test_strcmp(int result, char *s1, char *s2, int i)
{
  if (s1[i] == '\0')
    result = -s2[i];
  else if (s2[i] == '\0')
    result = s1[i];
  else if (s1[i] == s2[i])
    result = 0;
  else
    result = s1[i] - s2[i];
  return (result);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	result;
  int	bool;

  i = 0;
  result = 0;
  bool = 0;
  while (result == 0 && bool == 0)
    {
      if (s1[i] == '\0' && s2[i] == '\0')
	{
	  result = 0;
	  bool = 1;
	}
      else
	result = test_strcmp(result, s1, s2, i);
      i++;
    }
  return (result);
}
