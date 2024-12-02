#include "pipex.h"

void child(pid_t pipefd[2], char **av)
{
	char	b[1024];

	close(pipefd[0]);
	int fd = open("file.txt", O_RDONLY);
	int end = read(fd, b, sizeof(b));
	b[end] = '\0';
	dup2(pipefd[1], 1);
	char *agv[] = {"cat", av[1], NULL};
	if (execve("/usr/bin/cat", agv, NULL) == -1)
		exit(EXIT_FAILURE);
	close(pipefd[1]);
}
