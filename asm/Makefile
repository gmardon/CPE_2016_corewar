##
## Makefile for asm in /home/gmardon/CPE_2016_corewar/asm
##
## Made by Guillaume MARDON
## Login   <guillaume.mardon@epitech.net>
##
## Started on  Mon Oct 24 10:23:27 2016 Guillaume MARDON
## Last update Sun Dec 18 19:11:15 2016 Aurelien
##

NAME		=	asm

#CFLAGS	+=	-Wextra -Wall -W

SRC		=	src/parser/parser.c			\
			src/compiler/compiler.c \
			src/compiler/args_compiler.c \
			src/compiler/args_utils.c \
			src/compiler/labelref_utils.c \
			src/compiler/header_compiler.c \
			src/compiler/instructions_compiler.c \
			src/parser/instruction.c			\
			src/op.c 	\
			src/main.c \
			src/utils/get_next_line.c \
			src/utils/file.c \
			src/utils/buffer.c \
			src/utils/my_putchar.c \
			src/utils/my_strsep.c \
			src/utils/my_commandsep.c \
			src/utils/my_strncpy.c \
			src/utils/my_str_to_int.c \
			src/utils/my_putstr.c \
			src/utils/my_strlen.c \
			src/utils/my_strcpy.c \
			src/utils/my_strcmp.c \
			src/utils/my_malloc.c \
			src/utils/my_indexof.c \
			src/utils/my_strncmp.c \
			src/utils/my_cleanstr.c \
			src/utils/my_strlowcase.c \
			src/utils/my_itoa.c \
			src/utils/my_nbrlen.c \
			src/utils/printf/my_printf.c 	\
			src/utils/printf/formats/numeric_format.c \
			src/utils/printf/formats/alphabetic_format.c \
			src/utils/printf/formats/extra_format.c

OBJS		=	$(SRCS:.c=.o)

RM		=	rm -f

all:	$(NAME)

$(NAME):
	gcc $(SRC) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
