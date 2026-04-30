CC = cc
CFLAGS = -Wall -Werror -Wextra -g
NAME = push_swap
LIBFT = libft/libft.a
INCLUDES = -I./includes -I./libft

SRC = push_swap.c \
		operations_push.c \
		operations_rev_rotate.c \
		operations_rotate.c \
		operations_swap.c \
		ps_utils.c \
		ps_utils1.c \
		stack.c \
		index.c \
		moves.c \
		algorithm.c \

all: $(NAME)

$(NAME): 
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -g

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY = all clean fclean re