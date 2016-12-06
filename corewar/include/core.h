/*
** core.h for corewar in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/corewar/src/core/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Fri Nov 11 10:33:26 2016 Guillaume MARDON
** Last update Tue Nov 29 16:47:50 2016 Guillaume MARDON
*/
#ifndef _CORE_H_
# define _CORE_H_

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "op.h"

# define	RADIX	"0123456789abcdefghijklmnopqrstuvwxyz"

# define LIVE		(1)
# define LD		  (2)
# define ST		  (3)
# define ADD		(4)
# define SUB		(5)
# define AND		(6)
# define OR		  (7)
# define XOR		(8)
# define ZJMP		(9)
# define LDI		(10)
# define STI		(11)
# define FORK		(12)
# define LLD		(13)
# define LLDI		(14)
# define LFORK	(15)
# define AFF		(16)

# define MALLOC_FAIL "malloc failure."

typedef struct		s_champion
{
  int id_fork;
  int is_dead;
  header_t *head;
  unsigned char **PC;
  ssize_t i;
  int *reg;
  char carry;
  int c_to_wait;
  int							cycle_to_die_cur;
  int							nbr_live_cur;
  int n_delta;
  struct 		s_champion	*next;
}			t_champion;

typedef struct		s_corewar
{
  unsigned char		*arena;
  t_champion			*champions;
}			t_corewar;

typedef struct		s_instruction
{
  int							id;
  int							(*function)(t_corewar *core,
							 			t_champion *champions/*,
							 			t_instruction *instruction*/);
  int             nbr_cycle;
}			t_instruction;

extern t_instruction	tab_instruction[];

/*
 **CORE
 */
void exec_champ(t_corewar *core, t_champion *ch);
void the_core_war(t_corewar *core);
int check_game_over(t_corewar *core);
int check_nb_alive(int ch_alive[5]);
void put_id_core_war(t_corewar *core);
void print_usage();
void print_arena(t_corewar *core);
unsigned char *hex_conv(unsigned char c);
void print_err(char *str);
void print_err_no_exit(char *str);

/*
**UTILS
*/
int my_str_srch(char *to_search, char *str);
char *my_strdup(char *str);
size_t my_strlen(char *str);
char 	*my_strlowcase(char *str);
void	my_itoa(size_t input, char *buffer, unsigned int radix);
size_t	my_nbrlen(size_t input, unsigned int radix);
void	my_putchar(char c);
size_t	my_nbrlen(size_t input, unsigned int radix);
void	my_putstr(char *str);
int my_printf(const char *format, ...);

/*
**INSTRUCTIONS
*/
int			alive(t_corewar *core, t_champion *champions);

#endif
