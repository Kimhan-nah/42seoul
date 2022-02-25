# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/25 11:41:13 by hannkim           #+#    #+#              #
#    Updated: 2022/02/25 12:05:27 by hannkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libgnl.a
cc		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= get_next_line.c
OBJS	= $(SRCS:.c=.o)

all	:	$(NAME)

$(NAME) : $(OBJS)
	ar rcs $@ $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re	:
	make fclean
	make all

.PHONY: clean fclean re all

