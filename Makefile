# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niludwig <niludwig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/08 01:33:55 by niludwig          #+#    #+#              #
#    Updated: 2017/03/19 22:19:17 by niludwig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
CC = gcc
CFLAG = -Wall -Werror -Wextra
SRC = main.c init_one.c init_two.c algo.c get_link.c find_path.c sheck.c \
	get_room.c invalid_way.c pound_on.c get_info.c
OBJ = $(SRC:.c=.o)
LIBFT_PATH = ./libft/libft/
PRINTF_PATH = ./libft/
PRINTF = ./libft/libftprintf.a
LIBFT = ./libft/libft/libft.a
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(PRINTF_PATH)
	@$(MAKE) -C $(LIBFT_PATH)
	@$(CC) -o $(NAME) $(OBJ) -L. $(LIBFT) $(PRINTF)

%.o: %.c
	@$(CC) $(CFLAG) -o $@ -c $<

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(RM) $(OBJ)

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)

re: fclean all
