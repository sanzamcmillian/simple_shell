#include "shell.h"

void init_shell()
{
	clear();

	char* username = getenv("USER");
	printf("@%s", username);
	printf("\n");
}
