/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:28:46 by kyoulee           #+#    #+#             */
/*   Updated: 2022/10/25 22:34:05 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include <ft_tool.h>
#include <ft_global.h>

int	ft_unsetenv(const char *name)
{
	extern char **environ;
	char		**ep;
	char		**sp;
	char		*tmp;
	size_t		len;

	len = ft_strlen(name);
	if (name == NULL || name[0] == '\0' || ft_strchr(name, '=') != NULL)
	{
		errno = EINVAL;
		return (-1);
	}
	ep = environ;
	while (*ep != NULL)
	{
		if (ft_strncmp(*ep, name, len) == 0 && (*ep)[len] == '=') 
		{
			sp = ep;
			tmp = *ep;
			while (*sp != NULL)
			{
				*sp = *(sp + 1);
				sp++;
			}
			if (!ft_find_origin_envp((void **)&tmp))
				free(tmp);
			return (1);
		}
		else
			ep++;
	}
	return (0);
}