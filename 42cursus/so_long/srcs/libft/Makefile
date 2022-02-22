# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 16:37:29 by hannkim           #+#    #+#              #
#    Updated: 2022/02/22 15:11:11 by hannkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar
ARFLAGS = rcs
FUNC = ft_bzero \
	   ft_calloc \
	   ft_isalnum \
	   ft_isalpha \
	   ft_isascii \
	   ft_isdigit \
	   ft_isprint \
	   ft_memccpy \
	   ft_memchr \
	   ft_memcmp \
	   ft_memcpy \
	   ft_memmove \
	   ft_memset \
	   ft_strchr \
	   ft_strdup \
	   ft_strlcat \
	   ft_strlcpy \
	   ft_strlen \
	   ft_strncmp \
	   ft_strnstr \
	   ft_strrchr \
	   ft_tolower \
	   ft_toupper \
	   ft_substr \
	   ft_strjoin \
	   ft_strtrim \
	   ft_split \
	   ft_itoa \
	   ft_strmapi \
	   ft_putchar_fd \
	   ft_putstr_fd \
	   ft_putendl_fd \
	   ft_putnbr_fd \
	   ft_atoi \
	   ft_lstnew \
	   ft_lstadd_front \
	   ft_lstsize \
	   ft_lstlast \
	   ft_lstadd_back \
	   ft_lstdelone \
	   ft_lstclear \
	   ft_lstiter \
	   ft_lstmap


SRCS = $(addsuffix .c, $(FUNC))

OBJS = $(SRCS:.c=.o)

.PHONY	: all
all 	: $(NAME)

$(NAME) : $(OBJ_FILES)
	$(AR) $(ARFLAGS) $(NAME) $^

.PHONY	: clean
clean 	:
	rm -rf $(OBJS)

.PHONY	: fclean
fclean	: clean
	rm -rf $(NAME)

.PHONY	: re
re		: fclean all
