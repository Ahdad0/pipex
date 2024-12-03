#include "pipex.h"

void child(pid_t pipefd[2], char **av)
{
	close(pipefd[0]);
	dup2(pipefd[1], 1);
	char **agv = ft_split_cpy(av[2], ' ', av[1]);
	if (!agv)
		exit(EXIT_FAILURE);
	char *path = add(av[2]);
	if (!path)
	{
		free_prev(agv, strlen(*agv) - 1);
		exit(EXIT_FAILURE);
	}
	if (execve(path, agv, NULL) == -1)
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
