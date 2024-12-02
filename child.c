#include "pipex.h"

void child(pid_t pipefd[2], char **av)
{
	close(pipefd[0]);
	int fd = open(av[1], O_RDONLY);
	dup2(pipefd[1], 1);
	char *agv[] = {"cat", av[1], NULL};
	if (execve("/usr/bin/cat", agv, NULL) == -1)
		exit(EXIT_FAILURE);
	close(pipefd[1]);
}
