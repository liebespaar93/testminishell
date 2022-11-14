/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:20:56 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/13 10:10:33 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_tool.h>

int					ft_minus(int *n);
long unsigned int	ft_numlen(int n);

char	*ft_itoa(int n)
{
	char				*str;
	long unsigned int	str_len;
	int					sign;

	sign = ft_minus(&n);
	if (sign < 0)
		return ((char *)ft_strdup("-2147483648"));
	str_len = ft_numlen(n);
	str = (char *)malloc(sizeof(char) * (str_len + sign + 1));
	if (str == NULL)
		return (NULL);
	str[str_len + sign] = '\0';
	while (str_len-- > 0)
	{
		str[str_len + sign] = '0' + n % 10;
		n /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

int	ft_minus(int *n)
{
	if (*n < 0)
	{
		if (*n <= -2147483648)
			return (-1);
		*n *= -1;
		return (1);
	}
	return (0);
}

long unsigned int	ft_numlen(int n)
{
	long unsigned int	n_len;

	n_len = 0;
	while (n)
	{
		n /= 10;
		n_len++;
	}
	if (!n_len)
		return (1);
	return (n_len);
}
