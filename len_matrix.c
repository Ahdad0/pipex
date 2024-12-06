#include "pipex.h"

size_t	len_matrix(char **s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}