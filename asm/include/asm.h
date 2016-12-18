/*
** asm.h for asm in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/include/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Wed Nov  9 13:46:05 2016 Guillaume MARDON
** Last update Sun Dec 18 12:33:27 2016 Guillaume MARDON
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

typedef struct          buffer_s
{
  int										index;
  char                  *data;
}                       buffer_t;

typedef struct          labelref_s
{
  char                  *name;
  int										index;
  int										size;
  char									is_label;
  char									is_direct;
}                       labelref_t;

typedef struct          instruction_s
{
  op_t									*op;
  args_t								*args;
  char									*label;
  struct instruction_t  *next;
}                       instruction_t;

typedef struct          program_s
{
  char									*name;
  char									*comment;
  instruction_t  				*first_instruction;
}												program_t;

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
int my_printf(const char *format, ...);
char	*filename_to_cor(char *file_path);
int 	my_strncmp(char *s1, char *s2, int size);
char	**my_strsep(char *str, char delim);
void	save(int length, char* buffer, char* filepath);
char	*right_padding(char *data, int base_size, int requested_size);
void	write_to_buffer(buffer_t *index, char *to_write, int size);
int		my_int_convert(int i);
void	*my_malloc(int size);
void	write_empty(int count, buffer_t *buffer);
void	write_int_4(int value, buffer_t *buffer);
void write_int_2(int value, buffer_t *buffer);
int my_str_to_int(char *str);
char	**my_commandsep(char *str);
int	my_indexof(char c, char *str);
char	my_str_to_char(char *str);

// PARSER //
program_t	*	parse_file(char* file_name);
instruction_t	*read_instruction(char *line);

// COMPILER //
buffer_t*  compile(int *size, program_t *program);
char	get_encoded_args_type(char types[MAX_ARGS_NUMBER]);
int	need_encode_args_type(int code);
void	compile_header(buffer_t *buffer, char* name, char* comment);
buffer_t	*create_header(char *name, char *comment, int i_size, int *size);
buffer_t	*create_instructions(instruction_t *first_instruction, int *size);
void	write_args(instruction_t *instruction, buffer_t *buffer, labelref_t *refs);
void	write_direct(op_t *op, char *value, buffer_t *buffer, labelref_t *refs);
void	write_indirect(op_t *op, char *value, buffer_t *buffer, labelref_t *refs);
void	write_register(op_t *op, char value, buffer_t *buffer);
labelref_t	*create_refs_stack();
labelref_t	*find_label(labelref_t *refs, char *name);
buffer_t	*create_buffer(int size);
void	add_label_ref(int index, char *name, labelref_t *stack);
void	add_ref(labelref_t *stack, labelref_t *labelref);
