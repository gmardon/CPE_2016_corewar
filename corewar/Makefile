##
## Makefile for corewar in /home/gmardon/CPE_2016_corewar/asm
##
## Made by Guillaume Le MARDON
## Login   <guillaume.mardon@epitech.net>
##
## Started on  Mon Oct 24 10:23:27 2016 Guillaume MARDON
## Last update Tue Nov 29 16:48:16 2016 Guillaume MARDON
##
LDFLAGS=-lSDL -lSDL_ttf -lGLU -lGL

NAME		=	corewar

SRC		=	src/main.c \
				src/core/runtime.c \
				src/instructions/alive.c \
				src/utils/my_strlowcase.c \
				src/utils/my_putchar.c \
				src/utils/my_nbrlen.c \
				src/utils/my_itoa.c \
				src/utils/my_strlen.c \
				src/utils/my_putstr.c \
				src/utils/printf/my_printf.c 	\
				src/utils/printf/formats/numeric_format.c \
				src/utils/printf/formats/alphabetic_format.c \
			 	src/utils/printf/formats/extra_format.c

RM		=	rm -f

all:	$(NAME)

$(NAME):
	gcc $(SRC) -o $(NAME) -g $(LDFLAGS)

clean:
	find ./ \( -name "*~" -o -name "#*#" \) -exec $(RM) "{}" \;

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
