# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emallah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/02 20:56:10 by emallah           #+#    #+#              #
#    Updated: 2019/12/03 23:06:43 by emallah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

all : $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c *.c
	@ar -rc $(NAME) *.o
clean:
	@rm -f *.o
fclean: clean
	@rm -f $(NAME)
re: fclean all
