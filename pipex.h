#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

void	child(pid_t pipefd[2], char **av);
void	parent(pid_t pipefd[2], char **av);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split_cpy(char const *s, char c, char *av);
char	**ft_split(char const *s, char c);

#endif
