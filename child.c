#include "pipex.h"

void child(pid_t pipefd[2], char **av)
{
	close(pipefd[0]);
	dup2(pipefd[1], 1);
	char **agv = ft_split(av[2], ' ', av[1]);
	if (execve("/usr/bin/cat", agv, NULL) == -1)
		exit(EXIT_FAILURE);
	close(pipefd[1]);
}
