/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:36:48 by kyoulee           #+#    #+#             */
/*   Updated: 2022/10/25 22:28:20 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_global.h>
#include <stdlib.h>
#include <ft_tool.h>
#include <ft_export_tool.h>
#include <ft_env_tool.h>

int	ft_export_set(char *name)
{
	const char **export;
	char *new_name;
	int len;
	int i;
	
	if (ft_export_find(name))
		return (0);
	len = ft_void_len((void **)global.export_ptr);
	export = (const char **)malloc(sizeof(char *) * (len + 2));
	if (!export)
		return (-1);
	i = 0;
	while (i < len)
	{
		export[i] = global.export_ptr[i];
		i++;
	}
	if (ft_strchr(name, '='))
	{
		new_name = ft_strncpy(name, ft_strchr(name, '=') - name);
		ft_putenv(ft_strdup(name));
	}
	else
		new_name = ft_strdup(name);
	export[i++] = new_name;
	export[i] = NULL;
	free(global.export_ptr);
	global.export_ptr = export;

	return (0);
}

