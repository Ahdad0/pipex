#include "pipex.h"

static char	*helper_allocation(char *s)
{
	int		len;
	char	*new;

	len = ft_strlen(s) + ft_strlen("/usr/bin/");
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	return (new);
}

static void	helper_cpy(char *s, char *new)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	j = 0;
	path = "/usr/bin/";
	while (path[i])
	{
		new[i] = path[i];
		i++;
	}
	while (s[j])
		new[i++] = s[j++];
	new[i] = '\0';
}

char	*add(char *s)
{
	char	*new;
	int		j;
	int		id;

	
	j = 0;
	if (strchr(s, ' ') != NULL)
	{
		while (s[j] != ' ')
			j++;
		s[j] = '\0';
	}
	new = helper_allocation(s);
	if (!new)
		return (NULL);
	helper_cpy(s, new);
	return (new);
}
