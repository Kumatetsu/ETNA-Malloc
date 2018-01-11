##
## Makefile for libmy_extended in /home/aurelien/Documents/Lib_etna/castel_a/libmy_extended
## 
## Made by CASTELLARNAU Aurelien
## Login   <castel_a@etna-alternance.net>
## 
## Started on  Wed Feb  1 09:37:15 2017 CASTELLARNAU Aurelien
## Last update Wed Jan 10 16:14:15 2018 BILLAUD Jean
##

CC      =       gcc

NAME    =       my_malloc

LIB     =       ./libmy

CFLAGS  =       -W -Wextra -Werror -Wall -g -Iinclude/ -Ilibmy

LDFLAGS =       -lpthread -L ./libmy -lmy

SRC     =       main.c \
		blockchain.c \
		chunk.c \
		my_malloc.c \

OBJ     =       ${SRC:%.c=%.o}

RM      =       rm -f

all	:	lib	$(NAME)

lib	:
		$(MAKE)	-C	$(LIB)

libPar	:
		$(MAKE)	-C	$(LIBPAR)

re	:	clean	all

$(NAME)	:	$(OBJ)
		$(CC)	$(CFLAGS)	$(OBJ)	$(LDFLAGS)	-o	$(NAME)

clean	:
		$(RM)	$(OBJ)

fclean	:	clean
		$(RM)	$(NAME)

.PHONY	:	all	clean	fclean
