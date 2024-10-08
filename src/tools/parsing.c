/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:45:44 by amiguel-          #+#    #+#             */
/*   Updated: 2024/10/08 11:58:42 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// \\" Tiene que quedar las comillas abiertas
// \" NO tiene que salir error de comillas
// \$ \" \\ 

int	count_backslashes(char *line, int index)
{
	int	count;

	count = 0;
	while (index > 0 && line[index - 1] == '\\')
	{
		count++;
		index--;
	}
	return (count);
}

int	quotes(char *line, int index)
{
	int	i;
	int	open;

	i = 0;
	open = 0;
	while (line[i] && i != index)
	{
		if (count_backslashes(line, i) % 2 == 0)
			// Verifica si la comilla esta escapada
		{
			if (open == 0 && line[i] == '\"')
				open = 1;
			else if (open == 0 && line[i] == '\'')
				open = 2;
			else if (open == 1 && line[i] == '\"')
				open = 0;
			else if (open == 2 && line[i] == '\'')
				open = 0;
		}
		i++;
	}
	return (open);
}

int	is_sep(char *line, int i)
{
	if (count_backslashes(line, i) % 2 == 0 && ft_strchr("<>|;", line[i])
		&& quotes(line, i) == 0)
		return (1);
	return (0);
}
