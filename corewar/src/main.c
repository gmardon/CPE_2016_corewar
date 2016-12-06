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

int main(int ac, char **av)
{
  t_corewar *core;

  if (ac > 2 && ac < 6)
  {
    core = read_core(ac, av);
    //print_arena(core);
    put_id_core_war(core);
    //init_c_to_wait(); // init c_to_wait with the next instruct to be exec.
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
      {
        ch->is_dead = 1;
        //printf("DEAD..\n");
        write(1, "DEAD ?\n", 7);
      }
      if (ch->is_dead == 0 && ch->c_to_wait == 0)
      {
        printf("IS_HERE\n");
        // execute each prog (PC & move PC) (if PC null or unknown instruct, do nothing)
        // set nbr_live_cur if live
        // set c_to_wait (next instruction)
      }
      if (ch->is_dead == 0 && ch->c_to_wait > 0)
        ch->c_to_wait--;
      if (ch->is_dead == 0 && ch->cycle_to_die_cur > 0)
        ch->cycle_to_die_cur--;
      ch = ch->next;
    }
  }
  printf("GAME OVER\n");
}

int check_game_over(t_corewar *core)
{
  t_champion *ch;
  int ch_id[5];
  int ch_alive[5];
  int i;
  ch = core->champions;

  ch_id[4] = ch_alive[4] = i = 0;
  while (ch != NULL)
  {
    if (ch->id_fork < 0)
    {
      i = 0;
      while (ch_id[i] != (ch->id_fork * -1))
        i++;
    }
    else
      ch_id[i] = ch->id_fork;
    if (ch->is_dead == 0)
      ch_alive[i] = 1;
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
    ch->reg[0] = ch->id_fork;
    ch = ch->next;
  }
}
