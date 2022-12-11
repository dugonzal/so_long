# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 14:14:26 by ciclo             #+#    #+#              #
#    Updated: 2022/12/11 14:36:07 by ciclo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS_DIR = srcs/
OBJS_DIR = obj/

SRC_FILES = so_long

#debuggers
val :=  valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
SANI := -fsanitize=address -g3

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))

OBJSF = .cache_exists

$(NAME) : $(OBJS)
	make -C libft
	mkdir -p bin
	mv libft/libft.a bin/libft.a

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJSF) :


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
