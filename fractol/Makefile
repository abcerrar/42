NAME = fractol
CC = gcc
CFLAGS = 

#Sources
SRC_PATH = src/
SRC = main.c
SRCS = $(addprefix $(SRC_PATH), $(SRC))

#MiniLibx
MLX_PATH	= minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

#Libft
LIBFT_PATH = libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

#Includes
INC			=	-I ./includes/\
				-I ./libft/\
				-I ./minilibx-linux/

#Objects
OBJ_PATH = obj/
OBJ = ${SRC:.c=.o}
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

all: $(MLX) $(LIBFT) ${NAME}

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(MLX):
	@echo "Creating mlx..."
	@make -sC $(MLX_PATH)

$(LIBFT):
	@echo "Creating libft..."
	@make -sC $(LIBFT_PATH)

$(NAME): $(OBJS)
	@echo "Compiling fractol..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INC) -lXext -lX11 -lm
	@echo "Fractol ready."

clean:
	@echo "Removing .o files..."
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@echo "Removing fractol..."
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

.PHONY: all re clean fclean
