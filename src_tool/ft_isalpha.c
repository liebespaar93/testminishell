/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:43:18 by kyoulee           #+#    #+#             */
/*   Updated: 2022/10/24 13:43:21 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (0x41 <= c && c <= 0x5a)
		return (1);
	else if (0x61 <= c && c <= 0x7a)
		return (2);
	return (0);
}