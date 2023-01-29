# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 14:14:26 by ciclo             #+#    #+#              #
#    Updated: 2023/01/29 21:19:34 by ciclo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long
MLX			:= mlx_linux_linux.a
CC			:= clang -g
CFLAGS		:= -Wall -Wextra -Werror
RM			:= rm -rf
MLX_CF		:= -framework OpenGL -framework AppKit
MLX_PATH 	:= ./minilibx_macos
SRC_DIR 	:= src/
OBJ_DIR 	:= obj/
SRC_FILES 	:= so_long  read_map get_images check_map utils moves
#debuggers
val 		:=  valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
SANI 		:= -fsanitize=address -g3

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF = .cache_exists

ifeq ($(shell uname), Linux)
$(NAME): MLX_CF	= -L./mlx_linux -lmlx_Linux -lXext -lX11
$(NAME): MLX_PATH = ./mlx_linux
endif

$(NAME): $(OBJ)
	@mkdir -p bin
	@make -C libft
	@mv libft/libft.a bin/
	@make -C $(MLX_PATH) 2>/dev/null
	@mv	$(MLX_PATH)/libmlx.a bin/
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_CF) bin/*.a -o $(NAME)
	@echo "so_long compilando!"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@$(CC) -g $(CFLAGS)   -c $< -o $@
	@echo "Compilando $< "

$(OBJF):
	@mkdir -p $(OBJ_DIR)

all: $(NAME)

clean:
	@$(RM) $< $(OBJ_DIR)
	@$(RM) bin
	@make -C libft clean
	@make -C $(MLX_PATH) clean
	@echo "clean done 🧹"

fclean: clean
	@$(RM) $(NAME)
	@make -C libft fclean
	@make clean -C $(MLX_PATH)
	@echo "fclean done 🗑"

re: fclean all

.PHONY: all clean fclean re

normi-i:
	@python3 -m venv venv
	@. venv/bin/activate
	@pip install norminette
normi:
	@norminette
tree:
	@tree > esquema
