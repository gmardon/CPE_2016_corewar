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

void parse_comment(t_code_champ *code, t_champion *ch)
{
  ssize_t j;
  int cond;

  j = 0;
  while (code->i < ((PROG_NAME_LENGTH + 4) + (COMMENT_LENGTH + 12)))
  {
    cond = (code->str[code->i] >= 32 && code->str[code->i] < 127);
    if (code->str[code->i] != '\0' && cond)
    {
      ch->head->comment[j] = code->str[code->i];
      j++;
    }
    code->i++;
  }
  ch->head->comment[j] = '\0';
}

void parse_name(t_code_champ *code, t_champion *ch)
{
  ssize_t j;
  int cond;

  j = 0;
  while (code->i < (PROG_NAME_LENGTH) + 4)
  {
    cond = (code->str[code->i] >= 32 && code->str[code->i] < 127);
    if (code->str[code->i] != '\0' && cond)
    {
      ch->head->prog_name[j] = code->str[code->i];
      j++;
    }
    code->i++;
  }
  ch->head->prog_name[j] = '\0';
}

int parse_magic(t_code_champ *code, t_champion *ch)
{
  char *exec_magic;
  ssize_t i;
  int magic;
  char *hex;

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

  size = 1;
  while (code->i < (PROG_NAME_LENGTH + 12))
  {
    if (code->str[code->i] != 0)
      size = size * code->str[code->i];
    code->i++;
  }
  return (size);
}
