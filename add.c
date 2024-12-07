#include "pipex.h"

char	*add(char *s)
{
	char	*path;
	
	if (s[0] == '/')
	{
		if (access(s, F_OK) == -1)
		{
			// write(2, s, ft_strlen(s));
			// write(2, ": ", 2);
			perror(s);
			exit(127);
		}
		else
			return (s);
	}
	path = get_path(s);
	if (!path)
		return (NULL);
	return (path);
}
