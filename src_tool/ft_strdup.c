/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:16:51 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/13 10:10:46 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_tool.h>

char	*ft_strdup(const char *s1)
{
	char	*strdup_ptr;
	size_t	s1_len;

	strdup_ptr = (char *)s1;
	if (s1 == (void *)0)
		s1 = "\0";
	s1_len = ft_strlen(s1);
	strdup_ptr = (char *)malloc(1 * (s1_len + 1));
	if (strdup_ptr == NULL)
		return (NULL);
	while (*s1 != '\0')
		*strdup_ptr++ = *s1++;
	*strdup_ptr = '\0';
	return (strdup_ptr - s1_len);
}
