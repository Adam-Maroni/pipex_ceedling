#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv, char **envp)
{
	char *tab[3];

	tab[0] = "cat";
	tab[1] = "-e";
	tab[2] = NULL;
	int fd = open("inFile", O_RDWR);
	dup2(fd, STDIN_FILENO);
	execve("/usr/bin/cat", tab, envp);
	close(fd);
}
