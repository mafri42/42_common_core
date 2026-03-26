CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap

SRC = push_swap.c \
		operations_push.c \
		operations_rev_rotate.c \
		operations_roate.c \
		operations_swap.c \
		ps_utils.c \
		stack.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY = all clean fclean re