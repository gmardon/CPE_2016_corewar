/*
** read_core.h for corewar in /home/aurelien/home/aurelien.olibe/delivery/CPE_2016_corewar/corewar/src/read
**
** Made by Aurelien
** Login   <aurelien.olibe@epitech.eu@epitech.net>
**
** Started on  Tue Nov 29 18:45:01 2016 Aurelien
** Last update Tue Nov 29 18:45:01 2016 Aurelien
*/
#ifndef _READ_CORE_H_
# define _READ_CORE_H_

#define BUFF_SIZE 4096

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "op.h"
#include "core.h"

typedef struct s_code_champ
{
  unsigned char *str;
  ssize_t len;
  ssize_t i;
} t_code_champ;

int read_core(int ac, char **av);
ssize_t get_file_size(char *);
t_code_champ *cor2str(char *file);
t_champion *code2champ(t_code_champ *code);
char *parse_comment(t_code_champ *code);
char *parse_name(t_code_champ *code);
t_champion *init_champ();
void init_str(char *str, int max);
unsigned char *hex_conv(unsigned char c);

#endif
