/*
** main.c for corewar in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/vm/src/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Wed Nov  9 18:45:17 2016 Guillaume MARDON
** Last update Tue Dec  6 09:54:09 2016 Aurelien
*/
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <stdlib.h>
#include "op.h"
#include "core.h"
#include "read_core.h"

/*
** TO DO LIST:
** check for live
** set all macro : v4.2
** update/change my_printf
** add arg options (-dump, ...)
** modif thing to put champ far away each other
** modif print_arena for arg options
** set a limit prog_size !!
** do some free (arg, ...)
** check if dec_nbr_live if is wrong live
** check for carry (why: ldi 6, %4, r3 set carry to 0 ?)
** test zjump
** test sti, ldi, lld, lldi
** check for fork
** check if extern is up to the norme
** check if PC en maj is up to norme
** check if the jump (fork & zjmp) is done from good start pts
** inc PC if instr not found ??
** norme...
*/

int main(int ac, char **av)
{
  t_corewar *core;

  if (ac > 2 && ac < 6)
  {
    core = read_core(ac, av);
    put_id_core_war(core);
    the_core_war(core);
  }
  else if (ac >= 6)
    write(1, "The number of champion is above the limit.\n", 43);
  else
    print_usage();
  return (0);
}

void the_core_war(t_corewar *core)
{
  t_champion *ch;

  while (check_game_over(core) == 0)
  {
    ch = core->champions;
    while (ch != NULL)
    {
      if (ch->cycle_to_die_cur == 0)
        kill_all_child(core, ch->id);
      if (ch->is_dead == 0 && ch->c_to_wait == 0)
        exec_champ(core, ch);
      if (ch->is_dead == 0 && ch->c_to_wait > 0)
        ch->c_to_wait--;
      if (ch->is_dead == 0 && ch->cycle_to_die_cur > 0)
        ch->cycle_to_die_cur--;
      ch = ch->next;
    }
    core->live_on_this_cycle = 0;
  }
  decide_winner(core);
  // free all ?
}

int check_game_over(t_corewar *core)
{
  t_champion *ch;
  int ch_id[5];
  int ch_alive[5];
  int i;

  ch = core->champions;
  ch_id[4] = ch_alive[4] = i = 0;
  init_int_tab(ch_id, 4);
  init_int_tab(ch_alive, 4);
  while (ch != NULL)
  {
    if (is_already_in(ch, ch_id) == 0)
    {
      ch_id[i] = ch->id;
      ch_alive[i] = (ch->is_dead) ? (0) : (1);
    }
    ch = ch->next;
    i++;
  }
  return (check_nb_alive(ch_alive));
}

int check_nb_alive(int ch_alive[5])
{
  int i;
  int sum;

  i = sum = 0;
  while (i < 4)
  {
    if (ch_alive[i] == 1)
      sum++;
    i++;
  }
  if (sum >= 2)
    return (0);
  else
    return (1);
}

void put_id_core_war(t_corewar *core)
{
  t_champion *ch;

  ch = core->champions;
  while (ch != NULL)
  {
    ch->reg[1] = ch->id;
    ch = ch->next;
  }
}
