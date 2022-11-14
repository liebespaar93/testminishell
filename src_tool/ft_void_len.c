/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:20:54 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/13 10:11:22 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/_types/_null.h>
#include <sys/_types/_size_t.h>

size_t	ft_void_len(void *ptr[])
{
	void		**temp;
	size_t		len;

	len = 0;
	temp = ptr;
	while (temp[len] != NULL)
		len++;
	return (len);
}
