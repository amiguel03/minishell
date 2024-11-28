/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:00:29 by sergio            #+#    #+#             */
/*   Updated: 2024/11/24 16:49:16 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_min(void)
{
	char	*arr;

	arr = (char *)ft_calloc(12, 1);
	if (arr == NULL)
		return (NULL);
	ft_strlcpy(arr, "-2147483648", 12);
	return (arr);
}

char	*ft_ifzero(void)
{
	char	*arr;

	arr = (char *)ft_calloc(2, 1);
	if (arr == NULL)
		return (NULL);
	ft_strlcpy(arr, "0", 2);
	return (arr);
}

char	*ft_memory(int len, int sign, int n)
{
	char	*arr;
	char	*ptr;

	arr = (char *)ft_calloc((size_t)len + 1, 1);
	if (arr == NULL)
		return (NULL);
	ptr = arr + len;
	*ptr-- = '\0';
	while (n > 0)
	{
		*ptr-- = (n % 10) + '0';
		n /= 10;
	}
	if (sign == -1)
		*ptr = '-';
	ptr++;
	return (arr);
}

char	*ft_itoa(long n)
{
	int	sign;
	int	len;
	int	temp;

	sign = 1;
	len = 0;
	if (n < 0)
	{
		sign = -1;
		n = -n;
		len++;
		if (n == -2147483648)
			return (ft_min());
	}
	if (n == 0)
		return (ft_ifzero());
	temp = n;
	while (temp++ > 0)
	{
		temp /= 10;
		len++;
	}
	return (ft_memory(len, sign, n));
}
