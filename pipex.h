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

#endif
