/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tty.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:05:26 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/20 13:07:11 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

void	ft_bash_ttyset_c_cc(struct termios *tty)
{
	(*tty).c_cc[VEOF] = 4;
	(*tty).c_cc[VEOL] = 255;
	(*tty).c_cc[VEOL2] = 255;
	(*tty).c_cc[VERASE] = 127;
	(*tty).c_cc[VWERASE] = 23;
	(*tty).c_cc[VKILL] = 21;
	(*tty).c_cc[VREPRINT] = 18;
	(*tty).c_cc[VINTR] = 3;
	(*tty).c_cc[VQUIT] = 28;
	(*tty).c_cc[VSUSP] = 26;
	(*tty).c_cc[VDSUSP] = 25;
	(*tty).c_cc[VSTART] = 17;
	(*tty).c_cc[VSTOP] = 19;
	(*tty).c_cc[VLNEXT] = 22;
	(*tty).c_cc[VDISCARD] = 15;
	(*tty).c_cc[VMIN] = 1;
	(*tty).c_cc[VTIME] = 0;
	(*tty).c_cc[VSTATUS] = 20;
}

void	ft_bash_ttyset(struct termios *tty)
{
	if (!tty)
		return ;
	(*tty).c_iflag = BRKINT | ICRNL | IXON | IXANY | IMAXBEL | IUTF8;
	(*tty).c_oflag = OPOST | ONLCR;
	(*tty).c_cflag = CSIZE | CREAD | HUPCL;
	(*tty).c_lflag = \
	ECHOKE | ECHOE | ECHOK | ECHO | ECHOCTL | ISIG | ICANON | IEXTEN | PENDIN;
	(*tty).c_ispeed = B38400;
	(*tty).c_ospeed = B38400;
	ft_bash_ttyset_c_cc(tty);
}

int	ft_tty_quit_on(void)
{
	int				fd;
	struct termios	newtty;

	fd = open(ttyname(STDIN_FILENO), O_RDWR | O_NOCTTY);
	if (fd < 0)
		return (-1);
	tcgetattr(fd, &newtty);
	newtty.c_cc[VQUIT] = 28;
	tcsetattr(fd, TCSANOW, &newtty);
	close(fd);
	return (0);
}

int	ft_tty_quit_off(void)
{
	int				fd;
	struct termios	newtty;

	fd = open(ttyname(STDIN_FILENO), O_RDWR | O_NOCTTY);
	if (fd < 0)
		return (-1);
	tcgetattr(fd, &newtty);
	newtty.c_cc[VQUIT] = 0;
	tcsetattr(fd, TCSANOW, &newtty);
	close(fd);
	return (0);
}
