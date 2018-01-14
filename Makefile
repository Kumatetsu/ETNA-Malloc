##
## Makefile<ETNA-Malloc> for Malloc in /home/kumatetsu/ETNA-Malloc
## 
## Made by BILLAUD Jean
## Login   <billau_j@etna-alternance.net>
## 
## Started on  Thu Jan 11 21:48:05 2018 BILLAUD Jean
## Last update Sun Jan 14 15:27:24 2018 BILLAUD Jean
##

CC	=	gcc

NAME	=	libmy_malloc_$(shell uname).so

LNAME   =       libmy_malloc.so

CFLAGS  =	-W -Werror -Wextra -Wall -g -Iinclude/ -fPIC

LDFLAGS =	-shared

SRC	= 	my_malloc.c 	\
		my_calloc.c	\
		my_realloc.c	\
		blockchain.c	\

TSRC    =	main_calloc.c	\

OBJ	=	${SRC:%.c=%.o}

TOBJ    =	${TSRC:%.c=%.o}

RM	=	rm -f

PWD	:=	`pwd`

all	:	${NAME}

re	:	clean	all

$(NAME)	:	$(OBJ)
		$(CC)	$(CFLAGS)	$(OBJ)	$(LDFLAGS)	-o	$(NAME)
		ln -s $(PWD)/$(NAME) $(LNAME)

catest	:	$(TOBJ)
		$(CC) $(CFLAGS)		$(TOBJ) 	-o	calloc_test

clean	:
		$(RM)	$(OBJ) $(TOBJ)

fclean	:	clean
		$(RM)	$(NAME) $(LNAME) calloc_test

.PHONY	:	all	clean	fclean
