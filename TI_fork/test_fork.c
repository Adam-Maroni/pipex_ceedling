#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv, char **envp)
{
	int pid = getpid();
	printf("PID = %d\n", pid);
	fork();
	pid = getpid();
	printf("PID = %d\n", pid);
}
