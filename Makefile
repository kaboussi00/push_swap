NAME = push_swap
INC = push_swap.h
SRCS = push_swap.c\
	erreurs.c\
	instructions_a.c\
	instructions_b.c\
	instructions_a_b.c\
	srt_two_trs_a.c\
	srt_two_trs_b.c\
	sort_quatre.c\
	sort_cinq.c\
	pivot.c\
	sort_a.c\
	sort_b.c\
	back_to_a_b.c\
	ft_retat.c\
	add_instruction.c\
	optimisation.c\
	utils00.c\
	utils01.c\
	utils02.c\
	utils03.c\

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