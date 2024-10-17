/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:26:53 by amiguel-          #+#    #+#             */
/*   Updated: 2024/10/14 11:03:13 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	last_valid_arg(t_token *token)
{
	t_token	*prev;

	if (!token || is_type(token, CMD) || is_type(token, ARG))
	{
		prev = prev_sep(token, NOSKIP);
		if (!prev || is_type(prev, END) || is_type(prev, END))
			return (1);
		return (0);
	}
	else
		return (0);
}

int	check_line(t_mini *mini, t_token *token)
{
	while (token)
	{
		if (is_type(token, "TAI") && (!token->next || is_type(token->next,
					"TAIPE")))
		{
			ft_putstr_fd("bash: syyntax error unpredicted token", STDERR);
			token->next ? ft_putstr_fd(token->next->str, STDERR) : 0;
			token->next ? 0 : ft_putstr_fd("newline", STDERR);
			ft_putendl_fd("'", STDERR);
			mini->ret = 258;
			return (0);
		}
		if (is_types(token, "PE") && (!token->prev || !token->next
				|| is_types(token->prev, "TAIPE")))
		{
			ft_putstr_fd("bash: syntax error unpredcited token `", STDERR);
			ft_putstr_fd(token->str, STDERR);
			ft_putendl_fd("'", STDERR);
			mini->ret = 258;
			return (0);
		}
		token = token->next;
	}
	return (1);
}
