#include "pipex.h"

char	*add(char *s)
{
	char	*new;
	int	len;
	char	*path;

	if (strchr(s, ' ') != NULL)
	{
		int j = 0;
		while (s[j] != ' ')
			j++;
		s[j] = '\0';
	}
	path = "/usr/bin/";
	len = strlen(s) + strlen("/usr/bin/");
	printf("len=%d\n", len);
	new = malloc(len);
	if (!new)
		return (NULL);
	int i = 0;
	while (path[i])
	{
		new[i] = path[i];
		i++;
	}
	int o = 0;
	while (s[o])
	{
		new[i++] = s[o];
		o++;
	}
	new[i] = '\0';
	return (new);
}

void child(pid_t pipefd[2], char **av)
{
	close(pipefd[0]);
	dup2(pipefd[1], 1);
	char **agv = ft_split_cpy(av[2], ' ', av[1]);
	char *a[] = {"cat", av[1], NULL};
	printf("%s", agv[0]);
	if (execve("/usr/bin/cat", a, NULL) == -1)
	{
		 perror("execve failed"); 
		exit(EXIT_FAILURE);
	}
	close(pipefd[1]);
}
