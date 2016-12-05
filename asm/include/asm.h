/*
** asm.h for asm in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/include/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Wed Nov  9 13:46:05 2016 Guillaume MARDON
** Last update Mon Dec  5 15:24:08 2016 Guillaume MARDON
*/
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "op.h"

#define BUFF_SIZE (4096)
#define	RADIX	"0123456789abcdefghijklmnopqrstuvwxyz"

// STRUCTS //
typedef struct          args_s
{
  char                  type[MAX_ARGS_NUMBER];
  char                  *argv[MAX_ARGS_NUMBER];
}                       args_t;

typedef struct          instruction_s
{
  op_t									*op;
  args_t								*args;
  char									*label;
  struct instruction_t  *next;
}                       instruction_t;

// UTILS //
void	my_putchar(char c);
void	my_putstr(char *str);
char *get_next_line(const int fd);
size_t	my_strlen(char *str);
char 	*my_strcpy(char *dest, char *src);
int 	my_strcmp(char *s1, char *s2);
char	*my_cleanstr(char *str);
char 	*my_strlowcase(char *str);
void	my_itoa(size_t input, char *buffer, unsigned int radix);
size_t	my_nbrlen(size_t input, unsigned int radix);

// PARSER //
int	parse_file(char* file_name);
int	label_index(char *line);
instruction_t	*read_instruction(char *line);

// COMPILER //
char*  compile(int *size, instruction_t *first_instruction);
char	get_encoded_args_type(char types[MAX_ARGS_NUMBER]);
