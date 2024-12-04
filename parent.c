#include "pipex.h"

void	parent(pid_t pipefd[2], char **av)
{
	char	**agv;
	char	*path;
	int		fd1;

	fd1 = open(av[4], O_WRONLY | O_CREAT, 0644);
	if (fd1 == -1)
	{
		write(1, av[4], sizeof(av[4]));
		write(1, ": ", 2);
		perror("");
		exit(EXIT_FAILURE);
	}
	close(pipefd[1]);
	dup2(pipefd[0], 0);
	close(pipefd[0]);
	dup2(fd1, 1);
	close(fd1);
	agv = ft_split(av[3], ' ');
	if (!agv)
		exit(EXIT_FAILURE);
	path = add(av[3]);
	if (!path)
	{
		free_prev(agv, strlen(*agv) - 1);
		exit(EXIT_FAILURE);
	}
	if (execve(path, agv, environ) == -1)
	{
		free(path);
		free_prev(agv, strlen(*agv) - 1);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	free(path);
	free_prev(agv, strlen(*agv) - 1);
}
