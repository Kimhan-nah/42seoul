# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/19 12:35:12 by hannkim           #+#    #+#              #
#    Updated: 2022/02/19 15:34:33 by hannkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
MAKE = make
SOURCES = srcs/

B_SOURCES = srcs/bonus/
LIBDIR = libft
HEADERS = includes

OBJECTS = $(SOURCES:.c=.o)
B_OBJECTS = $(B_SOURCES:.c=.o)

ifdef IS_BONUS
	OBJ_FILES = $(B_OBJECTS)
else
	OBJ_FILES = $(OBJECTS)
endif

$(NAME): $(OBJ_FILES)
	$(MAKE) -C ./libft
	cp libft/libft.a ./$(NAME)

.PHONY	: all
all		: $(NAME)

.PHONY	: bonus
bonus	:
	@$(MAKE) IS_BONUS=1 all

.PHONY	: clean
clean	:
	$(MAKE) -C libft clean
	$(RM) $(OBJECTS) $(B_OBJECTS)

.PHONY	: fclean
fclean	: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME)

.PHONY	: cc
cc 		: $(NAME) $(SOURCES)

.PHONY	: re
re		: fclean all
