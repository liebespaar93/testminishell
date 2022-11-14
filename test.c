/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:49:01 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/14 09:49:44 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ft_cmd.h>

void	ft_argv_printf(t_cmd *cmd)
{
	int	i;

	i == 0;
	if (!cmd->argv)
		return ;
	while (cmd->argv[i])
	{
		printf("cmd->argv[%d] : %s\n", i, cmd->argv[i]);
		i++;
	}
}
