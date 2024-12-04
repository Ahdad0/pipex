#include "pipex.h"

static char	*helper_allocation(char *s)
{
	int		len;
	char	*new;

	len = ft_strlen(s);
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	return (new);
}

static char	*get_path(char *s)
{
	int	fd[2];
	int	id;
	char	*agv[] = {"which", s, NULL};
	int	byte;
	char	*path;

	path = malloc(20);
	if (!path)
		return (NULL);
	if (pipe(fd) == -1 || (id = fork()) == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	if (id == 0)
	{
		dup2(fd[1], 1);
		execve("/usr/bin/which", agv, NULL);
	}
	else
	{
		wait(NULL);
		byte = read(fd[0], path, sizeof(path));
		if (byte == -1)
			exit(EXIT_FAILURE);
		path[byte] = '\0';
	}
	
	return (path);
}

static void	helper_cpy(char *s, char *new)
{
	int		i;
	char	*path;

	i = 0;
	path = get_path(s);
	while (path[i])
	{
		new[i] = path[i];
		i++;
	}
	new[i] = '\0';
}

char	*add(char *s)
{
	char	*new;
	int		j;
	
	j = 0;
	if (strchr(s, ' ') != NULL)
	{
		while (s[j] != ' ')
			j++;
		s[j] = '\0';
	}
	new = helper_allocation(get_path(s));
	if (!new)
		return (NULL);
	helper_cpy(s, new);
	return (new);
}
