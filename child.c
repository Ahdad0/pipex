#include "pipex.h"

void child(pid_t pipefd[2], char **av)
{
	char	**agv;
	char	*path;
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	agv = ft_split(av[2], ' ');
	if (!agv || !agv[0])
		exit(EXIT_FAILURE);
	path = add(agv[0]);
	if (!path)
	{
		free_prev(agv, len_matrix(agv) - 1);
		exit(EXIT_FAILURE);
	}
	dup2(fd, 0);
	dup2(pipefd[1], 1);
	if (execve(path, agv, environ) == -1)
	{
		free(path);
		free_prev(agv, len_matrix(agv) - 1);
		perror("execve child"); 
		exit(EXIT_FAILURE);
	}
	close(pipefd[1]);
	free(path);
	free_prev(agv, len_matrix(agv) - 1);
	exit(0);
}
