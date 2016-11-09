##
## Makefile for my_printf in /home/gmardon/PSU_2016_my_printf
##
## Made by Guillaume Le MARDON
## Login   <guillaume.mardon@epitech.net>
##
## Started on  Mon Oct 24 10:23:27 2016 Guillaume MARDON
## Last update Wed Nov  9 13:54:27 2016 Guillaume MARDON
##

NAME		=	asm

SRC		=	src/parser/parser.c			\
			src/op.c 	\
			src/main.c \
			src/utils/get_next_line.c \
			src/utils/my_putchar.c \
			src/utils/my_putstr.c \
			src/utils/my_strlen.c

RM		=	rm -f

all:	$(NAME)

$(NAME):
	gcc $(SRC) -o $(NAME) -g

clean:
	find ./ \( -name "*~" -o -name "#*#" \) -exec $(RM) "{}" \;

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
