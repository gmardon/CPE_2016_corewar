##
## Makefile for corewar in /home/gmardon/CPE_2016_corewar/asm
##
## Made by Guillaume Le MARDON
## Login   <guillaume.mardon@epitech.net>
##
## Started on  Mon Oct 24 10:23:27 2016 Guillaume MARDON
## Last update Fri Nov 11 11:34:42 2016 Guillaume MARDON
##
LDFLAGS=-lSDL -lSDL_ttf -lGLU -lGL

NAME		=	corewar

SRC		=	src/main.c \
				src/core/runtime.c \
				src/instructions/alive.c

RM		=	rm -f

all:	$(NAME)

$(NAME):
	gcc $(SRC) -o $(NAME) -g $(LDFLAGS)

clean:
	find ./ \( -name "*~" -o -name "#*#" \) -exec $(RM) "{}" \;

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
