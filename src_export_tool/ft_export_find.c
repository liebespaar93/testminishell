/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:40:26 by kyoulee           #+#    #+#             */
/*   Updated: 2022/10/25 22:12:44 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_tool.h>
#include <ft_global.h>
#include <stdlib.h>

const char **ft_export_find(char *name)
{
	const char **export;
	char *find;
	
	if (ft_strchr(name, '='))
		find = ft_strncpy(name, ft_strchr(name, '=') - name);
	else
		find = ft_strdup(name);
	export = global.export_ptr;
	while (*export)
	{
		if (!ft_strcmp(*export, find))
		{
			free(find);
			return (export);
		}
		export++;
	}
	free(find);
	return (NULL);
}
