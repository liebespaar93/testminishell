/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 00:32:42 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/16 15:08:12 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#include <ft_tool.h>

int	ft_echo(int argc, const char *argv[])
{
	int		i;
	int		flag;
	char	*temp;

	i = 1;
	flag = 1;
	while (i < argc && !ft_strncmp(argv[i], "-n", 2))
	{
		temp = (char *)argv[i];
		temp++;
		while (*temp && *temp == 'n')
			temp++;
		if (*temp)
			break ;
		flag = 0;
		i++;
	}
	while (i < argc)
	{
		write(STDOUT_FILENO, argv[i], ft_strlen(argv[i]));
		i++;
	}
	if (flag)
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}
