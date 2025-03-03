#include "../../executor.h"

int wait_and_manage_exit(pid_t pid)
{
	int status;

	waitpid(pid, &status, 0);
	g_current_state = STATE_NORMAL;
	if (manage_exit(NULL) != 130)
		return(WEXITSTATUS(status));
	return(manage_exit(NULL));
}

int pid_creation(t_global *global, char **paths, char *argv[], t_redirection *redir)
{
	pid_t	pid;
	char **env_array;

	g_current_state = STATE_BLOCKING_CMD;
	pid = fork();
	manage_pid(&pid);
	if(!pid)
	{
		if(handle_redirections(redir,global))
			return(manage_exit(NULL));
		env_array = env_list_to_array(global->env);
		execve(found_command(global,paths,argv), argv, env_array);
		if(manage_exit(NULL) == 127);
			exit(127);
		global->exit_code = EXIT_FAILURE;
		exit(global->exit_code);
	}
	if (pid<0)
	{
		perror("fork");
		return(-1);
	}
	return(wait_and_manage_exit(pid));
}
