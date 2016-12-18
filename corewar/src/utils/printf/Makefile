##
## Makefile for Makefile in /home/aurelien.olibe/Makefile
##
## Made by Aurelien Olibe
## Login   <aurelien.olibe@epitech.net>
##
## Started on  Sat Oct 29 18:51:39 2016 Aurelien Olibe
## Last update Sun Dec 18 20:06:54 2016 Aurelien
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wextra -Wall -Werror -pedantic

#LIB	= -L./lib -lmy

HDRS	= -I./include

NAME	= libmy.a

SRCS	=	basic.c		\
		recon.c		\
		manag.c		\
		manag2.c	\
		free_printf.c	\
		parse_flag.c	\
		dec_conv.c	\
		char_conv.c	\
		long_conv.c	\
		flag.c		\
		flag2.c		\
		new_forest.c	\
		my_strlen.c

OBJS	= $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJS):
	$(CC) $(SRCS) $(HDRS) $(CFLAGS) -c

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
