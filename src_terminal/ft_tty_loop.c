/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tty_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:55:35 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/20 01:27:10 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/syslimits.h>

#include <ft_tool.h>
#include <ft_running.h>

void	ft_tty_loop(void)
{
	char	history_str[ARG_MAX];
	char	*temp;

	ft_bzero(history_str, sizeof(char [ARG_MAX]));
	while (1)
	{
		ft_bzero(history_str, sizeof(char [ARG_MAX]));
		temp = readline("minishell-0.4$ ");
		if (!temp && printf("\b\bexit\n"))
			return ;
		ft_strcat(history_str, temp);
		free(temp);
		if (*history_str)
		{
			ft_running(history_str);
			add_history(history_str);
		}
	}
}
