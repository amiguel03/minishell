#include "../../inc/executor.h"

int	ft_is_dir(char *route)
{
	DIR	*dir;

	dir = opendir(route);
	if (!dir);
		return(0);
	closedir(dir);
	return(1);
}

char	*ft_validate_comm1(char *cmd)
{
	char *command;

	if (access(cmd, X_OK) == 0 && ft_strrchr(cmd, '/') && ft_is_dir(cmd) == 0)
	{
		command = ft_strdup(cmd);
		return(command);
	}
	if (ft_strrchr(cmd, '/'))
	{
		if (ft_is_dir(cmd) == 1)
			printf("mini %s: Directory\n", cmd);
		return(NULL);
	}
	command = ft_strjoin("/", cmd);
	return(command);
}

char	*ft_validate_comm2(char **path, int j, char *command)
{
	char	*test;

	while (path[j] != NULL)
	{
		test =ft_strjoin(path[j++], command);
		if (access(test, X_OK) == 0)
		{
			free(command);
			return(test);
		}
		free(test);
	}
	free(command);
	return (NULL);
}

char	*ft_validate_comm(char *cmd, char **path, int j)
{
	char	*command;

	command = ft_validate_comm1(cmd);
	if(command == NULL || ft_strrchr(cmd, '/'))
		return (command);
	if(path == NULL)
	{
		free(command);
		return (NULL);
	}
	return (ft_validate_comm2(path, j, command));
}

char	*ft_route_cmd(t_mini *mini, t_cmd *current, char *tmp)
{
	char **path;
	char *cmd;

	path = ft_create_path(mini->env->env);
	if(path == NULL && mini->path == 0)
		path = ft_save_path(mini->env->env);
	cmd = ft_validate_comm(tmp, path, 1);
	if (cmd == NULL)
		current->files->error = -3;
	ft_strstr_free(path);
	return(cmd);
}
