/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_running.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 07:22:07 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/19 10:29:28 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/syslimits.h>

#include <ft_tool.h>
#include <ft_terminal.h>
#include <ft_cmd.h>
#include <ft_error.h>

char	*ft_while_eof(char *history_str, char *str, int *flag)
{
	char	*temp;

	if (!ft_strchr(str + 1, *str))
		ft_strcat(history_str, "\n");
	while (!ft_strchr(str + 1, *str))
	{
		temp = readline("> ");
		if (!temp)
		{
			free(temp);
			return (str + ft_strlen(str));
		}
		free(temp);
		ft_strcat(history_str, rl_line_buffer);
	}
	*flag = 0;
	return (ft_strchr(str + 1, *str));
}

char	*ft_pipe_eof(char *history_str, char *str)
{
	char	*temp;

	ft_strcat(history_str, " ");
	while (!*str || ft_strchr(WHITE_SPACE, *str))
	{
		if (!*str)
		{
			temp = readline("> ");
			if (!temp)
			{
				free(temp);
				return (str + ft_strlen(str));
			}
			ft_strcat(history_str, temp);
			free(temp);
		}
		else
			str++;
	}
	return (str);
}

char	*ft_redirect_eof(char *str, int *flag)
{
	char	*temp;

	if (!ft_strncmp(">>", str, 2))
		str += 2;
	else if (!ft_strncmp("<<", str, 2))
		str += 2;
	else if (!ft_strncmp(">", str, 1))
		str += 1;
	else if (!ft_strncmp("<", str, 1))
		str += 1;
	temp = str;
	while (*temp)
	{
		if (!ft_strchr(WHITE_SPACE, *temp))
			break ;
		else
			temp++;
	}
	if (!*temp)
		ft_syntax_error(flag, "\n");
	return (str);
}

char	*ft_semi_eof(char *start, char *end)
{
	char	*temp;

	ft_cmd(ft_strncpy(start, end - start));
	temp = end + 1;
	while (*temp && ft_strchr(WHITE_SPACE, *temp))
		temp++;
	if (!*temp)
		return (NULL);
	return (end + 1);
}

int	ft_running(char *history_str)
{
	char	*temp;
	char	*start;
	int		flag;

	flag = 1;
	start = history_str;
	temp = history_str;
	while (start)
	{
		if (!*temp)
			return (ft_cmd(ft_strncpy(start, temp - start)));
		else if (ft_strchr("\'\"", *temp))
			temp = ft_while_eof(history_str, temp, &flag) + 1;
		else if (*temp == '|' && !ft_syntax_error(&flag, temp))
			temp = ft_pipe_eof(history_str, temp + 1);
		else if (ft_strchr("<>",*temp) && !ft_syntax_error(&flag, temp))
			temp = ft_redirect_eof(temp, &flag);
		else if (*temp == ';' && !ft_syntax_error(&flag, temp))
			start = ft_semi_eof(start, temp++);
		else if (flag < 0)
			return (flag);
		else if (!ft_strchr(WHITE_SPACE, *temp++))
			flag = 0;
	}
	return (1);
}
