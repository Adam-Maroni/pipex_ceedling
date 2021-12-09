#include <stdio.h>
#include <unistd.h>


int main(int argc, char **argv, char **envp)
{
	int pipefds[2];
	int returnstatus;
	int pid;

	char writemsg[2][20] = {"Hi", "hello"};
	char readmsg[20];

	returnstatus = pipe(pipefds);
	if(returnstatus == -1)
	{
		printf("Unable to create pipe\n");
		return (1);
	}
	pid = fork();
	if(pid == 0)
	{
		read(pipefds[0], readmsg, sizeof(readmsg));
		printf("PID = %d\n", getpid());
		printf("Child process reading from pipe %s\n", readmsg);
	}
	else
	{
		printf("PID = %d\n", getpid());
		printf("Parent process writing to pipe %s\n", writemsg[1]);
		write(pipefds[1], writemsg[1], sizeof(writemsg[1]));
	}
	return (0);
}
