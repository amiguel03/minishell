#include "../../inc/utils.h"

int	ft_locate_next_quote(int i, char *input, char quote)
{
	while (input && input[i] && input[i] != quote)
		i++;
	return (i);
}

char	*ft_strchr_mod(char *str, int value, int stop)
{
	char	quote;
	int		i;

	i = -1;
	quote = 0;
	while (str[++i] != '\0')
	{
		if(str[i] == '\"')
		{
			quote += 1;
			if (quote == 2)
				quote = 0;
		}
		else if (str[i] == '\'' && quote == 0)
		{
			i = ft_locate_next_quote(i + 1, str, str[i]);
			if (str[i] == '\0')
				return (NULL);
		}
		if (str && str[i] == value && stop-- == 0)
			return(str + i);
	}
	return(NULL);
}

char	**ft_sindub_join(char **str, char *str1)
{
	char	**result;
	int		len;
	int		i;

	i = -1;
	if (str == NULL)
		len = 0;
	len = ft_strstr_len(str);
	result = ft_calloc(sizeof(char *), (size_t)len + 1 + 1);
	while (++i < len)
		result[i] = ft_strdup(str[i]);
	result[i] = ft_strdup(str1);
	return(result);
}

int		ft_strlen_dup(char *argv)
{
	int	i;
	int	space;

	i = 0;
	space = 0;
	if(argv)
		while(argv[i] != '\0')
			if(argv[i++] == ' ')
				space++;
	return (i - space);
}
