##
## Makefile for asm in /home/gmardon/CPE_2016_corewar/asm
##
## Made by Guillaume MARDON
## Login   <guillaume.mardon@epitech.net>
##
## Started on  Mon Oct 24 10:23:27 2016 Guillaume MARDON
## Last update Mon Dec  5 16:28:47 2016 Guillaume MARDON
##

NAME		=	asm

#CFLAGS	+=	-Wextra -Wall -Werror -pedantic

SRC		=	src/parser/parser.c			\
			src/compiler/compiler.c \
			src/compiler/args_compiler.c \
			src/parser/instruction.c			\
			src/op.c 	\
			src/main.c \
			src/utils/get_next_line.c \
			src/utils/file.c \
			src/utils/my_putchar.c \
			src/utils/my_strsep.c \
			src/utils/my_putstr.c \
			src/utils/my_strlen.c \
			src/utils/my_strcpy.c \
			src/utils/my_strcmp.c \
			src/utils/my_cleanstr.c \
			src/utils/my_strlowcase.c \
			src/utils/my_itoa.c \
			src/utils/my_nbrlen.c \
			src/utils/printf/my_printf.c 	\
			src/utils/printf/formats/numeric_format.c \
			src/utils/printf/formats/alphabetic_format.c \
			src/utils/printf/formats/extra_format.c

RM		=	rm -f

all:	$(NAME)

$(NAME):
	gcc $(SRC) -o $(NAME) -g

clean:
	find ./ \( -name "*~" -o -name "#*#" \) -exec $(RM) "{}" \;

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
