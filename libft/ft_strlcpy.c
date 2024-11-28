/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:09:26 by sergio            #+#    #+#             */
/*   Updated: 2024/07/01 12:46:22 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	i = -1;
	src_len = ft_strlen(src);
	if (dstsize > 0)
	{
		while (++i < dstsize - 1 && src[i])
			dst[i] = src[i];
		dst[i] = '\0';
	}
	return (src_len);
}
