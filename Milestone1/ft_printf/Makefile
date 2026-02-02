CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a

SRC = ft_printf.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putnbr.c \
		ft_un_putnbr.c \
		ft_hex.c \
		ft_pointer.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY = all clean fclean re