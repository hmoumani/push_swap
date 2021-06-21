# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/15 18:50:07 by hmoumani          #+#    #+#              #
#    Updated: 2021/06/21 20:26:46 by hmoumani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS=push_swap.c tools.c tools1.c tools2.c operations.c operations1.c operations2.c

FLAGS=-Wextra -Wall -Werror -g

NAME=push_swap

BONUS=checker

BONUS_SRC=checker.c tools.c tools1.c tools2.c get_next_line/get_next_line.c \
get_next_line/get_next_line_utils.c operations.c operations1.c operations2.c \
checker_tools.c


$(NAME):$(SRCS)
	gcc $(FLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

re: fclean $(NAME)

clean:
	rm -rf $(NAME)

bonus:
	gcc $(FLAGS) $(BONUS_SRC) -o $(BONUS)

fclean: clean