/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strword.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:32:12 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/08 09:33:05 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_tool.h>
#include <sys/_types/_null.h>

char	*ft_strword(char *str)
{
	char	*temp;

	temp = str;
	while (ft_isalpha(*temp) || ft_isdigit(*temp) || *temp == '_')
		temp++;
	if (temp - str)
		return (ft_strncpy(str, temp - str));
	return (ft_strdup(""));
}
