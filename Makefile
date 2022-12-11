# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 14:14:26 by ciclo             #+#    #+#              #
#    Updated: 2022/12/11 15:20:01 by ciclo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC_DIR = src/
OBJ_DIR = obj/

SRC_FILES = so_long

#debuggers
val :=  valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
SANI := -fsanitize=address -g3

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF = .cache_exists

$(NAME): $(OBJ)
	@make -C libft
	@mkdir -p bin
	@mv libft/libft.a bin/libft.a
	@$(CC) $(CFLAGS) $(OBJ) bin/libft.a -o $(NAME)
	@echo "so_long compilando!"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compilando $<"

$(OBJF):
	@mkdir -p $(OBJ_DIR)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJSF)
	make -C libft clean

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
