#ifndef ERROR_H
# define ERROR_H
# include "../minishell.h"

// 〖─◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇│◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇──◇─〗
//                                     〘LEXER〙

// error.c
void	errmsg(char *errmsg, char *detail, int quotes);
void	free_ptr(void *ptr);

// ft_str_utils.c
void	ft_strstr_free(char **str);
int	ft_strstr_len(char **str);
int	ft_strnstrstr(char **str, char *locate);
char	**ft_strstr_dup(char **str);
char	**ft_strstr_join(char **str, char **str1);

//ft_str_utils2.c
int	ft_locate_next_quote(int i, char *input, char quote);
char	*ft_strchr_mod(char *str, int value, int stop);
char	**ft_sindub_join(char **str, char *str1);
int		ft_strlen_dup(char *argv);

#endif