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

t_corewar *read_core(int ac, char **av)
{
  t_code_champ *ch;
  t_corewar *core;
  int i;

  i = 1;
  core = init_corewar();
  while (i < ac)
    {
      if ((my_str_srch(".cor", av[i])) != 1)
        print_err(COR_FILE_FAIL);
      ch = cor2str(av[i]);
      code2champ(ch, core, i);
      free(ch); //to do: real free_code
      i++;
    }
  return (core);
}

t_corewar *init_corewar()
{
  t_corewar *core;
  ssize_t i;

  i = 0;
  if ((core = malloc(sizeof(t_corewar))) == NULL)
    print_err(MALLOC_FAIL);
  if ((core->arena = malloc(sizeof(char) * MEM_SIZE)) == NULL)
    print_err(MALLOC_FAIL);
  while (i < MEM_SIZE)
  {
    core->arena[i] = 0;
    i++;
  }
  core->live_on_this_cycle = 0;
  core->last_live_id = 0;
  core->nbr_live_cur = NBR_LIVE;
  core->n_delta = 0;
  core->champions = NULL;
  return (core);
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
    print_err(OPEN_FAIL);
  while ((readed = read(fd, buf, BUFF_SIZE)) > 0)
    size = size + readed;
  close(fd);
  if ((size - 2192) > (MEM_SIZE / 4))
    print_err(FILESIZE_MAX_FAIL);
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
    print_err(OPEN_FAIL);
  file_size = get_file_size(file);
  if ((str = malloc(sizeof(char) * (file_size + 1))) == NULL)
    print_err(MALLOC_FAIL);
  while ((readed = read(fd, (str + i), (file_size - i))) > 0 && i <= file_size)
    i = i + readed;
  if ((ch1 = malloc(sizeof(t_code_champ))) == NULL)
    print_err(MALLOC_FAIL);
  ch1->str = str;
  ch1->len = file_size;
  close(fd);
  return (ch1);
}
