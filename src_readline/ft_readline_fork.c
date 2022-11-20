/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 09:53:44 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/20 13:13:24 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/syslimits.h>

#include <readline/readline.h>
#include <readline/history.h>

#include <ft_global.h>
#include <ft_readline.h>
#include <ft_tool.h>
#include <ft_terminal.h>

char	*ft_readline_fork(char *str)
{
	pid_t	pid;
	char	*rl_buffer;
	char	buff[ARG_MAX];
	int		fd_pipe[2];
	int		statu;

	rl_buffer = NULL;
	ft_bzero(buff, sizeof(char) * ARG_MAX);
	pipe(fd_pipe);
	pid = fork();
	if (!pid)
	{
		close(fd_pipe[STDIN_FILENO]);
		signal(SIGINT, g_global.old_ft);
		ft_tty_quit_off();
		rl_buffer = readline(str);
		ft_tty_quit_on();
		if (!rl_buffer)
			exit(-1);
		write(fd_pipe[STDOUT_FILENO], rl_buffer, ft_strlen(rl_buffer));
		exit(0);
	}
	close(fd_pipe[STDOUT_FILENO]);
	read(fd_pipe[STDIN_FILENO], buff, ARG_MAX);
	waitpid(pid, &statu, 0);
	if (statu < 0 || statu == 65280)
		return (NULL);
	close(fd_pipe[STDIN_FILENO]);
	return (ft_strdup((const char *)buff));
}

char	*ft_readline_fork_ori(char *str)
{
	pid_t	pid;
	char	*rl_buffer;
	char	buff[ARG_MAX];
	int		fd_pipe[2];
	int		statu;

	rl_buffer = NULL;
	ft_bzero(buff, sizeof(char) * ARG_MAX);
	pipe(fd_pipe);
	pid = fork();
	if (!pid)
	{
		close(fd_pipe[STDIN_FILENO]);
		signal(SIGINT, g_global.old_ft);
		ft_tty_quit_off();
		rl_buffer = readline(str);
		ft_tty_quit_on();
		if (!rl_buffer)
			exit(-1);
		write(fd_pipe[STDOUT_FILENO], rl_line_buffer, ft_strlen(rl_buffer));
		exit(0);
	}
	close(fd_pipe[STDOUT_FILENO]);
	read(fd_pipe[STDIN_FILENO], buff, ARG_MAX);
	waitpid(pid, &statu, 0);
	if (statu < 0 || statu == 65280)
		return (NULL);
	close(fd_pipe[STDIN_FILENO]);
	return (ft_strdup((const char *)buff));
}