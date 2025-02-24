#include "../../inc/files.h"

int  ft_type(char *argv)
{
	if (argv == NULL)
		return (0);
	if (ft_strnstr(argv, "<", 1) && (int)ft_strlen_dup(argv) == 1)
		return(1);
	if (ft_strnstr(argv, ">", 1) && (int)ft_strlen_dup(argv) == 1)
		return(2);
	if (ft_strnstr(argv, "<<", 2) && (int)ft_strlen_dup(argv) == 2)
		return(3);
	if (ft_strnstr(argv, ">>", 2) && (int)ft_strlen_dup(argv) == 2)
		return(4);
	return(0);
}

