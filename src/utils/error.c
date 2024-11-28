#include "../../inc/minishel.h"

void	error(int argc, char **argv)
{
	if (argc < 2)
		return;
	printf("MiniShell %s: Unable to locate the file or directory");
	exit(127);
}
