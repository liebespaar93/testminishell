/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:19:18 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/15 13:24:11 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <ft_global.h>
#include <ft_export_tool.h>
#include <ft_tool.h>

void	ft_global_init(const char **envp)
{
	char	**tmp;
	int		i;

	g_global.export_ptr = ft_export_init(envp);
	g_global.origin_envp = \
		malloc(sizeof(char *) * (ft_void_len((void **)envp) + 1));
	if (!g_global.origin_envp)
		return ;
	tmp = (char **)envp;
	i = 0;
	while (*tmp)
		g_global.origin_envp[i++] = *tmp++;
	g_global.origin_envp[i] = NULL;
}

int	ft_find_origin_envp(void **ptr)
{
	char	**tmp;

	tmp = (char **)g_global.origin_envp;
	while (*tmp)
	{
		if (*tmp == *ptr)
			return (1);
		tmp++;
	}
	return (0);
}
