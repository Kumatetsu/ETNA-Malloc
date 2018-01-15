##
## Makefile<ETNA-Malloc> for Malloc in /home/kumatetsu/ETNA-Malloc
## 
## Made by BILLAUD Jean
## Login   <billau_j@etna-alternance.net>
## 
## Started on  Thu Jan 11 21:48:05 2018 BILLAUD Jean
## Last update Mon Jan 15 17:01:51 2018 BILLAUD Jean
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

CTSRC    =	main_calloc.c	\

MTSRC    =	main.c		\

RTSRC    =      main_realloc.c	\

OBJ	 =	${SRC:%.c=%.o}

CTOBJ    =	${CTSRC:%.c=%.o}

MTOBJ    =	${MTSRC:%.c=%.o}

RTOBJ    = 	${RTSRC:%.c=%.o}

RM	 =	rm -f

PWD	:=	`pwd`

all	:	${NAME}

re	:	clean	all

$(NAME)	:	$(OBJ)
		$(CC)	$(CFLAGS)	$(OBJ)	$(LDFLAGS)	-o	$(NAME)
		ln -s $(PWD)/$(NAME) $(LNAME)

catest	:	$(CTOBJ)
		$(CC) $(CFLAGS)		$(CTOBJ) 	-o	calloc_test

matest	:	$(MTOBJ)
		$(CC) $(CFLAGS)		$(MTOBJ)	-o	malloc_test

retest	:	$(RTOBJ)
		$(CC) $(CFLAGS)		$(RTOBJ)	-o	realloc_test

clean	:
		$(RM)	$(OBJ) $(CTOBJ) $(MTOBJ) $(LNAME)

fclean	:	clean
		$(RM)	$(NAME) $(LNAME) calloc_test malloc_test realloc_test

.PHONY	:	all	clean	fclean
