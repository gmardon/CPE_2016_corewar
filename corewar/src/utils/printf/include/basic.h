/*
** basic.h for emacs in /home/aurelien.olibe/delivery/PSU_2016_my_printf
**
** Made by Aurelien Olibe
** Login   <aurelien.olibe@epitech.net>
**
** Started on  Tue Nov  8 16:01:32 2016 Aurelien Olibe
** Last update Sat Nov 19 01:04:38 2016 Aurelien Olibe
*/

#ifndef BASIC_H_
# define BASIC_H_

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define FLAG_NULL -1
# define INT_NULL -1

typedef struct	s_farg
{
  int		*flag;
  int		form;
  ssize_t	n_o;
  int		modif;
}		t_farg;

typedef struct	s_stockarg
{
  char		**all_arg;
  int		*start;
  int		*p_len;
  ssize_t	k;
  char		**to_free;
}		t_stockarg;

int		my_printf(const char *format, ...);
t_farg		*init_avs(const char *format);
void		init_str(char *str, size_t max);
t_stockarg	*init_stock(const char *format);
void		clear_avs(t_farg *avs);
void		percent(const char *format, int *i, t_farg *avs);
ssize_t		numeric(const char *format, int *i);
int		format1(const char form);
int		format2(const char form);
int		modifiers(const char modif, const char modif2);
int		flags(const char flag);
void		flag_sort(t_farg *avs);
size_t		my_strlen(const char *str);
ssize_t		my_wtlen(char **wt);
ssize_t		intlen(int *tab);
void		replace_free(t_stockarg *store, char *new);
void		free_avs(t_farg *avs);
void		free_store(t_stockarg *store);
t_stockarg	*init_stockarg2(t_stockarg *store, ssize_t count);
void		sort(t_farg *avs, ssize_t *i, int bol, int nb);
char		*d_conv(t_farg *avs, va_list args, t_stockarg *store);
char		*udx_conv(t_farg *avs, va_list args, int base,
			  t_stockarg *store);
char		*c_conv(va_list args, t_stockarg *store);
char		*s_conv(va_list args);
char		*lx_conv(t_farg *avs, va_list args, int base,
			 t_stockarg *store);
char		*ls_conv(va_list args, t_stockarg *store);
ssize_t		gen_string(t_stockarg *store, const char *format);
char		*fmanag(t_farg *avs, va_list args, t_stockarg *store,
			const char *);
char		*fmanag2(t_farg *avs, va_list args, t_stockarg *store);
char		*zero_pad(t_farg *avs, char *str, int alt, t_stockarg *store);
void		zero_pad2(t_farg *avs, char *str, char *new, ssize_t i);
char		*field_pad(t_farg *avs, char *str, t_stockarg *store);
char		*neg_pad(t_farg *avs, char *str, t_stockarg *store);
char		*plus(char *str, t_stockarg *store, int plus);
char		*gest_flag(t_farg *avs, char *str, int d, t_stockarg *store);

#endif
