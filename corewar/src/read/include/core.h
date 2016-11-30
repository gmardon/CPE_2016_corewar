/*
** core.h for corewar in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/corewar/src/core/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Fri Nov 11 10:33:26 2016 Guillaume MARDON
** Last update Tue Nov 29 16:47:50 2016 Guillaume MARDON
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define	RADIX	"0123456789abcdefghijklmnopqrstuvwxyz"

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
  char			*file_name;
  char			*name;
  char			*comment;
  unsigned char **PC;
  int *reg;
  char carry;
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

// UTILS //
char 	*my_strlowcase(char *str);
void	my_itoa(size_t input, char *buffer, unsigned int radix);
size_t	my_nbrlen(size_t input, unsigned int radix);
void	my_putchar(char c);
size_t	my_nbrlen(size_t input, unsigned int radix);
void	my_putstr(char *str);

// INSTRUCTIONS //
int			alive(t_corewar *core,
				t_champion *champions);
