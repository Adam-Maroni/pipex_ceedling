#ifdef TEST

#include "unity.h"
#include <string.h>
#include "init.h"
TEST_FILE("../src/extract.c")

int argc = 5;
char **argv;
char **envp;

void setUp(void)
{
	argv = (char**)calloc(argc + 1, sizeof(char*));
	argv[0] = strdup("./pipex");
	argv[1] = strdup("inFile");
	argv[2] = strdup("ls -l");
	argv[3] = strdup("wc -l -m -c");
	argv[4] = strdup("outFile");
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

void test_init_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement init");
}

#endif // TEST
