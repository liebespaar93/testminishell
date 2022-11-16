/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 23:03:12 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/16 15:09:18 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <ft_env_tool.h>
#include <ft_export_tool.h>
#include <ft_tool.h>

int	ft_unset(int argc, const char *argv[])
{
	int	flag;
	int	i;

	flag = 0;
	if (argc == 1)
		return (0);
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
			{
				ft_unsetenv((char *)argv[i]);
				ft_export_unset((char *)argv[i]);
			}
		}
	}
	return (flag);
}
