/*
** core.h for corewar in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/corewar/src/core/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Fri Nov 11 10:33:26 2016 Guillaume MARDON
** Last update Thu Dec 15 11:10:58 2016 Aurelien
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
# define INSTR_LEN_ARG (arg[0] + arg[1] + arg[2] + arg[3] + 2)
# define CYCLE_TO_DIE_DELTA (CYCLE_TO_DIE - (CYCLE_DELTA * core->n_delta))

typedef struct		s_champion
{
  int			id;
  int			is_dead;
  header_t		*head;
  ssize_t		pc;
  int			*reg;
  char			carry;
  int			is_exec;
  unsigned char		*instr;
  int			c_to_wait;
  int			cycle_to_die_cur;
  struct s_champion	*next;
}			t_champion;

typedef struct		s_corewar
{
  int			prog_number;
  ssize_t		dump;
  ssize_t		load_address;
  int			last_live_id;
  int			live_on_this_cycle;
  int			nbr_live_cur;
  int			n_delta;
  unsigned char		*arena;
  t_champion		*champions;
}			t_corewar;

typedef struct		s_instruction
{
  int			id;
  int			(*function)(t_corewar *core,
				t_champion *champions);
  int			nbr_cycle;
}			t_instruction;

extern t_instruction	tab_instruction[];

/*
 ** CORE
 */
void decide_winner(t_corewar *core);
int is_already_in(t_champion *ch, int ch_id[5]);
ssize_t inc_pc(ssize_t pc, int inc);
void exec_champ(t_corewar *core, t_champion *ch);
void set_next_exec(t_corewar *core, t_champion *ch);
void copy_next_instr(t_corewar *core, t_champion *ch);
void kill_all_child(t_corewar *core, int id);
ssize_t get_instr_len(t_corewar *core, ssize_t pc, unsigned char instr);
char *decode_octet(unsigned char c);
char decode_bit(char arg, char bit1, char bit2);
void the_core_war(t_corewar *core);
int check_game_over(t_corewar *core);
int check_nb_alive(int ch_alive[5]);
void put_id_core_war(t_corewar *core);
void print_usage();
void print_arena(t_corewar *core);
unsigned char *hex_conv(unsigned char c);
void do_dump(t_corewar *core);
void print_err(char *str);
void print_err_no_exit(char *str);
void free_core_ch(t_corewar *core);

/*
** UTILS
*/
void init_int_tab(int *tab, ssize_t max);
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
** INSTRUCTIONS
*/
int lfrk(t_corewar *core, t_champion *ch);
int frk(t_corewar *core, t_champion *ch);
int lldi(t_corewar *core, t_champion *ch);
int lld(t_corewar *core, t_champion *ch);
int sti(t_corewar *core, t_champion *ch);
int ldi(t_corewar *core, t_champion *ch);
int zjmp(t_corewar *core, t_champion *ch);
int aff(t_corewar *core, t_champion *ch);
int xor(t_corewar *core, t_champion *ch);
int or(t_corewar *core, t_champion *ch);
int and(t_corewar *core, t_champion *ch);
int sub(t_corewar *core, t_champion *ch);
int add(t_corewar *core, t_champion *ch);
int st(t_corewar *core, t_champion *ch);
int ld(t_corewar *core, t_champion *ch);
int			alive(t_corewar *core, t_champion *champions);
int alive_read_id(t_champion *ch);
void add_live_to_core(t_corewar *core, int id);
void dec_nbr_live(t_corewar *core);
int check_reg(unsigned char r);
int st_dir_pc(t_corewar *core, ssize_t pc, int dir);
int read_dir_pc(t_corewar *core, t_champion *ch, short ind);
int read_dir(t_champion *ch, ssize_t *k);
short read_ind(t_champion *ch, ssize_t *k);
short read_ind_pc(t_corewar *core, t_champion *ch, short ind);
int read_dir_pc_int(t_corewar *core, t_champion *ch, int sum);
int read_dir_pc_l(t_corewar *core, t_champion *ch, short ind);
int read_dir_pc_int_l(t_corewar *core, t_champion *ch, int sum);
short read_ind_pc_l(t_corewar *core, t_champion *ch, short ind);
int get_dir_form_arg(t_corewar *core, t_champion *ch, char a, ssize_t *i);
int get_sum(t_corewar *core, t_champion *ch, ssize_t *i, int *sum);
int get_sum2(t_corewar *core, t_champion *ch, ssize_t *i, int *sum);
int get_sum_l(t_corewar *core, t_champion *ch, ssize_t *i, int *sum);
int instr_len_exception(char *arg);
t_champion *ch_dup(t_corewar *core, t_champion *ch);

#endif
