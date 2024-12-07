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
		perror("d");
	}
}

static char	*parent_pro(int fd[2])
{
	char	buffer[50];
	int		byte;
	char	*new;

	close(fd[1]);
	byte = read(fd[0], buffer, sizeof(buffer));
	if (byte == -1 || byte == 0)
	{
		if (access(buffer, X_OK) == -1)
		{
			// write(2, s, ft_strlen(s));
			// write(2, ": ", 2);
			// write(2, ": Command not found!\n", 21);
			perror("");
		}
		exit(EXIT_FAILURE);
	}
	buffer[byte - 1] = '\0';
	close(fd[0]);
	// if (access(buffer, X_OK) == -1)
	// {
	// 	perror("");
	// 	return (NULL);
	// }
	new = ft_strdup(buffer);
	if (new == NULL)
		return (NULL);
	return (new);
}

char	*get_path(char *s)
{
	int	fd[2];
	char	*path;
	pid_t	id;

	path = NULL;
	if (pipe(fd) == -1 || (id = fork()) == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	if (id == 0)
	{
		child_pro(fd, s);
	}
	else
	{
		wait(NULL);
		path = parent_pro(fd);
		if (path == NULL)
			return (NULL);
	}
	return (path);
}
