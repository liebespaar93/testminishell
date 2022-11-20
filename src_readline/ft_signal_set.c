/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 01:24:42 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/20 13:11:13 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>

#include <ft_tool.h>
#include <ft_running.h>
#include <ft_global.h>

void	ft_sigint(int signo)
{
	(void)signo;
	signal(SIGINT, ft_sigint);
	return ;
}

int	ft_signal_set(void)
{
	g_global.old_ft = signal(SIGINT, ft_sigint);
	return (0);
}
