#include "minishell.h"

void	ft_redir(t_global *global, t_cmds *curr_cmd)
{
	execute_cmd(curr_cmd->cmd, curr_cmd->redir, global);
}

void	ft_or(t_global *global, t_cmds *curr_cmd, t_cmds *next_cmd)
{
	if (execute_cmd(curr_cmd->cmd, curr_cmd->redir, global) != 0)
		execute_cmd(next_cmd->cmd, next_cmd->redir, global);
}

void	ft_and(t_global *global, t_cmds *curr_cmd, t_cmds *next_cmd)
{
	if (execute_cmd(curr_cmd->cmd, curr_cmd->redir, global) == 0)
		execute_cmd(next_cmd->cmd, next_cmd->redir, global);
}

void	ft_semicolon(t_global *global, t_cmds *curr_cmd, t_cmds *next_cmd)
{
	execute_cmd(curr_cmd->cmd, curr_cmd->redir, global);
	execute_cmd(next_cmd->cmd, next_cmd->redir, global);
}