# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 12:38:09 by settaqi           #+#    #+#              #
#    Updated: 2019/11/08 13:56:05 by settaqi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

file_srcslibft = $(wildcard *.c)

OBJECTS = *.o

all: $(NAME)

$(NAME):
	@gcc -c -Wextra -Werror -Wall $(file_srcslibft)
	@ar rc libftprintf.a $(OBJECTS)
	@ranlib $(NAME)

clean:
	@/bin/rm -rf $(OBJECTS)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re
