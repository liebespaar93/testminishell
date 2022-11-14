/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:59:21 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/14 12:14:47 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include <ft_cmd.h>
#include <ft_tool.h>


int	ft_exe_set(t_cmd *cmd)
{
	char	*temp;
	int		i;

	temp = cmd->argv[0];
	i = 0;
	if (!temp)
		return (0);
	while (ft_isalpha(*temp) || ft_isdigit(*temp) || *temp == '_')
		temp++;
	if (*temp == '=')
	{
		// ft_putenv 수정요망
		putenv(ft_strdup(cmd->argv[0]));
		free(cmd->argv[0]);
		while (cmd->argv[i])
			cmd->argv[i] = cmd->argv[i + 1];
		return (1);
	}
	return (0);
}

void	ft_exe_pipe(t_cmd *cmd)
{
	pid_t	pid;
	int		fd_pipe[2];
	
	pipe(fd_pipe);
	pid = fork();
	if (!pid)
	{
		while (ft_exe_set(cmd))
			;
		if (cmd->fd_in == STDIN_FILENO)
			dup2(fd_pipe[STDIN_FILENO], STDIN_FILENO);
		else
			dup2(cmd->fd_in, STDIN_FILENO);
		if (cmd->fd_out == STDOUT_FILENO)
			dup2(fd_pipe[STDOUT_FILENO], STDOUT_FILENO);
		else
			dup2(cmd->fd_out, STDOUT_FILENO);
		execve(cmd->argv[0], cmd->argv, NULL);
		exit(0);
	}
	wait(NULL);
	close(fd_pipe[STDIN_FILENO]);
	close(fd_pipe[STDOUT_FILENO]);
}

#include <stdio.h>

void	ft_exe(t_cmd *cmd, int flag)
{
	if (flag)
	{
		ft_exe_pipe(cmd);
		printf("%s\n", getenv("b"));
	}
	else
	{
		while (ft_exe_set(cmd))
			;
		printf("%s\n", getenv("a"));
	}
}


