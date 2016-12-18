##
## Makefile for corewar in /home/gmardon/CPE_2016_corewar/asm
##
## Made by Guillaume Le MARDON
## Login   <guillaume.mardon@epitech.net>
##
## Started on  Mon Oct 24 10:23:27 2016 Guillaume MARDON
## Last update Sat Dec 17 22:22:51 2016 Aurelien
##

#CFLAGS	+=	-Wextra -Wall -Werror -pedantic

CC	=	gcc

MY_PRINTF =	src/utils/printf

NAME	=	corewar

SRCS	=	src/main.c \
		src/core/print.c \
		src/core/execute.c	\
		src/core/execute2.c	\
		src/core/runtime.c \
		src/core/free.c	\
		src/read/read_core.c \
		src/read/champ_conv.c \
		src/read/parse_core.c \
		src/read/i_love_norme.c	\
		src/instructions/fork.c	\
		src/instructions/lfork.c	\
		src/instructions/lld.c	\
		src/instructions/lldi.c	\
		src/instructions/sti.c	\
		src/instructions/ldi.c	\
		src/instructions/aff.c	\
		src/instructions/zjump.c	\
		src/instructions/or.c	\
		src/instructions/xor.c	\
		src/instructions/and.c	\
		src/instructions/sub.c	\
		src/instructions/add.c	\
		src/instructions/st.c	\
		src/instructions/ld.c	\
		src/instructions/alive.c \
		src/utils/my_strcmp.c	\
		src/utils/init_int_tab.c	\
		src/utils/my_strlen.c \
		src/utils/my_strdup.c \
		src/utils/my_str_srch.c	\

OBJS	=	$(SRCS:.c=.o)

LIB	=	-L./src/utils/printf -lmy

RM	=	rm -f

all:	$(MY_PRINTF) $(NAME)

$(NAME):
	$(CC) $(SRCS) -o $(NAME) -I./include $(LIB)

$(MY_PRINTF):
	$(MAKE) -C $(MY_PRINTF)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(MY_PRINTF) clean

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) -C $(MY_PRINTF) fclean

re:	fclean all

.PHONY:	all clean fclean re $(MY_PRINTF)
