#ifdef TEST

#include "unity.h"
#include "exec.h"
#include <string.h>

#define PROG "./pipex"
#define FILE1 "inFile"
#define CMD1 "cat"
#define CMD1ARGS "-A"
#define CMD2 "wc"
#define CMD2ARGS "-l -m -c"
#define FILE2 "outFile"

int argc = 5;
char **argv;
char **envp;

void setUp(void)
{
	argv = (char**)calloc(argc + 1, sizeof(char*));
	argv[0] = strdup(PROG);
	argv[1] = strdup(FILE1);
	argv[2] = strdup(CMD1 " " CMD1ARGS);
	argv[3] = strdup(CMD2 " " CMD2ARGS);
	argv[4] = strdup(FILE2);
	argv[5] = NULL;

	envp = (char**)calloc(argc + 1, sizeof(char*));
	envp[0] = strdup("envp0");
	envp[1] = strdup("envp1");
	envp[2] = strdup("PATH=/mnt/nfs/homes/amaroni/.brew/bin:/mnt/nfs/homes/amaroni/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin");
	envp[3] = strdup("envp3");
	envp[4] = strdup("envp4");
	envp[5] = NULL;
}

void tearDown(void)
{
	for (int i = 0; i < argc ; i++)
	{
		free(argv[i]);
		free(envp[i]);
	}
	free(argv);
	free(envp);
}

#endif // TEST
