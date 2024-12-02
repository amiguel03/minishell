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
	
}