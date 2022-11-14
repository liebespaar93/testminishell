/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:22:07 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/13 12:23:01 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#include <ft_tool.h>
#include <ft_terminal.h>

int	main(void)
{
	struct termios	oldtty;
	struct termios	newtty;
	int				fd;

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
	return (1);
}
