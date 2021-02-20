# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emallah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/02 20:56:10 by emallah           #+#    #+#              #
#    Updated: 2019/12/10 10:47:21 by emallah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

files = ft_conversion.c ft_free.c ft_flags.c ft_itoa.c ft_printf.c len.c ft_putstr.c ft_itoh.c\
		is_what.c rest_and_flags.c s_and_flags.c rest_output_2.c rest_output_1.c

all : $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(files)
	@ar -rc $(NAME) *.o
clean:
	@rm -f *.o
fclean: clean
	@rm -f $(NAME)
re: fclean all
