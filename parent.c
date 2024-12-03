#include "pipex.h"

void	parent(pid_t pipefd[2], char **av)
{
	close(pipefd[1]);
	int fd1 = open(av[4], O_WRONLY);
	if (fd1 == -1)
	{
		printf("%s: %s\n", av[4], strerror(errno));
		exit(EXIT_FAILURE);
	}
	dup2(pipefd[0], 0);
	close(pipefd[0]);
	dup2(fd1, 1);
	close(fd1);
	char **agv = ft_split(av[3], ' ');
	if (execve(add(av[3]), agv, NULL) == -1)
		exit(EXIT_FAILURE);
}
