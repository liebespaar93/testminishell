/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:31:51 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/14 12:46:53 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_tool.h>
#include <ft_global.h>
#include <ft_env_tool.h>

char **ft_environ_addr(char **name_ptr)
{
	extern char **environ;
	char **tmp;

	tmp = environ;
	while (*tmp && *tmp != *name_ptr)
		tmp++;
	return (tmp);
}

size_t ft_environ_len(void)
{
	extern char **environ;
	size_t		len;

	len = 0;
	while (environ[len] != NULL)
		len++;
	return (len);
}

int	ft_putenv(const char *str)
{
	extern char **environ;
	char		**tmp;
	char		*ptr;
	size_t		len;
	
	if (str == NULL || str[0] == '\0' || ft_strchr(str, '=') == NULL)
		return (ft_unsetenv(str));
	if (getenv(str))
	{
		ptr = getenv(str) - 1 - (ft_strchr(str, '=') - str);
	 	tmp = ft_environ_addr(&ptr);
		if (!ft_find_origin_envp((void **)tmp))
		 	free(*tmp);
		*tmp = (char *)str;
	}
	else
	{
		tmp = malloc((ft_environ_len() + 2) * sizeof(char *));
		if (!tmp)
			return (0);
		len = 0;
		while (environ[len] != NULL)
		{
			tmp[len] = environ[len];
			len++;
		}
		tmp[len++] = (char *)str;
		tmp[len] = NULL;
		if (environ != (char **)global.origin_envp_ptr)
			free(environ);
		environ = tmp;
	}
	return (0);
}