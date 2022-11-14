/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:22:07 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/14 13:20:15 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#include <ft_tool.h>
#include <ft_terminal.h>
#include <ft_global.h>


#include <stdlib.h>
int	main(int argc, char *argv[], char *envp[])
{
	struct termios	oldtty;
	struct termios	newtty;
	int				fd;

	(void)argc;
	(void)argv;
	ft_global_init((const char **)envp);
	global.origin_envp_ptr = (const char **)envp;
	fd = open(ttyname(STDIN_FILENO), O_RDWR | O_NOCTTY);
	if (fd < 0)
	{
		perror(ttyname(STDIN_FILENO));
		return (-1);
	}
	tcgetattr(fd, &oldtty);
	ft_bzero(&newtty, sizeof(struct termios));
	ft_bash_ttyset(&newtty);
	tcsetattr(fd, TCSANOW, &newtty);
	ft_tty_loop();
	tcsetattr(fd, TCSANOW, &oldtty);
	system("leaks a.out");
	return (1);
}
