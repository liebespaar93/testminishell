/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tty_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:55:35 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/20 14:12:00 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/syslimits.h>

#include <ft_tool.h>
#include <ft_running.h>
#include <ft_readline.h>

void	ft_tty_loop(void)
{
	char	history_str[ARG_MAX];
	char	*temp;
	
	ft_bzero(history_str, sizeof(char [ARG_MAX]));
	ft_signal_set();
	while (1)
	{
		temp = NULL;
		ft_bzero(history_str, sizeof(char [ARG_MAX]));
		temp = ft_readline_fork("minishell-0.7$ ");
		if (!temp && printf("\b\bexit\n"))
			return ;
		if (!*temp && printf("\n"))
			continue ;
		ft_strcat(history_str, temp);
		free(temp);
		if (*history_str)
		{
			ft_running(history_str);
			add_history(history_str);
		}
	}
}
