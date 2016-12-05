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

t_champion *code2champ(t_code_champ *code, t_corewar *core, int i)
{
  t_champion *champ;

  code->i = 0;
  champ = init_champ(i);
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

t_champion *init_champ(int id)
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
  champ->carry = champ->i = champ->c_to_wait = champ->is_dead = 0;
  champ->n_data = 0;
  champ->id_fork = id;
  champ->cycle_to_die_cur = CYCLE_TO_DIE;
  champ->nbr_live_cur = NBR_LIVE;
  if ((champ->reg = malloc(sizeof(int) * REG_NUMBER)) == NULL)
    exit(84);
  while (i < REG_NUMBER)
  {
    champ->reg[i] = 0;
    i++;
  }
  return (champ);
}
