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

typedef struct		s_champion
{
  int id_fork;
  header_t *head;
  unsigned char **PC;
  ssize_t i;
  int *reg;
  char carry;
  int cycle_to_wait;
  struct 		s_champion	*next;
}			t_champion;

typedef struct		s_corewar
{
  unsigned char		*arena;
  t_champion			*champions;
  int							nbr_live_cur;
  int							cycle_to_die_cur;
}			t_corewar;

typedef struct		s_instruction
{
  int							id;
  int							(*function)(t_corewar *core,
							 			t_champion *champions/*,
							 			t_instruction *instruction*/);
}			t_instruction;

/*
 **CORE
 */
void print_arena(t_corewar *core);
unsigned char *hex_conv(unsigned char c);

/*
**UTILS
*/
char *my_strdup(char *str);
size_t my_strlen(char *str);
char 	*my_strlowcase(char *str);
void	my_itoa(size_t input, char *buffer, unsigned int radix);
size_t	my_nbrlen(size_t input, unsigned int radix);
void	my_putchar(char c);
size_t	my_nbrlen(size_t input, unsigned int radix);
void	my_putstr(char *str);

/*
**INSTRUCTIONS
*/
int			alive(t_corewar *core,
				t_champion *champions);

#endif
