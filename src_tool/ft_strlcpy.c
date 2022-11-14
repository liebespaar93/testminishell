/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:18:09 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/13 10:11:53 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/_types/_size_t.h>
#include <ft_tool.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned char	*dptr;
	unsigned char	*sptr;
	size_t			count;

	dptr = (unsigned char *)dst;
	sptr = (unsigned char *)src;
	if (src == (void *)0)
		*sptr = '\0';
	count = ft_strlen((const char *)sptr);
	if (dstsize == 0)
		return (count);
	while (*sptr != '\0' && dstsize-- > 1)
		*dptr++ = *sptr++;
	if (*dptr != '\0')
		*dptr = '\0';
	return (count);
}
