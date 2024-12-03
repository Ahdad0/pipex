#include "pipex.h"

void child(pid_t pipefd[2], char **av)
{
	close(pipefd[0]);
	dup2(pipefd[1], 1);
	char **agv = ft_split_cpy(av[2], ' ', av[1]);
	char *path = add(av[2]);

	if (execve(path, agv, NULL) == -1)
	{
		perror("execve failed"); 
		exit(EXIT_FAILURE);
	}
	close(pipefd[1]);
}
