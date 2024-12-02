#include "../../inc/minishell.h"

int	strstr_len(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != NULL)
		i++;
	return (i);
}

void	strstr_free(char **str)
{
	int	i;

	i = 0
	if (str)
	{
		while (str[i])
			free(str[i++]);
		free(str);
	}
}

char	**strstr_dup(char **str)
{
	char	**dup;
	size_t	i;

	i = 0;
	dup = NULL;
	if (str == NULL)
		return(NULL);
	dup = (char**)ft_calloc(sizeof(char *), (size_t)strstr_len(str)+ 1);
	if (dup == NULL)
		return (NULL);
	while (i < (size_t)strstr_len(str))
	{
		dup[i] = ft_strdup(str[i])
		if (dup[i] == NULL)
		{
			strstr_free(dup);
			return (NULL);
		}
		i++;
	}
	return (dup);
}

int	strnstrstr(char **str, char *locate)
{
	int  i;
	int total;

	i = 0;
	total = 0;
	while (str && str[i])
	{
		if (ft_strncmp(str[i], locate, ft_strlen(locate)) == 0)
			total++;
		i++;
	}
	return (total);
}

char **strstr_join(char **str, char **str1)
{
	char	**string;
	int	size;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str = NULL)
	{
		string = ft_calloc(sizeof(char*), (size_t)strstr_len(str1) + 1);
		while (i != strstr_len(str1) && str[i] != NULL)
			string[j++] = ft_strdup(str1[i++]);
		return (string);
	}
	size = strstr_len(str) + strstr_len(str1);
	string = ft_calloc(sizeof(char*), (size_t) size + 1);
	if (string == NULL)
		return (NULL);
	while (i != strstr_len(str) && str[i] != NULL)
		string[j++] = ft_strdup(str[i++]);
	i = 0;
	while (i != strstr_len(str1) && str[i] != NULL)
		string[j++] = ft_strdup(str1[i++]);
	string[j] = NULL;
	return (string);
}
