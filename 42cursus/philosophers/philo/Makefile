# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 14:54:52 by hannkim           #+#    #+#              #
#    Updated: 2022/05/08 20:13:13 by hannah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= philo
CC 			= cc
ifdef DEBUG
	CFLAGS	= -g3
else
	CFLAGS = -Wall -Wextra -Werror
endif
AR			= ar rcs
RM			= rm -f


HEADERS 		= ./includes/
SRCS_DIR		= ./srcs/

SRC				= main.c parsing.c utils.c thread.c action.c error.c
SRCS			= $(addprefix $(SRCS_DIR), $(SRC))
OBJS 			= $(SRCS:.c=.o)


.c.o:
	$(CC) $(CFLAGS) -I $(HEADERS) -o $@ -c $?


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I $(HEADERS)

.PHONY	: all
all		: $(NAME)

.PHONY	: clean
clean	:
	$(RM) $(OBJS) a.out a.out.dSYM

.PHONY	: fclean
fclean	: clean
	$(RM) $(NAME) a.out a.out.dSYM

.PHONY	: cc
cc 		: $(NAME) $(SOURCES)

.PHONY	: re
re		: fclean all

.PHONY	: debug
debug	:
	make DEBUG=1 all
