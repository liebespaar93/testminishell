/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 23:17:49 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/16 15:08:33 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include <ft_tool.h>

int	ft_exit(int argc, const char *argv[])
{
	int	i;

	i = 0;
	if (argc > 2)
	{
		printf("%s: too many arguments\n", argv[0]);
		return (1);
	}
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i++]))
			printf("%s: %s: numeric argument required\n", argv[0], argv[1]);
		exit(255);
	}
	i = ft_atoi(argv[1]);
	exit(i % 256);
	return (0);
}
