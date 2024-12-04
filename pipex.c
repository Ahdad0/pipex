#include "pipex.h"
#include <stdlib.h>

int main(int ac, char **av)
{
	int	id;

	if (ac != 5)
	{
		write(1, "few argument!\n", 14);
		exit(EXIT_FAILURE);
	}
	if (access(av[1], F_OK) == -1 || access(av[1], R_OK) == -1)
	{
		write(1, av[1], sizeof(av[1]));
		write(1, ": ", 2);
		perror("");
		exit(EXIT_FAILURE);
	}
	pid_t pipefd[2];
	if (pipe(pipefd) == -1)
	{
        perror("pipe");
		exit(EXIT_FAILURE);
    }
	if ((id = fork()) == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (id == 0)
		child(pipefd, av);
	else
	{
		wait(NULL);
		parent(pipefd, av);
	}
	exit(EXIT_SUCCESS);
}
