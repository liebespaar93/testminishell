/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transrate_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 07:19:47 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/14 09:44:51 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/syslimits.h>

#include <ft_tool.h>

char	*ft_transrate_sigle_quote(char *new, char *str)
{
	char	*temp;

	temp = ft_strchr(str + 1, '\'');
	ft_strncat(new, str + 1, temp - str - 1);
	return (temp + 1);
}

char	*ft_transrate_double_quote(char *new, char *str)
{
	char	*temp;
	char	*word;
	int		word_len;
	int		index;

	temp = str + 1;
	index = ft_strlen(new);
	while (*temp != '\"')
	{
		if (*temp == '$')
		{
			word = ft_strword(temp + 1);
			word_len = ft_strlen(word);
			temp += word_len + 1;
			index += word_len;
			ft_strcat(new, getenv(word));
			free(word);
		}
		else
			new[index++] = *temp++;
	}
	return (temp + 1);
}

char	*ft_transrate_doller(char *new, char *str)
{
	char	*temp;
	char	*word;

	temp = str;
	word = ft_strword(temp + 1);
	temp += ft_strlen(word) + 1;
	ft_strcat(new, getenv(word));
	free(word);
	return (temp);
}

char	*ft_transrate_env(char *str)
{
	char	new[ARG_MAX];
	char	*temp;
	int		index;

	ft_bzero(new, sizeof(char [ARG_MAX]));
	temp = str;
	while (*temp)
	{
		if (*temp == '\'')
			temp = ft_transrate_sigle_quote(new, temp);
		else if (*temp == '\"')
			temp = ft_transrate_double_quote(new, temp);
		else if (*temp == '$')
			temp = ft_transrate_doller(new, temp);
		else
		{
			index = ft_strlen(new);
			while (*temp && !ft_strchr("\'\"$", *temp))
				new[index++] = *temp++;
		}
	}
	return (ft_strdup(new));
}
