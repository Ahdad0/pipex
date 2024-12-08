#include "pipex.h"

void	parent(int ac, char **av)
{
	char	**agv;
	char	*path;
	int		fd1;

	fd1 = open(av[ac - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd1 == -1)
	{
		write(1, av[ac - 1], ft_strlen(av[ac - 1]));
		write(1, ": ", 2);
		perror("");
		exit(EXIT_FAILURE);
	}
	agv = ft_split(av[ac - 2], ' ');
	if (!agv || !agv[0])
	{
		write(2, "Command not found\n", 19);
		exit(EXIT_FAILURE);
	}
	path = add(agv[0]);
	if (!path)
	{
		free_prev(agv, len_matrix(agv) - 1);
		exit(EXIT_FAILURE);
	}
	// close(pipefd[1]);
	// dup2(pipefd[0], 0);
	dup2(fd1, 1);
	if (execve(path, agv, NULL) == -1)
	{
		free(path);
		free_prev(agv, len_matrix(agv) - 1);
		perror("execve parent");
		exit(EXIT_FAILURE);
	}
	free(path);
	free_prev(agv, len_matrix(agv) - 1);
	close(fd1);
}
