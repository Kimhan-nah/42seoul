# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/19 12:35:12 by hannkim           #+#    #+#              #
#    Updated: 2022/03/05 12:57:42 by hannkim          ###   ########.fr        #
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

GNL_DIR			= ./lib/gnl/
GNL_FLAGS		= -L ./$(GNL_DIR) -lgnl

HEADERS 		= ./includes/
SRCS_DIR		= ./srcs/

SRC				= main.c
SRCS			= $(addprefix $(SRCS_DIR), $(SRC))
OBJS 			= $(SRCS:.c=.o)


.c.o:
	$(CC) $(CFLAGS) -I $(HEADERS) -o $@ -c $?


$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(GNL_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(GNL_FLAGS) $(LIBFT_FLAGS) -I $(HEADERS) -L 

.PHONY	: all
all		: $(NAME)

.PHONY	: clean
clean	:
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean
	$(RM) $(OBJS) a.out a.out.dSYM

.PHONY	: fclean
fclean	: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean
	$(RM) $(NAME) a.out a.out.dSYM

.PHONY	: cc
cc 		: $(NAME) $(SOURCES)

.PHONY	: re
re		: fclean all

.PHONY	: debug
debug	:
	make DEBUG=1 all
