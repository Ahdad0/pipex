SRCS = pipex.c child.c parent.c ft_split_cpy.c ft_memcpy.c ft_split.c add.c ft_strlen.c\
	get_path.c

CFLAGS = -Wall -Wextra -Werror

CC = cc

NAME = pipex

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SECONDARY:
