SRCS = pipex.c child.c parent.c ft_split_cpy.c ft_memcpy.c ft_split.c add.c ft_strlen.c\
	   get_path.c ft_strdup.c len_matrix.c ft_strchr.c ft_strjoin.c

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

CC = cc

NAME = pipex

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -g $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SECONDARY:
