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
