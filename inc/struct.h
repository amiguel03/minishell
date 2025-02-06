#ifndef STRUCT_H
# define STRUCT_H

# include "../minishell.h"

// 〖─◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇│◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇─〗
//                                    〘STRUCT〙
typedef struct s_files
{
	int			error;
	char		**order;
	char		**f_order;
}				t_files;

typedef struct s_env
{
	int			env_amount;
	char		*path;
	char		**env;
}				t_env;

typedef struct s_names
{
	int		fd;
	int		fd_tmp;
	int		fd_infile;
	int		fd_outfile;

}			t_names;

typedef struct s_type
{
	int			infile;
	int			append;
	int			outfile;
	int			here_doc;
	char		*in;
	char		*out;
}				t_type;

typedef struct s_red
{
	int			si_ri;
	int			si_le;
	int			do_ri;
	int			do_le;
	int			number;
	int			red_error;
	char		*error;
}				t_red;

typedef struct s_flags
{
	int			pipe;
	int			quote;
	int			dollar;
	int			expander;
	int			locate_red;
	t_red		*redirect;
}				t_flags;

typedef struct s_cmd
{
	int				exit;
	int				size;
	int				error;
	int				built;
	int				args_amount;
	char			*cmd;
	char			**tmp;
	char			**args;
	char			**quote_args;
	t_type			*type;
	t_files			*files;
	t_names			*names;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_mini
{
	int			tty;
	int			pwd;
	int			path;
	int			error;
	int			index;
	int			oldpwd;
	int			fd_tmp;
	int			single;
	int			here_doc;
	int			num_comm;
	int			fd_pipe[2];
	int			fd_history;
	int			shell_level;
	int			here_doc_index;
	char		*input;
	char		**join;
	char		**files;
	double		qpr_error;
	pid_t		*proc;
	t_env		*env;
	t_cmd		*cmd;
	t_flags		*flags;
}				t_mini;

#endif