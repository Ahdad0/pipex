#include "pipex.h"

static void	child_pro(int fd[2], char *s)
{
	char **av;

	av[0] = "which";
	av[1] = s;
	av[2] = NULL;
	dup2(fd[1], 1);
	execve("/usr/bin/which", av, NULL);
}

static char	*parent_pro(int fd[1])
{
	char	buffer[1024];
	int	byte;

	byte = read(fd[0], buffer, sizeof(buffer));
	if (byte == 0)
		return;
	buffer[byte] = '\0';
	
}

char	*get_path(char *s)
{
	int	fd[2];
	int	id;
	char	*agv[] = {"which", s, NULL};
	int	byte;
	char	*path;

	if (pipe(fd) == -1 || (id = fork()) == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	child_pro(fd, s);
	path = parent_pro(fd);
	return (path);
}
