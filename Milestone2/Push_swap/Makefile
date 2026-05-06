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
		ps_utils2.c \
		stack.c \
		moves.c \
		algorithm.c \

all: $(NAME)

OBJS = $(SRC:.c=.o)

%.o: %.c
	@${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@ 

${NAME}: ${OBJS}
	@make -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME} -g

all: ${NAME}

clean:
	@make -C ./libft clean 
	@${RM}	${OBJS}	

fclean: clean
	@make -C ./libft fclean
	@${RM}	${NAME}	

re: fclean	all

.PHONY:	all	clean	fclean	re