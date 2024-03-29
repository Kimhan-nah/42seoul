# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/19 12:35:12 by hannkim           #+#    #+#              #
#    Updated: 2022/03/03 14:21:40 by hannah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= so_long
CC 			= gcc
ifdef DEBUG
	CFLAGS	= -g3
#CFLAGS		= -g3 -fsanitize=address
else
	CFLAGS		= -Wall -Wextra -Werror
endif
AR			= ar rcs
RM			= rm -f

LIBFT_DIR 		= ./lib/libft/
LIBFT_FLAGS		= -L ./$(LIBFT_DIR) -lft
#LIBFT_FILE		= $(LIBFT_DIR)libft.a

GNL_DIR			= ./lib/gnl/
GNL_FLAGS		= -L ./$(GNL_DIR) -lgnl
#GNL_FILE		= $(LIBFT_DIR)libgnl.a

HEADERS 		= ./includes/
SRCS_DIR		= ./srcs/
MLX_DIR			= ./mlx/
MLX_FLAGS		= -lmlx -framework OpenGL -framework Appkit

SRC				= main.c draw.c error.c check_file.c initialization.c event.c
SRCS			= $(addprefix $(SRCS_DIR), $(SRC))
OBJS 			= $(SRCS:.c=.o)


.c.o:
	$(CC) $(CFLAGS) -I $(HEADERS) -o $@ -c $?


$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(GNL_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(GNL_FLAGS) $(LIBFT_FLAGS) -I $(HEADERS) -L $(MLX_DIR) $(MLX_FLAGS)

.PHONY	: all
all		: $(NAME)

.PHONY	: clean
clean	:
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean
	make -C $(MLX_DIR) clean
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
