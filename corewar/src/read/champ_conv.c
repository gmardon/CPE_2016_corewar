/*
** champ_conv.c for corewar in /home/aurelien/home/aurelien.olibe/delivery/CPE_2016_corewar/corewar/src/read
**
** Made by Aurelien
** Login   <aurelien.olibe@epitech.eu@epitech.net>
**
** Started on  Tue Nov 29 18:52:08 2016 Aurelien
** Last update Tue Nov 29 18:52:09 2016 Aurelien
*/
#include "read_core.h"

t_champion *code2champ(t_code_champ *code)
{
  t_champion *champ;

  code->i = 0;
  champ = init_champ();
  champ->name = parse_name(code);
  champ->comment = parse_comment(code);
  // rest of .cor into arena
  // set PC with arena
  return (champ);
}

t_champion *init_champ()
{
  t_champion *champ;
  ssize_t i;

  i = 0;
  if ((champ = malloc(sizeof(t_champion))) == NULL)
    exit(84);
  champ->next = NULL;
  champ->PC = NULL;
  champ->file_name = champ->name =  NULL;
  champ->comment = NULL;
  champ->carry = 0;
  if ((champ->reg = malloc(sizeof(int) * REG_NUMBER)) == NULL)
    exit(84);
  while (i < REG_NUMBER)
  {
    champ->reg[i] = 0;
    i++;
  }
  return (champ);
}

char *parse_comment(t_code_champ *code)
{
  char *comm;
  ssize_t j;
  int cond;

  j = 0;
  if ((comm = malloc(sizeof(char) * COMMENT_LENGTH + 1)) == NULL)
    exit(84);
  while (code->i < (PROG_NAME_LENGTH + COMMENT_LENGTH))
  {
    cond = (code->str[code->i] >= 32 && code->str[code->i] < 127);
    if (code->str[code->i] != '\0' && cond)
    {
      comm[j] = code->str[code->i];
      j++;
    }
    code->i++;
  }
  comm[j] = '\0';
  return (comm);
}

char *parse_name(t_code_champ *code)
{
  char *name;
  ssize_t j;
  int cond;

  j = 0;
  if ((name = malloc(sizeof(char) * PROG_NAME_LENGTH + 1)) == NULL)
    exit(84);
  while (code->i < PROG_NAME_LENGTH)
  {
    cond = (code->str[code->i] >= 32 && code->str[code->i] < 127);
    if (code->str[code->i] != '\0' && cond)
    {
      name[j] = code->str[code->i];
      j++;
    }
    code->i++;
  }
  name[j] = '\0';
  return (name);
}

unsigned char *hex_conv(unsigned char c)
{
  ssize_t base;
  ssize_t i;
  char *hex;
  unsigned char tmp;

  base = 16;
  i = 0;
  if ((hex = malloc(sizeof(char) * 3)) == NULL)
    exit(84);
  hex[2] = '\0';
  hex[1] = (c % base);
  c = c - (c % base);
  if (hex[1] > 9)
    hex[1] = (hex[1] - 10) + 'a';
  else
    hex[1] = hex[1] + '0';
  hex[0] = (c / base);
  if (hex[0] > 9)
    hex[0] = (hex[0] - 10) + 'a';
  else
    hex[0] = hex[0] + '0';
  return (hex);
}
