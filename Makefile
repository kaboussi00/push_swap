NAME = push_swap
NAME_B = checker
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
	replace_opt.c\
	delete_opt.c\
	utils00.c\
	utils01.c\
	utils02.c\
	utils03.c\
	utils04.c\

SRCS_B = my_checker.c\
	erreurs.c\
	instructions_a.c\
	instructions_b.c\
	instructions_a_b.c\
	add_instruction.c\
	get_next_line/get_next_line.c\
	get_next_line/get_next_line_utils.c\
	utils00.c\
	utils01.c\
	utils02.c\
	utils03.c\
	utils04.c\


OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

RM = rm -f

CFLAGS = -Wall -Wextra -Werror 

CC = cc

all:$(NAME)
$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus:$(NAME_B)
$(NAME_B):$(OBJS_B)
	$(CC) $(CFLAGS) $(OBJS_B) -o $(NAME_B)

%.o:%.c $(INC)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean:clean
	$(RM) $(NAME) $(NAME_B)

re: fclean all