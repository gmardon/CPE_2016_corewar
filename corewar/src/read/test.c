#include "read_core.h"

void print_cor(t_code_champ *ch1);

int main(int ac, char **av)
{
  if (ac > 1)
  {
    read_core(ac, av);
  }
  return (0);
}

void print_cor(t_code_champ *ch1)
{
  char *hex;
  ssize_t i;

  i = ch1->i;
  while (i < ch1->len)
  {
    hex = hex_conv(ch1->str[i]);
    write(1, hex, 2);
    write(1, " ", 1);
    i++;
  }
  write(1, "\n", 1);
}

void print_arena(t_corewar *core)
{
  char *hex;
  ssize_t i;

  i = 0;
  while (i < MEM_SIZE)
  {
    hex = hex_conv(core->arena[i]);
    if ((i % 24) == 0 && i != 0)
      write(1, "\n", 1);
    if (core->arena[i] != 0)
      write(1, "\033[34m\033[1m", 10);
    else
      write(1, "\033[0m", 5);
    write(1, hex, 2);
    write(1, " ", 1);
    i++;
  }
  write(1, "\n", 1);
}
