/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 09:59:50 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/20 14:17:51 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include <ft_tool.h>
#include <ft_cmd.h>
#include <ft_transrate.h>
#include <ft_exe.h>
#include <ft_global.h>
#include <ft_env_tool.h>

#define MAX_CMD_LEN 200

t_cmd	ft_cmd_init(void)
{
	t_cmd	cmd;

	cmd.argv = NULL;
	cmd.fd_in = STDIN_FILENO;
	cmd.fd_out = STDOUT_FILENO;
	return (cmd);
}

#include <stdio.h>
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

void	ft_cmd_envset(t_cmd *cmd, int std)
{
	char	*temp;
	int		index;
	int		i;

	i = 0;
	index = 0;
	if (!cmd->argv)
		return ;
	while (cmd->argv[index])
	{
		temp = cmd->argv[index];
		while (ft_isalpha(*temp) || ft_isdigit(*temp) || *temp == '_')
			temp++;
		if (*temp != '=')
			break ;
		index++;
	}
	while (index)
	{
		i = 0;
		if (!cmd->argv[index--] && std)
			ft_putenv(cmd->argv[0]);
		else
			free(cmd->argv[0]);
		while (cmd->argv[i++])
			cmd->argv[i - 1] = cmd->argv[i];
	}
}

pid_t	ft_cmd_pipe(t_cmd *cmd)
{
	pid_t	pid;
	int		fd_pipe[2];

	pipe(fd_pipe);
	pid = fork();
	if (!pid)
	{
		close(fd_pipe[STDIN_FILENO]);
		if (cmd->fd_out != STDOUT_FILENO)
			close(fd_pipe[STDOUT_FILENO]);
		else
			cmd->fd_out = fd_pipe[STDOUT_FILENO];
		ft_exe(cmd);
		close(fd_pipe[STDOUT_FILENO]);
		close(cmd->fd_in);
		close(cmd->fd_out);
		exit(0);
	}
	close(fd_pipe[STDOUT_FILENO]);
	if (cmd->fd_in != STDIN_FILENO && !close(cmd->fd_in))
		cmd->fd_in = STDIN_FILENO;
	if (cmd->fd_out != STDOUT_FILENO && !close(cmd->fd_out))
		cmd->fd_out = STDOUT_FILENO;
	cmd->fd_in = fd_pipe[STDIN_FILENO];
	return (pid);
}

pid_t	ft_cmd_std(t_cmd *cmd)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
	{
		ft_exe(cmd);
		close(cmd->fd_in);
		close(cmd->fd_out);
		exit(0);
	}
	if (cmd->fd_in != STDIN_FILENO)
		close(cmd->fd_in);
	if (cmd->fd_out != STDOUT_FILENO)
		close(cmd->fd_out);
	return (pid);
}

void ft_cmd_wait(pid_t *pid, int index)
{
	int		std;
	char	*str_num;
	int		i;
	i = 0;
	while (i < index)
	{
		waitpid(pid[i], &std, 0);
		i++;
	}
	str_num = ft_itoa(std);
	ft_putenv(ft_strjoin("?=", str_num));
	free(str_num);
}

int	ft_cmd(char *str)
{
	t_cmd	cmd;
	pid_t	pid[MAX_CMD_LEN];
	char	*temp;
	int		std;
	int		index;

	temp = str;
	cmd = ft_cmd_init();
	std = 1;
	index = 0;
	while (*temp)
	{
		if (*temp == '|' && temp++)
		{
			ft_cmd_envset(&cmd, std);
			pid[index++] = ft_cmd_pipe(&cmd);
			ft_argv_free(&cmd);
			std = 0;
		}
		else if (ft_strchr("<>", *temp))
		{
			temp = ft_redirect(&cmd, temp);
			if (!temp)
				return (1);
		}
		else if (ft_strchr(WHITE_SPACE, *temp))
			temp++;
		else
			temp = ft_cmd_word(&cmd, temp);
	}
	ft_cmd_envset(&cmd, std);
	ft_cmd_std(&cmd);
	ft_cmd_wait(pid, index);
	ft_argv_free(&cmd);
	free(str);
	return (1);
}
