SRCS = pipex.c child.c parent.c ft_split_cpy.c ft_memcpy.c ft_split.c add.c ft_strlen.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = cc

NAME = pipex

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SECONDARY:
