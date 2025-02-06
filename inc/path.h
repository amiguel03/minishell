#ifndef PATH_H
# define PATH_H
# include "../minishell.h"

// 〖─◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇│◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇─〗
//                                    〘PATH〙

// path_handling.c
char **ft_create_path(char **env);
static char	*ft_father(int *fd, char *search);
static void	ft_pid_0(int *fd, char *path, char **file, char **env);
char	*ft_execute(char **env, char **file, char *path, char *search);
char	**ft_save_path(char	**env);



#endif