# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/19 12:35:12 by hannkim           #+#    #+#              #
#    Updated: 2022/03/09 14:47:39 by hannkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= pipex
CC 			= gcc
ifdef DEBUG
	CFLAGS	= -g3
else
	CFLAGS		= -Wall -Wextra -Werror
endif
AR			= ar rcs
RM			= rm -f

LIBFT_DIR 		= ./lib/libft/
LIBFT_FLAGS		= -L ./$(LIBFT_DIR) -lft

HEADERS 		= ./includes/
SRCS_DIR		= ./srcs/

SRC				= main.c parsing.c
SRCS			= $(addprefix $(SRCS_DIR), $(SRC))
OBJS 			= $(SRCS:.c=.o)


.c.o:
	$(CC) $(CFLAGS) -I $(HEADERS) -o $@ -c $?


$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_FLAGS) -I $(HEADERS)

.PHONY	: all
all		: $(NAME)

.PHONY	: clean
clean	:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS) a.out a.out.dSYM

.PHONY	: fclean
fclean	: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) a.out a.out.dSYM

.PHONY	: cc
cc 		: $(NAME) $(SOURCES)

.PHONY	: re
re		: fclean all

.PHONY	: debug
debug	:
	make DEBUG=1 all
