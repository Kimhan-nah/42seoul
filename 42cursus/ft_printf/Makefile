# **************************************************************************** 
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/05 22:55:37 by hannkim           #+#    #+#              #
#    Updated: 2021/10/02 18:10:14 by hannkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar
MAKE = make
ARFLAGS = rcs
SOURCES = srcs/mandatory/ft_printf.c \
		 srcs/mandatory/parsing.c \
		 srcs/mandatory/specifier_idu.c \
		 srcs/mandatory/specifier_cs.c \
		 srcs/mandatory/specifier_p.c \
		 srcs/mandatory/specifier_x.c \
		 srcs/mandatory/printf_utils.c \
		 srcs/mandatory/print_specifier.c

B_SOURCES = srcs/bonus/ft_printf_bonus.c \
		 srcs/bonus/parsing_bonus.c \
		 srcs/bonus/specifier_idu_bonus.c \
		 srcs/bonus/specifier_cs_bonus.c \
		 srcs/bonus/specifier_p_bonus.c \
		 srcs/bonus/specifier_x_bonus.c \
		 srcs/bonus/printf_utils_bonus.c \
		 srcs/bonus/print_specifier_bonus.c

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
	$(AR) $(ARFLAGS) $(NAME) $^

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
