/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:35:30 by amiguel-          #+#    #+#             */
/*   Updated: 2024/10/09 12:15:15 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_type(t_token *token, int type)
{
	if	(token && token->type == type)
		return (1);
	else
		return (0);
}

int	is_types(t_token *token, char *types)
{
	if (ft_strchr(types, ' ') && is_type(token, EMPTY))
		return (1);
	else if (ft_strchr(types, 'X') && is_type(token, CMD))
		return (1);
	else if (ft_strchr(types, 'x') && is_type(token, ARG))
		return (1);
	else if (ft_strchr(types, 'T') && is_type(token, TRUNC))
		return (1);
	else if (ft_strchr(types, 'A') && is_type(token, APPEND))
		return (1);
	else if (ft_strchr(types, 'I') && is_type(token, INPUT))
		return (1);
	else if (ft_strchr(types, 'P') && is_type(token, PIPE))
		return (1);
	else if (ft_strchr(types, 'E') && is_type(token, END))
		return (1);
	return (0);
}

int	has_type(t_token *token, int type)
{
	while (token)
	{
		if (is_type(token, type))
			return (1);
		token = token->next;
	}
	return (0);
}

int	has_pipe(t_token *token)
{
	while (token && is_type(token, END) == 0)
	{
		if (is_type(token, PIPE))
			return (1);
		token = token->next;
	}
	return (0);
}

