#include "../../inc/executor.h"

static void ft_initialize_selection(t_cmd *current)
{
	int i;

	i = -1;
	current->size = 0;
	current->error = 0;
	while (current->args[++i])
	{
		if(ft_type(current->args[i]) != 0)
			current->size++;
	}
}

static char **ft_allocate_tmp(t_cmd *current)
{
	char	**tmp;
	int	arg_len;

	arg_len = ft_strstr_len(current->args);
	tmp = ft_calloc(sizeof(char*),
					(size_t)(arg_len - (current->size * 2)) + 1);
	if (tmp == NULL)
		return(NULL);
	return (tmp);
}

static void ft_process_command(t_cmd *current, t_mini *mini, int i)
{
	current->cmd = ft_builtins(current, current->args[i]);
	if (current->cmd == NULL)
		current->cmd = ft_route_cmd(mini, current, current->args[i]);
	if (current->cmd == NULL && current->error != -2)
		current->files->error = -3;
}

static void ft_process_argument(t_cmd *cmd, char ***tmp, int *j, int i)
{
	int max_args;

	max_args = (int)ft_strstr_len(cmd->args) - (cmd->size * 2);
	if (cmd->files->error != -2 && *j <max_args)
	{
		(*tmp)[*j] = ft_strdup(cmd->args[i]);
		if ((*tmp)[(*j)++] == NULL)
			cmd->files->error = -1;
	}
}

void	ft_select_cmd(t_cmd *current, t_mini *mini, int j)
{
	char **tmp;
	int	i;

	i = -1;
	ft_initialize_selection(current);
	tmp = ft_allocate_tmp(current);
	while (current->args[++i])
	{
		current->error = 0;
		if (ft_type(current->args[i]) != 0 && current->args[i + 1] != NULL)
			i++;
		else if(ft_nothing(current->args[i], 0) == 0)
		{
			if (j == 0)
				ft_process_command(current, mini, i);
			ft_process_argument(current, &tmp, &j, i);
		}
	}
	ft_strstr_free(current->args);
	current->args = tmp;
}
