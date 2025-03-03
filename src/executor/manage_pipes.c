#include "../../executor.h"

void	initialize_pipes(int **fds, int num_cmds, t_global *goblal)
{
	int i;

	i = -1;
	while(++i < num_cmds -1)
	{
		if (pipe(fds[i])<0)
		{
			perror("pipe");
			global->exit_code = EXIT_FAILURE;
			exit(global->exit_code);
		}
	}
}

