#include "../../inc/minishell.h"

static void free_sim(void *ptr, char *str, char *str1)
{
	if (str)
		free(str);
	if(str1)
		free(str1);
	free(ptr);
}

static void free_dou(void *ptr, char **str, char **str1)
{
	if (str)
		strstr_free(str);
	if (str1)
		strstr_free(str1);
	free (ptr);
}

void	free_t_cmd(t_cmd **cmd)
{
	t_cmd	*current;
	t_cmd	*next;

	current = *cmd;
	while (current)
	{
		next = current->next;
		strstr_free(current->args);
		strstr_free(current->quote_args);
		if(current->files)
			free_dou(current->files,
				current->files->f_order, current->files->order);
		if(current->type)
			free_sim(current->type, current->type->in, current->type->out);
		if (current->names)
			free(current->names);
		free(current->cmd);
		free(current);
		current = next;
	}
	*cmd = NULL;
}

void	free_t_mini(t_mini *mini)
{
	if (mini == NULL)
		return ;
	if (mini->env != NULL)
	{
		if (mini->env->path != NULL)
			free(mini->env->path);
		if (mini->env->env != NULL)
			strstr_free(mini->env->env);
	}
	if (mini->flags)
		free(mini->flags);
	if (mini->token != NULL)
	{
		if (mini->token->input != NULL)
			free(mini->token->input);
		if (mini->token->tokens != NULL)
			strstr_free(mini->token->tokens);
		free(mini->token);
	}
	if (mini->env)
		free(mini->env);
	free(mini);
}
