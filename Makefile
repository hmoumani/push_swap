# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/15 18:50:07 by hmoumani          #+#    #+#              #
#    Updated: 2021/06/18 14:54:52 by hmoumani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS=push_swap.c tools.c tools1.c operations.c operations1.c operations2.c

FLAGS=-Wextra -Wall -Werror -fsanitize=address

NAME=push_swap

$(NAME):
	gcc $(FLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

re: fclean $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean