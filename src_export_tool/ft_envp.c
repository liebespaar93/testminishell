/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:29:21 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/15 13:24:11 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <ft_global.h>
#include <ft_tool.h>
#include <ft_env_tool.h>

char	**ft_free_envp(char ***envp_ptr)
{
	char	**envp;

	if (!envp_ptr)
		return (NULL);
	envp = *envp_ptr;
	while (*envp)
		free(*envp++);
	free(envp);
	*envp_ptr = NULL;
	return (*envp_ptr);
}

char	**ft_envp(void)
{
	char	**envp;
	int		len;
	int		i;

	len = ft_void_len((void **)g_global.export_ptr);
	envp = (char **)malloc(sizeof(char *) * (len + 1));
	if (!envp)
		return (NULL);
	i = 0;
	while (g_global.export_ptr[i])
	{
		len = ft_strlen(g_global.export_ptr[i]) + \
			ft_strlen(getenv(g_global.export_ptr[i])) + 1;
		envp[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!envp[i])
			return (envp);
		ft_strcpy(envp[i], g_global.export_ptr[i]);
		ft_strcat(envp[i], "=");
		ft_strcat(envp[i], getenv(g_global.export_ptr[i]));
		i++;
	}
	envp[i] = NULL;
	return (envp);
}
