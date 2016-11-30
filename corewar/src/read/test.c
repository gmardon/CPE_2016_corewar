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
  ssize_t i;
  char *hex;

  i = 0;
  while (i < ch1->len)
  {
    hex = hex_conv(ch1->str[i]);
    write(1, hex, 2);
    write(1, " ", 1);
    i++;
  }
  write(1, "\n", 1);
}
