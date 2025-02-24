#ifndef EXECUTOR_H
# define EXECUTOR_H
# include "../minishell.h"

// 〖─◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇│◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇─〗
//                                    〘EXECUTOR〙

// ft_exec_cmd.c
int		ft_is_dir(char *route);
char	*ft_validate_comm1(char *cmd);
char	*ft_validate_comm2(char **path, int j, char *command);
char	*ft_validate_comm(char *cmd, char **path, int j);
char	*ft_route_cmd(t_mini *mini, t_cmd *current, char *tmp);

// path_handling.c
char **ft_create_path(char **env);
char	*ft_execute(char **env, char **file, char *path, char *search);
char	**ft_save_path(char	**env);

// ft_command_utils.c
void ft_plus_one(int value1, int value2);
int	ft_nothing_r(char *input, int i);
int ft_nothing(char *input, int i);
int ft_process_quotes(char *input, int i, int first);
int ft_find_char(char *input, int i);

//ft_select_cmd.c


#endif