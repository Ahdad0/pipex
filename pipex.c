#include "pipex.h"
#include <stdlib.h>

// static void	print_error(char *s)
// {
// 	perror(s);
// }

// static int	check_file(char **av)
// {
// 	if (access(av[1], F_OK) == -1)
// 	{
// 		print_error(av[1]);
// 		return (-1);
// 	}
	
// 	return (0);
// }

int	main(int ac, char **av)
{
	int		fd;

	if (ac < 5)
	{
		write(2, "few argument!\n", 14);
		exit(EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		perror(av[1]);
		exit(EXIT_FAILURE);
	}
	dup2(fd, 0);
	child(ac, av);
	exit(EXIT_SUCCESS);
}
