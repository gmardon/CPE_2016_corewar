/*
** my_converter.c for asm in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/src/utils/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Tue Dec  6 09:40:19 2016 Guillaume MARDON
** Last update Tue Dec  6 09:40:34 2016 Guillaume MARDON
*/
int		my_int_convert(int i)
{
  char		tmp;
  char		*s;

  s = (char *) &i;
  tmp = s[3];
  s[3] = s[0];
  s[0] = tmp;
  tmp = s[2];
  s[2] = s[1];
  s[1] = tmp;
  return (i);
}
