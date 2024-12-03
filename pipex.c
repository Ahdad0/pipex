#include "pipex.h"
#include <stdlib.h>

int main(int ac, char **av)
{
	(void)ac;
	/*if (ac < 5)
	{
		printf("few argument!");
		return (1);
	}
	if (access(av[1], F_OK) == -1 || access(av[1], R_OK) == -1)
	{
		printf("%s: %s\n", av[1], strerror(errno));
		exit(EXIT_FAILURE);
	}*/
	int id;
	pid_t pipefd[2];
	if (pipe(pipefd) == -1)
	{
        perror("pipe");
        return 1;
    }
	if ((id = fork()) == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (id == 0)
	{
		child(pipefd, av);
	}
	else
	{
		wait(NULL);
		parent(pipefd, av);
	}
	//exit(EXIT_SUCCESS);
}
