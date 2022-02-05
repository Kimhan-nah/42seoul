
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
MAKE = make
SOURCES = srcs/push_swap.c \

LIBDIR = libft
HEADERS = includes

OBJECTS = $(SOURCES:.c=.o)

$(NAME): $(OBJECTS)
	$(MAKE) -C ./libft
	cp libft/libft.a ./$(NAME)
	$(NAME) $^

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
