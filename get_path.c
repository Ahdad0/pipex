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
char *get_path(char *av)
{
	char *s = "PATH";
	char *path;
	int i = 0, j = 0;
	while (environ[i])
	{
		if (environ[i][0] == 'P')
		{
			j = 0;
			while (environ[i][j] == s[j])
				j++;
			if (s[j] == '\0')
				path = environ[i];
		}
		i++;
	}
	char *ori = sub(path);
	int p = 0;
	while (1)
	{
		char *new = sub_colon(ori, &p);
		char *npath = ft_strjoin(new, av);
		if (access(npath, X_OK) != -1)
			return (npath);
		if (strchr(ori + p, ':') == NULL)
			break;
		p++;
	}
	return (NULL);
}
