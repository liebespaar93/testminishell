/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:59:21 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/15 14:28:00 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include <ft_cmd.h>
#include <ft_tool.h>
#include <ft_builtin.h>
#include <ft_export_tool.h>
#include <ft_env_tool.h>
#include <ft_exe.h>

/**
 * 마즈막 실행코드 출력 (파이프가 있을시 전역번수 적용 x)
 * 코드 클린업
 * $? 만들기
 */

void	ft_exe_set(t_cmd *cmd)
{
	char	*temp;
	int		index;
	int		i;

	i = 0;
	index = 0;
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
		if (!cmd->argv[index--])
			ft_putenv(cmd->argv[0]);
		else
			free(cmd->argv[0]);
		while (cmd->argv[i++])
			cmd->argv[i - 1] = cmd->argv[i];
	}
}

void	ft_exe_pipe(t_cmd *cmd)
{
	pid_t	pid;
	int		fd_pipe[2];
	int		ft_tty[2];

	ft_tty[STDIN_FILENO] = dup(STDIN_FILENO);
	ft_tty[STDOUT_FILENO] = dup(STDOUT_FILENO);
	pipe(fd_pipe);
	pid = fork();
	if (!pid)
	{
		ft_exe_set(cmd);
		if (cmd->fd_in == STDIN_FILENO)
			dup2(fd_pipe[STDIN_FILENO], STDIN_FILENO);
		else
			dup2(cmd->fd_in, STDIN_FILENO);
		if (cmd->fd_out == STDOUT_FILENO)
			dup2(fd_pipe[STDOUT_FILENO], STDOUT_FILENO);
		else
			dup2(cmd->fd_out, STDOUT_FILENO);
		ft_execute(cmd->argv);
		dup2(ft_tty[STDIN_FILENO], STDIN_FILENO);
		dup2(ft_tty[STDOUT_FILENO], STDOUT_FILENO);
		close(fd_pipe[STDIN_FILENO]);
		close(fd_pipe[STDOUT_FILENO]);
		exit(0);
	}
	wait(NULL);
	close(fd_pipe[STDIN_FILENO]);
	close(fd_pipe[STDOUT_FILENO]);
}

void	ft_exe_std(t_cmd *cmd)
{
	int		ft_tty[2];

	ft_tty[STDIN_FILENO] = dup(STDIN_FILENO);
	ft_tty[STDOUT_FILENO] = dup(STDOUT_FILENO);
	ft_exe_set(cmd);
	if (cmd->fd_in != STDIN_FILENO)
		dup2(cmd->fd_in, STDIN_FILENO);
	if (cmd->fd_out != STDOUT_FILENO)
		dup2(cmd->fd_out, STDOUT_FILENO);
	ft_execute(cmd->argv);
	dup2(ft_tty[STDIN_FILENO], STDIN_FILENO);
	dup2(ft_tty[STDOUT_FILENO], STDOUT_FILENO);
}

void	ft_exe(t_cmd *cmd, int flag)
{
	if (flag)
	{
		ft_exe_pipe(cmd);
	}
	else
	{
		ft_exe_std(cmd);
	}
}
