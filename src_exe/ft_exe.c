/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:59:21 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/14 10:10:54 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cmd.h>
#include <ft_tool.h>

int	ft_exe_set(t_cmd *cmd)
{
	char	*temp;
	char	*env;

	temp = cmd->argv[0];
	if (!temp)
		return (0);
	env = temp;
	while (ft_isalpha(*temp) || ft_isdigit(*temp) || *temp == '_')
		temp++;
	if (*temp == "=")
	{
		ft_putenv()
		return (1);
	}
	return (0);
}
void	ft_exe(t_cmd *cmd)
{
	while (ft_exe_set(cmd))
	{

	}
}


