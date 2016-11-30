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

t_champion *code2champ(t_code_champ *code, t_corewar *core)
{
  t_champion *champ;

  code->i = 0;
  champ = init_champ();
  champ->head->magic = parse_magic(code, champ);
  parse_name(code, champ);
  champ->head->prog_size = parse_prog_size(code);
  parse_comment(code, champ);
  if (core->champions == NULL)
    core->champions = champ;
  else
    add_new_champ(core, champ);
  code2arena(code, core, champ);
  return (champ);
}

void add_new_champ(t_corewar *core, t_champion *ch)
{
  t_champion *tmp;

  tmp = core->champions;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = ch;
}

void code2arena(t_code_champ *code, t_corewar *core, t_champion *ch)
{
  int nb_champ;
  t_champion *ch_tmp;
  ssize_t i;
  ssize_t j;

  nb_champ = i = 0;
  ch_tmp = core->champions;
  while (ch_tmp != NULL)
  {
    ch_tmp = ch_tmp->next;
    nb_champ++;
  }
  i = (MEM_SIZE / 4) * (nb_champ - 1);
  if ((ch->PC = malloc(sizeof(char *) * (code->len + 1 - code->i))) == NULL)
    exit(84);
  ch->PC[code->len - code->i] = NULL;
  while (code->i < code->len)
  {
    core->arena[i] = code->str[code->i];
    ch->PC[ch->i] = (core->arena + i);
    code->i++;
    ch->i++;
    i++;
  }
  ch->PC[ch->i] = NULL;
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

t_champion *init_champ()
{
  t_champion *champ;
  ssize_t i;

  i = 0;
  if ((champ = malloc(sizeof(t_champion))) == NULL)
    exit(84);
  champ->next = NULL;
  champ->PC = NULL;
  if ((champ->head = malloc(sizeof(header_t))) == NULL)
    exit(84);
  champ->carry = champ->i = 0;
  if ((champ->reg = malloc(sizeof(int) * REG_NUMBER)) == NULL)
    exit(84);
  while (i < REG_NUMBER)
  {
    champ->reg[i] = 0;
    i++;
  }
  return (champ);
}

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
