/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_argv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:45:04 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/14 09:48:31 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <ft_cmd.h>
#include <ft_tool.h>

int	ft_argv_len(t_cmd *cmd)
{
	int	len;

	len = 0;
	if (!cmd->argv)
		return (0);
	while (cmd->argv[len])
		len++;
	return (len);
}

char	**ft_argv_cpy(char **new, t_cmd *cmd)
{
	int	index;

	index = 0;
	if (!cmd->argv)
		return (new);
	while (cmd->argv[index])
	{
		new[index] = cmd->argv[index];
		index++;
	}
	return (new);
}

char	**ft_argv_add(t_cmd *cmd, char *str)
{
	char	**new;
	int		len;

	len = ft_argv_len(cmd);
	new = (char **)malloc(sizeof(char *) * (len + 2));
	if (!new)
		return (NULL);
	ft_argv_cpy(new, cmd);
	new[len] = str;
	new[len + 1] = NULL;
	if (cmd->argv)
		free(cmd->argv);
	cmd->argv = new;
	return (new);
}

void	ft_argv_free(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (!cmd->argv)
		return ;
	while (cmd->argv[i])
		free(cmd->argv[i++]);
	free(cmd->argv);
}
