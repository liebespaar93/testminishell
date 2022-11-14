/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:20:35 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/13 10:10:42 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_overflow(long sign);

int	ft_atoi(const char *str)
{
	int		num;
	long	sign;

	num = 0;
	sign = 1;
	while ((0x09 <= *str && *str <= 0x0d) || *str == 0x20)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (0x30 <= *str && *str <= 0x39)
	{
		if (num > num * 10)
			return (ft_atoi_overflow(sign));
		num = num * 10 + (*str - 0x30);
		str++;
	}
	return ((int)(num * sign));
}

int	ft_atoi_overflow(long sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}
