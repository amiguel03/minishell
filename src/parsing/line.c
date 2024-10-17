/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:28:57 by amiguel-          #+#    #+#             */
/*   Updated: 2024/10/10 12:05:13 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*space_alloc(char *line)
{
	char	*new;
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (line[i])
	{
		if (is_sep(line, i))
			count++;
		i++;
	}
	if (!(new = malloc(sizeof(char) * (i + 2 * count + 1))))
		return (NULL);
	return (new);
}

char	*space_line(char *line)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = space_alloc(line);
	while (new &&line[i])
	{
		if (quotes(line, i) != 2 && line[i] == '$' && i && line[i - 1] != '\\')
			new[j++] = (char)(-line[i++]);
		else if (quotes(line, i) == 0 && is_sep(line, i))
		{
			new[j++] = ' ';
			new[j++] = line[i++];
			if (quotes(line, i) == 0 && line[i] == '>')
				new[j++] = line[i++];
			new[j++] = ' ';
		}
		else
			new[j++] = line[i++];
	}
	new[j] = '\0';
	ft_memdel(line);
	return (new);
}

int	quote_check(t_mini *mini, char **line)
{
	if (quotes(*line, 2147483647))
	{
		ft_putendl_fd("SYNTAX ERROR OPEN QUOTES", STDERR);
		ft_memdel(*line);
		mini->ret = 2;
		mini->start = NULL;
		return (1);
	}
	return (0);
}
