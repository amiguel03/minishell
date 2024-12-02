#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_files
{
	int		error;
	char	**order;
	char	**f_order;
}			t_files;

typedef	struct s_red
{
	int		si_ri;
	int		si_le;
	int		do_ri;
	int		do_le;
	int		number;
	char	*error;
}			t_red;

typedef struct s_flags
{
	int		pipe;
	int		quote;
	int		dollar;
	int		expander;
	int		locate_red;
	t_red	*error;
}			t_flags;

typedef struct s_cmd
{
	int		exit;
	int		size;
	int		error;
	int		built;
	int		args_count;
	char	*cmd;
	char	**tmp;
	char	**args;
	char	**quotes_args;
	t_files	*files;
	struct s_cmd	*next;
}				t_cmd;

typedef	struct	s_mini
{
	int		tty;
	int		pwd;
	int		path;
	int		error;
	int		index;
	int		oldpwd;
	int		fd_tmp;
	int		single;
	int		here_doc;
	int		num_cmd;
	int		fd_pipe[2];
	int		fd_history;
	int		shell_level;
	int		here_doc_index;
	char	*input;
	char	**join;
	char	**files;
	double	qpr_error;
	pid_t	*proc;
	t_flags	*flags;
}				t_mini;

#endif