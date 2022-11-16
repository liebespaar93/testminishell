/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:23:12 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/16 15:08:41 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include <ft_tool.h>
#include <ft_export_tool.h>

int	ft_export(int argc, const char *argv[])
{
	int	i;
	int	flag;

	flag = 0;
	if (argc == 1)
	{
		ft_export_args();
	}
	else
	{
		i = 0;
		while (++i < argc)
		{
			if (!(ft_isalpha(*argv[i]) || *argv[i] == '_'))
			{
				printf("%s: `%s': not a valid identifier", argv[0], argv[i]);
				flag = 1;
			}
			else
				ft_export_set((char *)argv[i]);
		}
	}
	return (flag);
}
