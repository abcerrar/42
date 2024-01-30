# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcolera- <dcolera-@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 20:03:56 by dcolera-          #+#    #+#              #
#    Updated: 2024/01/29 20:03:58 by dcolera-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf_utils.c ft_printf.c 
OBJ = $(SRC:.c=.o)
LIBFTDIR = ./libft
LIBFTNAME = libft.a

all : $(NAME)

.PHONY:	all clean fclean re

makelibft:
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFTNAME) .
	mv $(LIBFTNAME) $(NAME)
	

$(NAME): makelibft $(OBJ) 
	ar rcs $(NAME) $(OBJ) 

clean:
	rm -f $(OBJ)
	cd $(LIBFTDIR) && make clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBFTDIR) && make fclean

re: fclean all
