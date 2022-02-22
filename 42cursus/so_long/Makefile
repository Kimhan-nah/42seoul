# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/19 12:35:12 by hannkim           #+#    #+#              #
#    Updated: 2022/02/22 15:25:31 by hannkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
RM = rm -f
MAKE = make
SOURCES = srcs/

LIBDIR = libft
HEADERS = includes

OBJECTS = $(SOURCES:.c=.o)

$(NAME): $(OBJ_FILES)
	$(MAKE) -C ./srcs/libft
	cp ./libft/libft.a ./$(NAME)
	$(AR) $(ARFLAGS) $(NAME) $^

.PHONY	: all
all		: $(NAME)

.PHONY	: clean
clean	:
	$(MAKE) -C libft clean
	$(RM) $(OBJECTS)

.PHONY	: fclean
fclean	: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME)

.PHONY	: cc
cc 		: $(NAME) $(SOURCES)

.PHONY	: re
re		: fclean all
