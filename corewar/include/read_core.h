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

# define BUFF_SIZE 4096

# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include "op.h"
# include "core.h"

typedef struct s_code_champ
{
  unsigned char *str;
  ssize_t len;
  ssize_t i;
} t_code_champ;

t_corewar *read_core(int ac, char **av);
void code2arena(t_code_champ *code, t_corewar *core, t_champion *ch);
ssize_t get_file_size(char *);
t_code_champ *cor2str(char *file);
t_champion *code2champ(t_code_champ *code, t_corewar *core);
int parse_magic(t_code_champ *code, t_champion *ch);
void parse_comment(t_code_champ *code, t_champion *ch);
void parse_name(t_code_champ *code, t_champion *ch);
int parse_prog_size(t_code_champ *code);
t_corewar *init_corewar();
t_champion *init_champ();
void init_str(char *str, int max);
void add_new_champ(t_corewar *core, t_champion *ch);

#endif
