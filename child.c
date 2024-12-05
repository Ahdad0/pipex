#include "pipex.h"

void child(pid_t pipefd[2], char **av)
{
	char	**agv;
	char	*path;

	agv = ft_split_cpy(av[2], ' ', av[1]);
	if (!agv)
		exit(EXIT_FAILURE);
	path = add(av[2]);
	
	if (!path)
	{
		free_prev(agv, strlen(*agv) - 1);
		exit(EXIT_FAILURE);
	}
	close(pipefd[0]);
	dup2(pipefd[1], 1);
	if (execve(path, agv, environ) == -1)
	{
		free(path);
		free_prev(agv, strlen(*agv) - 1);
		perror("execve failed"); 
		exit(EXIT_FAILURE);
	}
	free(path);
	free_prev(agv, strlen(*agv) - 1);
	close(pipefd[1]);
}
