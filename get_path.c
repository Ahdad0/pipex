#include "pipex.h"

static char *sub(char *path)
{
	char *new = malloc(1024);
	int i = 5, j = 0;
	while (path[i])
	{
		new[j++] = path[i];
		i++;
	}
	new[j] = '\0';
	return (new);
}

char *sub_colon(char *s, int *p)
{
	char *new  = malloc(1024);
	if (!new)
		return (NULL);
	int i = 0;
	while (s[*p])
	{
		if (s[*p] == ':')
		{
			break;
		}
		new[i++] = s[*p];
		(*p)++;
	}
	new[i++] = '/';
	new[i] = '\0';
	return (new);
}
static char	*env(char *path)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (environ[i])
	{
		if (environ[i][0] == 'P')
		{
			j = 0;
			while (environ[i][j] == path[j])
				j++;
			if (path[j] == '\0')
				new = ft_strdup(environ[i]);
		}
		i++;
	}
	return (new);
}

char *get_path(char *av)
{
	char *path;
	char *npath;
	char *new;

	path = env("PATH");
	char *ori = sub(path);
	free(path);
	int p = 0;
	while (1)
	{
		new = sub_colon(ori, &p);
		npath = ft_strjoin(new, av);
		free(new);
		if (access(npath, X_OK) != -1)
			return (free(ori), npath);
		free(npath);
		if (strchr(ori + p, ':') == NULL)
			break;
		p++;
	}
	if (access(av, X_OK) == -1)
	{
		free(ori);
		write(2, "Command not found: ", 20);
		write(2, av, ft_strlen(av));
		write(2, "\n", 1);
		exit(127);
	}
	return (free(ori), NULL);
}
