/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:59:21 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/15 03:08:12 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include <ft_cmd.h>
#include <ft_tool.h>
#include <ft_env_tool.h>
#include <ft_builtin.h>

#include <stdio.h>
int		ft_execute(char *argv[]);

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

#include <ft_file.h>

int	ft_execute(char *argv[])
{
	char	*temp;
	int		pid;

	if (!argv[0])
		return (0);
	if (!ft_strcmp("echo", argv[0]))
		return (ft_echo(ft_void_len((void **)argv), (const char **)argv));
	else if (!ft_strcmp("cd", argv[0]))
		return (ft_cd(ft_void_len((void **)argv), (const char **)argv));
	else if (!ft_strcmp("pwd", argv[0]))
		return (ft_pwd());
	else if (!ft_strcmp("export", argv[0]))
		return (ft_export(ft_void_len((void **)argv), (const char **)argv));
	else if (!ft_strcmp("unset", argv[0]))
		return (ft_unset(ft_void_len((void **)argv), (const char **)argv));
	else if (!ft_strcmp("env", argv[0]))
		return (ft_env(ft_void_len((void **)argv), (const char **)argv));
	else if (!ft_strcmp("exit", argv[0]))
		return (ft_exit(ft_void_len((void **)argv), (const char **)argv));
	else if (ft_strchr(argv[0], '/'))
	{
		pid = fork();
		if (!pid)
		{
			if (execve(argv[0], argv, NULL) < 0)
						printf("%s\n", strerror(errno));
			exit(1);
		}
	}
	else
	{
		temp = ft_get_file(argv[0]);
		if (temp)
		{
			pid = fork();
			if (!pid)
			{
				if (execve(temp, argv, NULL) < 0)
				{
					printf("%s\n", strerror(errno));
					exit(1);
				}
			}
			wait(&pid);	
		}
		else 
			printf("%s: command not found\n", argv[0]);
		free(temp);
	}
	return (1);
}