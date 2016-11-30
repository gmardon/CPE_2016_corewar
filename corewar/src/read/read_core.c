/*
** read_core.c for Corewar in /home/aurelien.olibe/delivery/CPE_2016_corewar/corewar/src
**
** Made by Aurelien Olibe
** Login   <aurelien.olibe@epitech.net>
**
** Started on  Wed Nov 16 18:25:41 2016 Aurelien Olibe
** Last update Wed Nov 16 18:25:42 2016 Aurelien Olibe
*/
#include "read_core.h"

int read_core(int ac, char **av)
{
  t_code_champ *ch;
  t_champion *champ;
  int i;

  i = 1;
  while (i < ac)
    {
      // check if .cor
      ch = cor2str(av[i]);
      champ = code2champ(ch);
      free(ch); //to do: real free_code
      //print_cor(ch1);
      i++;
    }
  return (0);
}

void init_str(char *str, int max)
{
  int i;

  i = 0;
  while (i < max)
    {
      str[i] = '\0';
      i++;
    }
}

ssize_t get_file_size(char *file)
{
  int fd;
  ssize_t readed;
  ssize_t size;
  char buf[BUFF_SIZE];

  size = readed = 0;
  if ((fd = open(file, O_RDONLY)) == -1)
    exit(84);
  while ((readed = read(fd, buf, BUFF_SIZE)) > 0)
    size = size + readed;
  close(fd);
  return (size);
}

t_code_champ *cor2str(char *file)
{
  unsigned char *str;
  int fd;
  ssize_t readed;
  ssize_t i;
  ssize_t file_size;
  t_code_champ *ch1;

  readed = file_size = i = 0;
  if ((fd = open(file, O_RDONLY)) == -1)
    exit(84);
  file_size = get_file_size(file);
  if ((str = malloc(sizeof(char) * (file_size + 1))) == NULL)
    exit(84);
  while ((readed = read(fd, (str + i), file_size)) > 0 && i <= file_size)
    i = i + readed;
  if ((ch1 = malloc(sizeof(t_code_champ))) == NULL)
    exit(84);
  ch1->str = str;
  ch1->len = file_size;
  close(fd);
  return (ch1);
}
