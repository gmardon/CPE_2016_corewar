/*
** read_core.h for corewar in /home/aurelien/home/aurelien.olibe/delivery/CPE_2016_corewar/corewar/src/read
**
** Made by Aurelien
** Login   <aurelien.olibe@epitech.eu@epitech.net>
**
** Started on  Tue Nov 29 18:45:01 2016 Aurelien
** Last update Thu Dec 15 11:16:31 2016 Aurelien
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

# define OPEN_FAIL "Could not open the file."
# define FILESIZE_MAX_FAIL "The file is too long."
# define MAGIC_FAIL "The magic exec number is incorrect."
# define PROG_SIZE_FAIL "Wrong prog_size number."
# define HEADER_COMM_FAIL "Incorrect header. (in comment section)"
# define HEADER_NAME_FAIL "Incorrect header. (in name section)"
# define COR_FILE_FAIL "Incorrect .cor file."
# define N_ARG_INVALID "-n : argument should be between 1 and 4."
# define INVALID_ARG "This is not a valid argument."
# define INVALID_NUMBER "This is not a valid numer."
# define CH_ABOVE_LIMIT "The number of champion load is above the limit."

typedef struct	s_code_champ
{
  unsigned char	*str;
  ssize_t	len;
  ssize_t	i;
}		t_code_champ;

t_corewar *read_core(int ac, char **av, ssize_t total_ch);
void code2arena(t_code_champ *code, t_corewar *core, t_champion *ch,
                ssize_t total_ch);
ssize_t get_file_size(char *, ssize_t total_ch);
t_code_champ *cor2str(char *file, ssize_t total_ch);
t_champion *code2champ(t_code_champ *code, t_corewar *core, int i,
                        ssize_t total_ch);
ssize_t parse_arg(t_corewar *core, int ac, char **av, ssize_t j);
int parse_arg_intro(t_corewar *core, int ac, char **av, ssize_t j);
int parse_magic(t_code_champ *code);
void parse_comment(t_code_champ *code, t_champion *ch);
void parse_name(t_code_champ *code, t_champion *ch);
int parse_prog_size(t_code_champ *code);
t_corewar *init_corewar();
t_champion *init_champ(int id);
void init_str_un(unsigned char *str, int max);
int	my_strcmp(char *s1, char *s2);
ssize_t str2size(char *str);
void add_new_champ(t_corewar *core, t_champion *ch);
void free_code_ch(t_code_champ *ch);

#endif
