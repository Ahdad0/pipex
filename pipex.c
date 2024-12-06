#include "pipex.h"
#include <stdlib.h>

static void	print_error(char *s)
{
	write(2, s, sizeof(s));
	write(2, ": ", 2);
	perror("");
}

static int	check_file(char *av)
{
	if (access(av, F_OK) == -1 || access(av, R_OK) == -1)
	{
		print_error(av);
		return (-1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	pid_t	pipefd[2];
	int	id;

	if (ac != 5)
	{
		write(2, "few argument!\n", 14);
		exit(EXIT_FAILURE);
	}
	if (check_file(av[1]) == -1)
		exit(EXIT_FAILURE);
	if (pipe(pipefd) == -1 || (id = fork()) == -1)
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
