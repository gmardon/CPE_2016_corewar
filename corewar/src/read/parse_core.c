/*
** parse_core.c for corewar in /home/aurelien/home/aurelien.olibe/delivery/CPE_2016_corewar/corewar/src/read
**
** Made by Aurelien
** Login   <aurelien.olibe@epitech.eu@epitech.net>
**
** Started on  Thu Dec  1 15:22:07 2016 Aurelien
** Last update Thu Dec  1 15:22:12 2016 Aurelien
*/
#include "read_core.h"

ssize_t parse_arg(t_corewar *core, int ac, char **av, ssize_t j)
{
  if (my_strcmp(av[j], "-a") == 0 && ac > (j + 1))
    core->load_address = str2size(av[j + 1]);
  else if (my_strcmp(av[j], "-n") == 0 && ac > (j + 1))
  {
    if (av[j + 1][0] >= '1' && av[j + 1][0] <= '4' && av[j + 1][1] == '\0')
      core->prog_number = (av[j + 1][0] - '0');
    else
      print_err(N_ARG_INVALID);
  }
  else if (my_strcmp(av[j], "-dump") == 0 && ac > (j + 1))
    core->dump = str2size(av[j + 1]);
  else
    print_err(INVALID_ARG);
  j += 2;
  return (j);
}

void parse_comment(t_code_champ *code, t_champion *ch)
{
  ssize_t j;
  int cond;
  int bol;

  j = bol = 0;
  while (code->i < ((PROG_NAME_LENGTH + 4) + (COMMENT_LENGTH + 12)))
  {
    cond = (code->str[code->i] >= 32 && code->str[code->i] < 127);
    if (code->str[code->i] != '\0' && cond)
    {
      ch->head->comment[j] = code->str[code->i];
      j++;
      if (bol)
        print_err(HEADER_COMM_FAIL);
    }
    else if (code->str[code->i] == '\0')
      bol = 1;
    code->i++;
  }
  ch->head->comment[j] = '\0';
}

void parse_name(t_code_champ *code, t_champion *ch)
{
  ssize_t j;
  int cond;
  int bol;

  j = bol = 0;
  while (code->i < (PROG_NAME_LENGTH + 4))
  {
    cond = (code->str[code->i] >= 32 && code->str[code->i] < 127);
    if (code->str[code->i] != '\0' && cond)
    {
      ch->head->prog_name[j] = code->str[code->i];
      j++;
      if (bol)
        print_err(HEADER_NAME_FAIL);
    }
    else if (code->str[code->i] == '\0')
      bol = 1;
    code->i++;
  }
  ch->head->prog_name[j] = '\0';
}

int parse_magic(t_code_champ *code)
{
  char *exec_magic;
  ssize_t i;
  int magic;
  unsigned char *hex;

  exec_magic = my_strdup(COREWAR_EXEC_MAGIC);
  i = magic = 0;
  if (code->str[code->i] == 0 && exec_magic[i] == '0')
  {
    i += 2;
    code->i++;
    magic = 1;
  }
  while ((exec_magic[i] != '\0' && exec_magic[i + 1] != '\0') && magic == 1)
  {
    hex = hex_conv(code->str[code->i]);
    if (hex[0] == exec_magic[i] && hex[1] == exec_magic[i + 1])
      magic = 1;
    else
      magic = 0;
    free(hex);
    i += 2;
    code->i++;
  }
  return (magic);
}

int parse_prog_size(t_code_champ *code)
{
  int size;
  ssize_t i;
  ssize_t j;
  unsigned int value;

  size = 0;
  i = 1;
  code->i = code->i + 4;
  while (code->i < (PROG_NAME_LENGTH + 12))
  {
    j = (i - 1);
    value = ((j + 1) < 4) ? (1) : (0);
    while (++j < 4)
      value = (value * 256);
    if (code->str[code->i] != 0)
    {
      if (value > 0)
        size = size + (int) (code->str[code->i] * value);
      else
        size += (int) code->str[code->i];
    }
    code->i++;
    i++;
  }
  return (size);
}
