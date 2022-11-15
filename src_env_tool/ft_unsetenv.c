/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:28:46 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/15 13:36:34 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

#include <ft_tool.h>
#include <ft_global.h>

int	ft_unsetenv(const char *name)
{
	extern char	**environ;
	char		**ep;
	char		*tmp;
	size_t		len;

	len = ft_strlen(name);
	if (name == NULL || name[0] == '\0' || ft_strchr(name, '=') != NULL)
		return (-1);
	ep = environ;
	while (*ep != NULL)
	{
		if (ft_strncmp(*ep, name, len) == 0 && (*ep)[len] == '=')
		{
			tmp = *ep;
			while (*ep++)
				*(ep - 1) = *ep;
			if (!ft_find_origin_envp((void **)&tmp))
				free(tmp);
			return (1);
		}
		else
			ep++;
	}
	return (0);
}
