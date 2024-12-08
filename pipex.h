#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

extern char **environ;

void	child(int ac, char **av);
void	parent(int ac, char **av);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split_cpy(char const *s, char c, char *av);
char	**ft_split(char const *s, char c);
char	*add(char *s);
void	free_prev(char **res, int i);
size_t	ft_strlen(char *s);
char	*get_path(char *s);
char	*ft_strdup(char *s);
size_t	len_matrix(char **s);
char	*ft_strjoin(char *s1, char *s2);

#endif
