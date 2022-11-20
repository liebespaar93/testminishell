/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 08:16:36 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/20 11:27:58 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERMINAL_H
# define FT_TERMINAL_H

# include <termios.h>

void	ft_bash_ttyset(struct termios *tty);
void	ft_tty_loop(void);

int		ft_tty_quit_on(void);
int		ft_tty_quit_off(void);

#endif