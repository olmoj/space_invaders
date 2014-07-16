##
## Makefile for  in /Users/olmo_j/Documents/Projets/Space_Invaders/Etape_01
## 
## Made by OLMO Joy
## Login   <olmo_j@etna-alternance.net>
## 
## Started on  Wed Jul  2 14:41:10 2014 OLMO Joy
## Last update Wed Jul 16 15:35:37 2014 OLMO Joy
##

CC	= gcc

NAME	= space_invaders

SRC	= main.c \
	  structure.c \
	  src/f_init.c

OBJ	= $(SRC:%.c=%.o)

INC	= ./headers

RM	= rm -f

CFLAGS	= -ansi -pedantic -W -Wall -I $(INC)

LDFLAGS = -lSDL2 -lSDL2_image

$(NAME) :	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LDFLAGS)

all :		$(NAME)

clean :
		$(RM) $(OBJ)

fclean : 	clean
		$(RM) $(NAME)

re : 		fclean all
