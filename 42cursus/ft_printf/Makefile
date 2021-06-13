# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/05 22:55:37 by hannkim           #+#    #+#              #
#    Updated: 2021/06/11 20:33:20 by hannkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = libftprintf.a

SOURCE = srcs/ft_printf.c
LIBDIR = libft
HEADERS = includes
OBJECTS = $(SOURCE:.c=.o)

%o: %c
	$(CC) -c $(CFLAGS) $< -o $(OBJECTS) -I$(HEADERS) -I$(LIBDIR)
	#$(CC) -c $(CFLAGS) $< -o $(<:.c=.o) -I$(HEADERs) -I$(LIBDIR)

$(NAME): $(OBJECTS)
	$(MAKE) -C ./libft
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJECTS)
	#ranlib $(NAME)

all: $(NAME)

clean:
	$(MAKE) -C libft clean
	$(RM) $(OBJECTS)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
