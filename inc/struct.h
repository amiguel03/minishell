#ifndef STRUCT_H
# define STRUCT_H

# include "../minishell.h"

// 〖─◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇│◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇─〗
//                                    〘STRUCT〙
typedef enum s_shell_state
{
	STATE_NORMAL,
	STATE_HEREDOC,
	STATE_BLOCKING_CMD
}						t_shell_state;

// Types of tokens
typedef enum s_token
{
	WORD,
	PIPE,
	INPUT,
	OUTPUT,
	APPEND,
	HEREDOC,
	AND,
	OR,
	SEMICOLON,
	CLOSED_QUOTE,
	CLOSED_DQUOTE,
	NOT_CLOSED_QUOTE,
	NOT_CLOSED_DQUOTE,
	OPTIONS,
	STAR,
	DOLLAR,
	TILDE,
	COLON,
	IGNORE,
	BS_NEWLINE,
	BS_TAB,
	BS_VERTICAL_TAB,
	BS_BACKSPACE,
	BS_CARRIAGE_RETURN,
	BS_FORM_FEED,
	BS_BELL,
	BS_ESCAPE,
	BS_BACKSLASH,
	END
}						t_token;

// State of the parsing
typedef enum state
{
	VALID,
	QUOTE_ERROR,
	DQUOTE_ERROR,
	PIPE_ERROR,
	INPUT_ERROR,
	OUTPUT_ERROR,
	APPEND_ERROR,
	HEREDOC_ERROR,
	AND_ERROR,
	OR_ERROR,
	SEMICOLON_ERROR,
	OPTIONS_ERROR
}						t_state;

// Types of redirections
typedef enum s_redirectiontype
{
	NO_REDIRECTION,
	INPUT_REDIRECTION,
	OUTPUT_REDIRECTION,
	APPEND_REDIRECTION,
	HEREDOC_REDIRECTION
}						t_redirectiontype;

// Options for echo
typedef enum s_option
{
	NO_OPTION,
	OPTION_N,
	INVALID_OPTION
}						t_option;

// History
typedef struct s_history
{
	char				*line;
	struct s_history	*next;
}	t_history;

// Redirections and heredocs
typedef struct s_redirection
{
	t_redirectiontype	type;
	char				*filename;
	char				*limiter;
	int					type_hd;
}						t_redirection;

// Environment variables
typedef struct s_env
{
	char				*name;
	char				*value;
	struct s_env		*next;
}						t_env;

// Commands
typedef struct s_cmds
{
	char				*cmd;
	t_redirection		*redir;
	struct s_cmds		*next;
}						t_cmds;

// Count tokens
typedef struct s_count
{
	int					nbr_tokens;
	int					nbr_cmds;
	int					nbr_pipes;
	int					nbr_inputs;
	int					nbr_outputs;
	int					nbr_appends;
	int					nbr_heredocs;
	int					nbr_colons;
	int					nbr_semicolons;
	int					nbr_ands;
	int					nbr_ors;
	int					nbr_options;
	bool				special_cases;
}						t_count;

typedef struct s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

// Line
typedef struct s_line
{
	char				**token;
	t_token				*type;
	t_cmds				*cmds;
	bool				pipe;
	bool				heredoc;
	t_count				*count;
}						t_line;

// Global structure
typedef struct s_global
{
	int					exit_code;
	char				*home_folder;
	t_env				*env;
	t_line				*line;
}						t_global;

// Format structure
typedef struct s_format
{
	t_token				*new_types;
	char				**new_tokens;
	int					*token_idx;
	int					original_count;
	int					entries_count;
	int					in_double_quotes;
	int					in_simple_quotes;
	char				*output;
	int					i;
}						t_format;

#endif