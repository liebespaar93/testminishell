/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 09:59:50 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/14 09:57:09 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include <ft_tool.h>
#include <ft_cmd.h>
#include <ft_transrate.h>

#include <stdio.h>
// test
void	ft_argv_printf(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (!cmd->argv)
		return ;
	while (cmd->argv[i])
	{
		printf("cmd->argv[%d] : %s\n", i, cmd->argv[i]);
		i++;
	}
}
// test end

t_cmd	ft_cmd_init(void)
{
	t_cmd	cmd;

	cmd.argv = NULL;
	cmd.fd_in = STDIN_FILENO;
	cmd.fd_out = STDOUT_FILENO;
	return (cmd);
}

char	*ft_cmd_pipe(t_cmd *cmd, char *temp)
{
	ft_argv_printf(cmd);
	ft_argv_free(cmd);
	*cmd = ft_cmd_init();
	return (temp + 1);
}

char	*ft_cmd_word(t_cmd *cmd, char *str)
{
	char	*temp;
	char	*argv;

	temp = str;
	while (*temp && \
		!ft_strchr(WHITE_SPACE, *temp) && !ft_strchr("<>|", *temp))
	{
		if (ft_strchr("\'\"", *temp))
			temp = ft_strchr(temp + 1, *temp);
		temp++;
	}
	argv = ft_strncpy(str, temp - str);
	ft_argv_add(cmd, ft_transrate_env(argv));
	free(argv);
	return (temp);
}

int	ft_cmd(char *str)
{
	t_cmd	cmd;
	char	*temp;

	temp = str;
	cmd = ft_cmd_init();
	while (*temp)
	{
		if (*temp == '|')
			temp = ft_cmd_pipe(&cmd, temp);
		else if (ft_strchr("<>", *temp))
			temp = ft_redirect(&cmd, temp);
		else if (ft_strchr(WHITE_SPACE, *temp))
			temp++;
		else
			temp = ft_cmd_word(&cmd, temp);
	}
	ft_argv_printf(&cmd);
	ft_argv_free(&cmd);
	free(str);
	return (1);
}
