# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rohta <rohta@student.42.jp>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 15:47:33 by rohta             #+#    #+#              #
#    Updated: 2024/11/20 16:48:59 by rohta            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c check_all_arg.c check_over_dig_dup.c delete_node.c\
      found_near_node.c free_mem.c list.c push_command.c reverse_rotate_command.c\
      reverse_sort_3.c rotate_command.c sort_100.c sort_2.c sort_3.c\
      sort_4.c sort_5.c sort_500.c sort_6.c swap_command.c
OBJ = $(SRC:.c=.o)
LIBFT_DIR = ./libft
LIBFT_OBJ = $(LIBFT_DIR)/ft_*.o

INC = -I ./libft
LIB = -L $(LIBFT_DIR) -lft

all: $(NAME)

$(NAME): $(LIBFT_OBJ) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT_OBJ):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	
re: fclean all

.PHONY: all clean fclean re

