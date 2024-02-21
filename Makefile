##
## EPITECH PROJECT, 2023
## makefile
## File description:
## Task 01 - make file
##

C_FILES = main.c \
		  stat.c
O_FILES = $(C_FILES:.c=.o)
LIB 	= -I./include
NAME	= orion

all: ${NAME}

${NAME}: ${O_FILES}
	gcc ${O_FILES} -g -o ${NAME} ${LIB}
	rm *.o

%.o: %.c
	gcc -c -o $@ $<

clean:
	rm -f *.out
	rm -f ${O_FILES}

fclean: clean
	rm -f ${NAME}

re: fclean all
