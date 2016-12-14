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

t_champion *code2champ(t_code_champ *code, t_corewar *core, int i, ssize_t total_ch)
{
  t_champion *champ;

  code->i = 0;
  champ = init_champ(i);
  if ((champ->head->magic = parse_magic(code)) == 0)
    print_err_no_exit(MAGIC_FAIL);
  parse_name(code, champ);
  if ((champ->head->prog_size = parse_prog_size(code)) != (code->len - 2192))
    print_err_no_exit(PROG_SIZE_FAIL);
  parse_comment(code, champ);
  if (core->champions == NULL)
    core->champions = champ;
  else
    add_new_champ(core, champ);
  code2arena(code, core, champ, total_ch);
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

void code2arena(t_code_champ *code, t_corewar *core, t_champion *ch, ssize_t total_ch)
{
  int nb_champ;
  t_champion *ch_tmp;
  ssize_t i;

  nb_champ = i = 0;
  ch_tmp = core->champions;
  while (ch_tmp != NULL)
  {
    ch_tmp = ch_tmp->next;
    nb_champ++;
  }
  if (core->load_address != 0)
    i = (core->load_address % MEM_SIZE);
  else
    i = (MEM_SIZE / total_ch) * (nb_champ - 1);
  core->load_address = 0;
  ch->PC = i;
  while (code->i < code->len)
  {
    core->arena[i] = code->str[code->i];
    code->i++;
    i++;
  }
}

t_champion *init_champ(int id)
{
  t_champion *champ;
  ssize_t i;

  i = 0;
  if ((champ = malloc(sizeof(t_champion))) == NULL)
    print_err(MALLOC_FAIL);
  champ->next = NULL;
  if ((champ->head = malloc(sizeof(header_t))) == NULL)
    print_err(MALLOC_FAIL);
  champ->carry = champ->c_to_wait = champ->is_dead = 0;
  champ->PC = champ->is_exec = 0;
  champ->id = id;
  champ->cycle_to_die_cur = CYCLE_TO_DIE;
  if ((champ->reg = malloc(sizeof(int) * (REG_NUMBER + 1))) == NULL)
    print_err(MALLOC_FAIL);
  if ((champ->instr = malloc(sizeof(char) * 20)) == NULL)
    print_err(MALLOC_FAIL);
  init_str(champ->instr, 20);
  while (i < REG_NUMBER)
  {
    champ->reg[i] = 0;
    i++;
  }
  return (champ);
}

ssize_t str2size(char *str)
{
  ssize_t nb;
  ssize_t i;

  nb = i = 0;
  while (str[i] != '\0')
  {
    if (str[i] >= '0' && str[i] <= '9')
    {
      nb = nb * 10;
      nb += (str[i] - '0');
    }
    else
      print_err(INVALID_NUMBER);
    i++;
  }
  return (nb);
}
