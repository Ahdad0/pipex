#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

static void	child_pro(pid_t fd[2], char *s)
{
	char *av[] = {"/usr/bin/which", s, NULL};

	av[0] = ;
	av[1] = s;
	av[2] = NULL;
	// dup2(fd[1], 1);
	if (execve("/usr/bin/which", av, NULL) == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	// close(fd[1]);
}

static char	*parent_pro(pid_t fd[2])
{
	char	buffer[50];
	int		byte;
	char	*new;

	byte = read(fd[0], buffer, 50);
	buffer[byte] = '\0';
	new = strdup(buffer);
	return (new);
}

static char	*get_path(char *s)
{
	pid_t	fd[2];
	char	*path;

	printf("ds");
	if (pipe(fd) == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	child_pro(fd, s);
	//path = parent_pro(fd);
	return (path);
}

int main()
{
	char *s = get_path("ls");
    printf("%s", s);
}