/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 09:59:50 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/16 16:04:52 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include <ft_tool.h>
#include <ft_cmd.h>
#include <ft_transrate.h>
#include <ft_exe.h>

t_cmd	ft_cmd_init(void)
{
	t_cmd	cmd;

	cmd.argv = NULL;
	cmd.fd_in = STDIN_FILENO;
	cmd.fd_out = STDOUT_FILENO;
	return (cmd);
}

char	*ft_cmd_pipe(t_cmd *cmd, char *temp, int *flag)
{
	*flag = 1;
	ft_exe(cmd, *flag, 0);
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
	int		flag;

	temp = str;
	cmd = ft_cmd_init();
	flag = 0;
	while (*temp)
	{
		if (*temp == '|')
			temp = ft_cmd_pipe(&cmd, temp, &flag);
		else if (ft_strchr("<>", *temp))
			temp = ft_redirect(&cmd, temp);
		else if (ft_strchr(WHITE_SPACE, *temp))
			temp++;
		else
			temp = ft_cmd_word(&cmd, temp);
	}
	ft_exe(&cmd, flag, 1);
	ft_argv_free(&cmd);
	free(str);
	return (1);
}
