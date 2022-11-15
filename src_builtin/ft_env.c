/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 19:24:38 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/15 13:15:31 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <ft_tool.h>
#include <ft_export_tool.h>
#include <ft_env_tool.h>

int	ft_env_print(void)
{
	extern char	**environ;
	int			i;

	i = 0;
	while (environ[i])
	{
		if (ft_export_find(environ[i]))
			printf("%s\n", environ[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_env(int argc, const char *argv[])
{
	int	i;

	ft_setenv("_", argv[0], 1);
	if (argc == 1)
		ft_env_print();
	else
	{
		i = 0;
		while (++i < argc)
		{
			ft_export_set((char *)argv[i]);
		}
		ft_env_print();
		i = 0;
		while (++i < argc)
		{
			ft_unsetenv(*ft_export_find((char *)argv[i]));
			ft_export_unset((char *)argv[i]);
		}
	}
	return (1);
}
