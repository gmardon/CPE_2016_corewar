/*
** read_core.c for Corewar in /home/aurelien.olibe/delivery/CPE_2016_corewar/corewar/src
**
** Made by Aurelien Olibe
** Login   <aurelien.olibe@epitech.net>
**
** Started on  Wed Nov 16 18:25:41 2016 Aurelien Olibe
** Last update Wed Nov 16 18:25:42 2016 Aurelien Olibe
*/
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

/*
** trucs a mettre dans un .h
*/
#define BUFF_SIZE 4096

typedef struct s_code_champ
{
  unsigned char *str;
  ssize_t len;
} t_code_champ;

ssize_t get_file_size(char *);
t_code_champ *cor2str(char *file);
unsigned char *hex_conv(unsigned char c);
/*
** TEMP
*/
void print_cor(t_code_champ *ch1);
/*
** Fin des trucs a mettre dans un .h
*/

int main(int ac, char **av)
{
  t_code_champ *ch1;

  if (ac > 1)
    {
      ch1 = cor2str(av[1]);
      print_cor(ch1);
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

void init_str(char *str, int max)
{
  int i;

  i = 0;
  while (i < max)
    {
      str[i] = '\0';
      i++;
    }
}

ssize_t get_file_size(char *file)
{
  int fd;
  ssize_t readed;
  ssize_t size;
  char buf[BUFF_SIZE];

  size = readed = 0;
  if ((fd = open(file, O_RDONLY)) == -1)
    exit(84);
  while ((readed = read(fd, buf, BUFF_SIZE)) > 0)
    size = size + readed;
  close(fd);
  return (size);
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

t_code_champ *cor2str(char *file)
{
  unsigned char *str;
  int fd;
  ssize_t readed;
  ssize_t i;
  ssize_t file_size;
  t_code_champ *ch1;

  readed = file_size = i = 0;
  if ((fd = open(file, O_RDONLY)) == -1)
    exit(84);
  file_size = get_file_size(file);
  if ((str = malloc(sizeof(char) * (file_size + 1))) == NULL)
    exit(84);
  while ((readed = read(fd, (str + i), file_size)) > 0 && i <= file_size)
    i = i + readed;
  if ((ch1 = malloc(sizeof(t_code_champ))) == NULL)
    exit(84);
  ch1->str = str;
  ch1->len = file_size;
  close(fd);
  return (ch1);
}
