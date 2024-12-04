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
