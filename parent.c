#include "pipex.h"

void	parent(pid_t pipefd[2], char **av)
{
	close(pipefd[1]);
	int fd1 = open("output.txt", O_RDWR);
	dup2(pipefd[0], 0);
	close(pipefd[0]);
	dup2(fd1, 1);
	close(fd1);
	char *aggv[] = {"cat", "-e", NULL};
	if (execve("/usr/bin/cat", aggv, NULL) == -1)
		exit(EXIT_FAILURE);
}
