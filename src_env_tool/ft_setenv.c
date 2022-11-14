/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 19:24:38 by kyoulee           #+#    #+#             */
/*   Updated: 2022/10/26 04:38:42 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <ft_tool.h>
#include <ft_global.h>
#include <ft_env_tool.h>

int	ft_setenv(const char *name, const char *value, int overwrite)
{
	char	*es;

	if (name == NULL || name[0] == '\0' || ft_strchr(name, '=') != NULL ||
			value == NULL) 
	{
		errno = EINVAL;
		return (-1);
	}
	if (getenv(name) != NULL && overwrite == 0)
		return (0);
	ft_unsetenv(name);
	es = malloc(ft_strlen(name) + ft_strlen(value) + 2);
	if (es == NULL)
		return (-1);
	ft_strcpy(es, name);
	ft_strcat(es, "=");
	ft_strcat(es, value);
	return (ft_putenv(es));
}