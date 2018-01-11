##
## Makefile<ETNA-Malloc> for Malloc in /home/kumatetsu/ETNA-Malloc
## 
## Made by BILLAUD Jean
## Login   <billau_j@etna-alternance.net>
## 
## Started on  Thu Jan 11 21:48:05 2018 BILLAUD Jean
## Last update Thu Jan 11 21:58:23 2018 BILLAUD Jean
##

CC	=	gcc

NAME	=	libmy_malloc_$(shell uname).so

LNAME   =       libmy_malloc.so

CFLAGS  =	-W -Werror -Wextra -Wall -g -Iinclude/ -fPIC

LDFLAGS =	-shared

SRC	= 	my_malloc.c 	\
		blockchain.c	\

OBJ	=	${SRC:%.c=%.o}

RM	=	rm -f

PWD	:=	`pwd`

all	:	${NAME}

re	:	clean	all

$(NAME)	:	$(OBJ)
		$(CC)	$(CFLAGS)	$(OBJ)	$(LDFLAGS)	-o	$(NAME)
		ln -s $(PWD)/$(NAME) $(LNAME)

clean	:
		$(RM)	$(OBJ)

fclean	:	clean
		$(RM)	$(NAME)

.PHONY	:	all	clean	fclean
