/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:50:48 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/19 21:02:59 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_tool.h>

char	*ft_file_name(char **str)
{
	char	*word;
	char	*temp;
	char	*file_name;

	temp = *str;
	while (*temp && ft_strchr(WHITE_SPACE, *temp))
		temp++;
	word = temp;
	if (*word)
		while (*temp && !ft_strchr(WHITE_SPACE, *temp))
			temp++;
	file_name = ft_strncpy(word, temp - word);
	*str = temp;
	return (file_name);
}
