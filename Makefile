# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 14:14:26 by ciclo             #+#    #+#              #
#    Updated: 2023/01/22 23:11:18 by ciclo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
MLX		= mlx_linux_linux.a
CC		= clang -g
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf
MLX_CF	= -lm -lbsd -lmlx -lXext -lX11
MLX_PATH 	= ./mlx_linux/

SRC_DIR = src/
OBJ_DIR = obj/

SRC_FILES = so_long check_map read_map utlis

#debuggers
val :=  valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
SANI := -fsanitize=address -g3

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF = .cache_exists

$(NAME): $(OBJ)
	@mkdir -p bin
	@make -C libft
	@mv libft/libft.a bin/
	@make -C $(MLX_PATH)
	@$(CC) $(CFLAGS) $(OBJ) bin/libft.a -Lbin -lft -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -o $(NAME)
	@echo "so_long compilando!"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@$(CC) -g $(CFLAGS) -c $< -o $@
	@echo "Compilando $< "

$(OBJF):
	@mkdir -p $(OBJ_DIR)

all: $(NAME)

clean:
	@$(RM) $< $(OBJ_DIR)
	@$(RM) bin
	@make -C libft clean
	@make -C mlx_linux clean
	@echo "clean done 🧹"

fclean: clean
	@$(RM) $(NAME)
	@make -C libft fclean
	@make clean -C $(MLX_PATH)
	@echo "fclean done 🗑"

re: fclean all

.PHONY: all clean fclean re

normi-i:
	python3 -m venv venv
	. venv/bin/activate
	pip install norminette
normi:
	norminette
tree:
	tree > esquema
