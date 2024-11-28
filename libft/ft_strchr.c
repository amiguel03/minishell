/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:26:03 by sergio            #+#    #+#             */
/*   Updated: 2024/06/21 17:24:33 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int value)
{
	while (*str)
	{
		if (*str == (char)value)
			return ((char *)str);
		str++;
	}
	if (*str == (char)value)
		return ((char *)str);
	return (NULL);
}
