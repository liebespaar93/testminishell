/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:31:51 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/16 15:15:50 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <ft_tool.h>
#include <ft_global.h>
#include <ft_env_tool.h>

char	**ft_environ_addr(char **name_ptr)
{
	extern char	**environ;
	char		**tmp;

	tmp = environ;
	while (*tmp && *tmp != *name_ptr)
		tmp++;
	return (tmp);
}

void	ft_environ_cpy(char **dst)
{
	extern char	**environ;
	int			i;

	i = 0;
	if (!dst || !environ)
		return ;
	while (environ[i] != NULL)
	{
		dst[i] = environ[i];
		i++;
	}
}

void	ft_put_env_norm(const char *str)
{
	char		**tmp;
	char		*ptr;

	ptr = getenv(str) - 1 - (ft_strchr(str, '=') - str);
	tmp = ft_environ_addr(&ptr);
	if (!ft_find_origin_envp((void **)tmp))
		free(*tmp);
	*tmp = (char *)str;
}

int	ft_putenv(const char *str)
{
	extern char	**environ;
	char		**tmp;
	int			len;

	if (str == NULL || str[0] == '\0' || ft_strchr(str, '=') == NULL)
		return (ft_unsetenv(str));
	if (getenv(str))
		ft_put_env_norm(str);
	else
	{
		len = ft_void_len((void **)environ);
		tmp = (char **)malloc((len + 2) * sizeof(char *));
		if (!tmp)
			return (0);
		ft_environ_cpy(tmp);
		tmp[len] = (char *)str;
		tmp[len + 1] = NULL;
		if (environ != (char **)g_global.origin_envp_ptr)
			free(environ);
		environ = tmp;
	}
	return (0);
}
