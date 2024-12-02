#include "pipex.h"
#include <stdlib.h>

int main(int ac, char **av)
{
	/*if (ac < 5)
	{
		printf("few arguments!");
		return (1);
	}*/
	int id;
	pid_t pipefd[2];
	char b[1024];
	int end;
	if (pipe(pipefd) == -1)
	{
        perror("pipe");
        return 1;
    }
	if ((id = fork()) == -1)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	if (id == 0)
	{
		close(pipefd[0]);
		int fd = open("file.txt", O_RDONLY);
		end = read(fd, b, sizeof(b));
		b[end] = '\0';
		dup2(pipefd[1], 1);
		char *agv[] = {av[2], av[1], NULL};
		if (execve("/usr/bin/cat", agv, NULL) == -1)
			exit(EXIT_FAILURE);
		close(pipefd[1]);
	}
	else
	{
		wait(NULL);
		close(pipefd[1]);
		int fd1 = open("output.txt", O_RDWR | O_CREAT, 0644);
		char s[1024];
		int e = read(pipefd[0], s, sizeof(b));
		s[e] = '\0';
		dup2(fd1, 1);
		printf("%s", s);
		char *aggv[] = {"cat", "-e", s, NULL};
		if (execve("/usr/bin/cat", aggv, NULL) == -1)
			exit(EXIT_FAILURE);
		close(pipefd[0]);
	}
}
