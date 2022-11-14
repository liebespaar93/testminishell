/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 23:03:12 by kyoulee           #+#    #+#             */
/*   Updated: 2022/10/25 23:12:10 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_env_tool.h>
#include <ft_export_tool.h>
#include <ft_tool.h>
#include <stdio.h>

int	ft_unset(int argc, const char *argv[])
{
	int	flag;
	int i;
	
	ft_setenv("_", argv[0], 1);
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