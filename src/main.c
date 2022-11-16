/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:22:07 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/16 15:18:48 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#include <ft_tool.h>
#include <ft_terminal.h>
#include <ft_global.h>
#include <ft_env_tool.h>

int	main(int argc, char *argv[], const char *envp[])
{
	struct termios	oldtty;
	struct termios	newtty;
	int				fd;

	(void)argc;
	(void)argv;
	ft_global_init(envp);
	g_global.origin_envp_ptr = envp;
	fd = open(ttyname(STDIN_FILENO), O_RDWR | O_NOCTTY);
	if (fd < 0)
		return (-1);
	tcgetattr(fd, &oldtty);
	ft_bzero(&newtty, sizeof(struct termios));
	ft_bash_ttyset(&newtty);
	tcsetattr(fd, TCSANOW, &newtty);
	close(fd);
	ft_tty_loop();
	fd = open(ttyname(STDIN_FILENO), O_RDWR | O_NOCTTY);
	if (fd < 0)
		return (-1);
	tcsetattr(fd, TCSANOW, &oldtty);
	close(fd);
	return (1);
}
