#include "pipex.h"

char	*add(char *s)
{
	char	*new;
	int		j;
	char	*path;
	
	j = 0;
	if (strchr(s, ' ') != NULL)
	{
		while (s[j] != ' ')
			j++;
		s[j] = '\0';
	}
	path = get_path(s);
	new = ft_strdup(path);
	if (!new)
	{
		free(path);
		return (NULL);
	}
	free(path);
	return (new);
}
