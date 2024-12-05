#include "pipex.h"

char	*add(char *s)
{
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
	if (!path)
		return (NULL);
	return (path);
}
