/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:03:09 by amiguel-          #+#    #+#             */
/*   Updated: 2024/10/09 15:42:44 by amiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <limits.h>
# include <errno.h>
# include <signal.h>

# define EMPTY 0
# define CMD 1
# define ARG 2
# define TRUNC 3
# define APPEND 4
# define INPUT 5
# define PIPE 6
# define END 7

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define ERROR 1
# define SUCCESS 0

#define SKIP 1
#define NOSKIP 0

typedef struct	s_token
{
	char			*str;
	int				type;
	struct s_token	*prev;
	struct s_token	*next;
}				t_token;

typedef struct	s_env
{
	char			*value;
	struct s_env	*next;
}				t_env;

typedef struct	s_mini
{
	t_token			*start;
	t_env			*env;
	t_env			*secret_env;
	int				in;
	int				out;
	int				fdin;
	int				fdout;
	int				pipin;
	int				pipout;
	int				pid;
	int				charge;
	int				parent;
	int				last;
	int				ret;
	int				exit;
	int				no_exec;
}				t_mini;

/*
TOOLS QUOTES
*/
int	count_backslashes(char *line, int index);
int	quotes(char *line, int index);
int	is_sep(char *line, int i);
int	ignore_sep(char *line, int i);
/*
TOOLS TOKEN
*/
t_token	*next_sep(t_token *token, int skip);
t_token	*prev_sep(t_token *token, int skip);
t_token	*next_run(t_token *token, int skip);
/*
TOOLS TYPE
*/
int	is_type(t_token *token, int type);
int	is_types(t_token *token, char *types);
int	has_type(t_token *token, int type);
int	has_pipe(t_token *token);
/*
SRC TOKENS
*/
void	type_arg(t_token *token, int separator);
void	squish_args(t_mini *mini);
int	next_alloc(char *line, int *i);
t_token	*next_token(char *line, int *i);
t_token	*get_tokens(char *line);
	

#endif