/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:09:10 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/15 13:24:11 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include <ft_global.h>
#include <ft_tool.h>
#include <ft_env_tool.h>

char	*ft_export_max(void)
{
	char	*max;
	int		i;

	i = 0;
	max = "";
	while (g_global.export_ptr[i])
	{
		if (ft_strcmp(max, g_global.export_ptr[i]) < 0)
			max = (char *)g_global.export_ptr[i];
		i++;
	}
	return (max);
}

void	ft_export_printf(char *less)
{
	if (ft_strcmp("_", less))
	{
		printf("declare -x %s", less);
		if (getenv(less))
			printf("=\"%s\"", getenv(less));
		printf("\n");
	}
}

int	ft_export_args(void)
{
	int		i;
	char	*max;
	char	*less;
	char	*last;

	last = "";
	less = "";
	max = ft_export_max();
	while (less != max)
	{
		i = 0;
		less = max;
		while (g_global.export_ptr[i])
		{
			if (ft_strcmp(last, g_global.export_ptr[i]) < 0 && \
				ft_strcmp(less, g_global.export_ptr[i]) > 0)
				less = (char *)g_global.export_ptr[i];
			i++;
		}
		ft_export_printf(less);
		last = less;
	}
	return (EXIT_SUCCESS);
}
