NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf_utils.c ft_printf.c 
OBJ = $(SRC:.c=.o)
MAKEFLAGS += -s

all : $(NAME)

.PHONY: clean fclean

#borrar
comp:
	$(CC) $(SRC) main.c libft.a
san:
	$(CC) -fsanitize=address -g $(SRC) main.c libft.a 

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm a.out

fclean: clean
	rm -f $(NAME)

re: fclean all
