#include "pipex.h"
#include <stdlib.h>

int main(int ac, char **av)
{
	if (ac < 1)
	{
		printf("few arguments!");
		return (1);
	}
	int id;
	pid_t pipefd[2];
	if (pipe(pipefd) == -1)
	{
        perror("pipe");
        return 1;
    }
	if ((id = fork()) == -1)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	if (id == 0)
		child(pipefd, av);
	else
	{
		wait(NULL);
		parent(pipefd, av);
	}
}
