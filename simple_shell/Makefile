NAME 		= pipex
CC 			= gcc
ifdef DEBUG
	CFLAGS	= -g3
else
	CFLAGS		= -Wall -Wextra -Werror
endif
AR			= ar rcs
RM			= rm -f

HEADERS 		= ./includes/
SRCS_DIR		= ./srcs/

SRC				= main.c parsing.c processor.c utils.c
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
