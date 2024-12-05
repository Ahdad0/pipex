#include "pipex.h"

static void	child_pro(int fd[2], char *s)
{
	char *av[3];

	av[0] = "which";
	av[1] = s;
	av[2] = NULL;
	dup2(fd[1], 1);
	close(fd[1]);
	if (execve("/usr/bin/which", av, environ) == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	exit(0);
}

static char	*parent_pro(int fd[2])
{
	char	buffer[50];
	int		byte;
	char	*new;

	byte = read(fd[0], buffer, sizeof(buffer));
	buffer[byte - 1] = '\0';
	new = ft_strdup(buffer);
	return (new);
}

char	*get_path(char *s)
{
	int	fd[2];
	char	*path;
	pid_t	id;

	if (pipe(fd) == -1 || (id = fork()) == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	if (id == 0)
		child_pro(fd, s);
	else
	{
		wait(NULL);
		path = parent_pro(fd);
	}
	return (path);
}
