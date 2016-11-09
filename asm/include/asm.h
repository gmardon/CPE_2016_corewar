/*
** asm.h for asm in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/CPE_2016_corewar/asm/include/
**
** Made by Guillaume MARDON
** Login   <guillaume.mardon@epitech.eu@epitech.eu>
**
** Started on  Wed Nov  9 13:46:05 2016 Guillaume MARDON
** Last update Wed Nov  9 14:39:15 2016 Guillaume MARDON
*/
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFF_SIZE (4096)

// UTILS //
void	my_putchar(char c);
void	my_putstr(char *str);
char *get_next_line(const int fd);
size_t	my_strlen(char *str);
char 	*my_strcpy(char *dest, char *src);

// PARSER //
int	parse_file(char* file_name);
