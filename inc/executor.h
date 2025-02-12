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



#endif