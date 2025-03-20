#include "minishell.h"

int	check_or(t_count *count_tmp, t_global *global, t_cmds *curr_cmd,
		t_token *type_tmp)
{
	if (count_tmp->nbr_ors > 0 && *type_tmp == OR)
	{
		count_tmp->nbr_ors--;
		ft_or(global, curr_cmd, curr_cmd->next);
		if (global->exit_code == 0)
			return (1);
		if (curr_cmd->next)
		{
			curr_cmd = curr_cmd->next;
			type_tmp++;
			while (*type_tmp != OR && *type_tmp != END)
				type_tmp++;
			if (*type_tmp == END)
				return (1);
		}
		return (1);
	}
	return (0);
}

int	check_and(t_count *count_tmp, t_global *global, t_cmds curr_cmd,
		t_token *type_tmp)
{
	if (count_tmp->nbr_ands > 0 && *type_tmp == AND)
	{
		count_tmp->nbr_ands--;
		ft_and(global, curr_cmd, curr_cmd->next);
		if (curr_cmd->next)
		{
			curr_cmd = curr_cmd->next;
			type_tmp++;
			while (*type_tmp != AND && *type_tmp != END)
				type_tmp++;
			if (*type_tmp == END)
				return (1);
		}
		return (1);
	}
	return (0);
}

int	check_semicolon_pipe(t_count *count_tmp, t_global *global, t_cmds *curr_cmd,
		t_token *type_tmp)
{
	if (*type_tmp == SEMICOLON || *type_tmp == PIPE)
	{
		if (*type_tmp == SEMICOLON)
			ft_semicolon(global, curr_cmd, curr_cmd->next);
		else
			ft_pipe(global, curr_cmd, curr_cmd->next);
		if (curr_cmd->next)
		{
			curr_cmd = curr_cmd->next;
			type_tmp++;
			while (*type_tmp != *type_tmp && *type_tmp != END)
				type_tmp++;
			if (*type_tmp == END)
				return (1);
		}
		return (1);
	}
	return (0);
}

int	check_special(t_count *count_tmp, t_global *global, t_cmds *curr_cmd,
		t_token *type_tmp)
{
	if (*type_tmp == INPUT || *type_tmp == HEREDOC || *type_tmp == APPEND
		|| *type_tmp == OUTPUT)
	{
		if (count_tmp->nbr_inputs > 0 && *type_tmp == INPUT)
			count_tmp->nbr_inputs--;
		else if (count_tmp->nbr_heredocs > 0 && *type_tmp == HEREDOC)
			count_tmp->nbr_heredocs--;
		else if (count_tmp->nbr_appends > 0 && *type_tmp == APPEND)
			count_tmp->nbr_appends--;
		else if (count_tmp->nbr_outputs > 0 && *type_tmp == OUTPUT)
			count_tmp->nbr_outputs--;
		ft_redir(global, curr_cmd);
		return (1);
	}
	return (0);
}

int check_