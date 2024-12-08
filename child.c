#include "pipex.h"

void child(int ac, char **av)
{
	char	**agv;
	char	*path;
	int pipefd[2];
	int id;
	int i = 2;

	pipe(pipefd);
	id = fork();
	while (i < ac - 2)
	{
		if (id == 0)
		{
			close(pipefd[0]);
			agv = ft_split(av[i], ' ');
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
			dup2(pipefd[1], 1);
			close(pipefd[1]);
			if (execve(path, agv, environ) == -1)
			{
				free(path);
				free_prev(agv, len_matrix(agv) - 1);
				perror("execve child"); 
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			// agv = ft_split(av[3], ' ');
			// if (!agv || !agv[0])
			// {
			// 	write(2, "Command not found\n", 19);
			// 	exit(EXIT_FAILURE);
			// }
			// path = add(agv[0]);
			// if (!path)
			// {
			// 	free_prev(agv, len_matrix(agv) - 1);
			// 	exit(EXIT_FAILURE);
			// }
			wait(NULL);
			close(pipefd[1]);
			dup2(pipefd[0], 0);
			close(pipefd[0]);
			// free(path);
			// free_prev(agv, len_matrix(agv) - 1);
			// close(fd1);
		}
		i++;
	}
	parent(ac, av);
}
