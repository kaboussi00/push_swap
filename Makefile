NAME = push_swap
INC = push_swap.h
SRCS = push_swap.c\
	utils00.c\
	utils01.c\
	utils02.c\
	utils03.c\
	utils04.c\
	utils05.c\
	utils06.c\
	utils07.c\
	utils08.c\
	utils09.c\
	utils10.c\
	utils11.c\
	utils12.c\
	utils13.c\

OBJS = $(SRCS:.c=.o)

RM = rm -f

CFLAGS = -Wall -Wextra -Werror 

CC = cc

all:$(NAME)
$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o:%.c $(INC)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS)

fclean:clean
	$(RM) $(NAME)

re: fclean all+