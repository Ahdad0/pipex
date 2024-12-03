#include "pipex.h"

void	free_prev(char **res, int i)
{
	while (i--)
		free(res[i]);
	free(res);
	
}

static int	count_word(const char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			word++;
		i++;
	}
	return (word);
}

static char	**ft_util(char **res, const char *s, char c, int c_word)
{
	int	i;
	int	j;
	int	e;
	int	len;

	i = 0;
	j = 0;
	while (i < c_word)
	{
		while (s[j] && s[j] == c)
			j++;
		e = j;
		while (s[j] && s[j] != c)
			j++;
		len = j - e;
		res[i] = malloc(len + 1);
		if (!res[i])
			return (free_prev(res, i), NULL);
		ft_memcpy(res[i], s + e, len);
		res[i][len] = '\0';
		i++;
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split_cpy(char const *s, char c, char *av)
{
	char	**res;
	int		c_word;

	if (!s)
		return (NULL);
	c_word = count_word(s, c);
	res = malloc(sizeof(char *) * (c_word + 2));
	if (res == NULL)
		return (NULL);
	ft_util(res, s, c, c_word);
	res[c_word++] = av;
	res[c_word] = NULL;
	return (res);
}
