##
## Makefile for corewar in /home/gmardon/CPE_2016_corewar/asm
##
## Made by Guillaume Le MARDON
## Login   <guillaume.mardon@epitech.net>
##
## Started on  Mon Oct 24 10:23:27 2016 Guillaume MARDON
## Last update Tue Dec  6 16:07:44 2016 Aurelien
##
LDFLAGS=-lSDL -lSDL_ttf -lGLU -lGL

#CFLAGS	+=	-Wextra -Wall -Werror -pedantic

CC	=	gcc

NAME	=	corewar

SRCS	=	src/main.c \
		src/core/print.c \
		src/core/execute.c	\
		src/core/runtime.c \
		src/read/read_core.c \
		src/read/champ_conv.c \
		src/read/parse_core.c \
		src/instructions/alive.c \
		src/utils/my_strlowcase.c \
		src/utils/my_putchar.c \
		src/utils/my_nbrlen.c \
		src/utils/my_itoa.c \
		src/utils/my_strlen.c \
		src/utils/my_putstr.c \
		src/utils/my_strdup.c \
		src/utils/my_str_srch.c	\
		src/utils/printf/my_printf.c 	\
		src/utils/printf/formats/numeric_format.c \
		src/utils/printf/formats/alphabetic_format.c \
		src/utils/printf/formats/extra_format.c

OBJS	=	$(SRCS:.c=.o)

RM	=	rm -f

all:	$(NAME)

$(NAME):
	$(CC) $(SRCS) -o $(NAME) -g $(LDFLAGS) $(CFLAGS) -I./include

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
