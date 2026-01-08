NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
		ft_printf_char.c \
		ft_printf_str.c \
		ft_printf_int.c \
		ft_printf_unsigned.c \
		ft_printf_hex.c \
		ft_printf_hexupper.c \
		ft_printf_address.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all