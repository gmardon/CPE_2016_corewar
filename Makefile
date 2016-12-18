##
## Makefile for corewar in /home/aurelien/home/aurelien.olibe/delivery/CPE_2016_corewar
## 
## Made by Aurelien
## Login   <aurelien.olibe@epitech.eu@epitech.net>
## 
## Started on  Sun Dec 18 19:34:44 2016 Aurelien
## Last update Sun Dec 18 19:39:42 2016 Aurelien
##

ASM	=	./asm

COREWAR	=	./corewar

all: $(ASM) $(COREWAR)

$(ASM):
	$(MAKE) -C $(ASM)

$(COREWAR):
	$(MAKE) -C $(COREWAR)

clean:
	$(MAKE) -C $(COREWAR) clean
	$(MAKE) -C $(ASM) clean

fclean:
	$(MAKE) -C $(COREWAR) fclean
	$(MAKE) -C $(ASM) fclean

re:	fclean all

.PHONY: all clean fclean re $(ASM) $(COREWAR)
