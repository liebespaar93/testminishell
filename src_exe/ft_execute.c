/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:59:21 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/19 23:22:09 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <ft_cmd.h>
#include <ft_tool.h>
#include <ft_builtin.h>
#include <ft_export_tool.h>
#include <ft_env_tool.h>
#include <ft_file.h>

int	ft_execute_dir(char *argv[])
{
	char		**envp;

	envp = ft_envp();
	if (execve(argv[0], argv, envp) < 0)
		printf("%s\n", strerror(errno));
	ft_free_envp(&envp);
	return (0);
}

int	ft_execute_else(char *argv[])
{
	char		*temp;
	char		**envp;

	temp = ft_get_file(argv[0]);
	if (*temp)
	{
		envp = ft_envp();
		if (execve(temp, argv, envp) < 0)
			printf("%s\n", strerror(errno));
		ft_free_envp(&envp);
	}
	else
		printf("%s: command not found\n", argv[0]);
	free(temp);
	return (0);
}

int	ft_set(int argc, const char *argv[])
{
	extern char	**environ;
	int	i;
	
	(void)argc;
	(void)argv;
	i = 0;
	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}

int	ft_execute(char *argv[])
{
	if (!argv[0])
		return (0);
	if (!ft_strcmp("echo", argv[0]))
		return (ft_echo(ft_void_len((void **)argv), (const char **)argv));
	else if (!ft_strcmp("cd", argv[0]))
		return (ft_cd(ft_void_len((void **)argv), (const char **)argv));
	else if (!ft_strcmp("pwd", argv[0]))
		return (ft_pwd());
	else if (!ft_strcmp("export", argv[0]))
		return (ft_export(ft_void_len((void **)argv), (const char **)argv));
	else if (!ft_strcmp("unset", argv[0]))
		return (ft_unset(ft_void_len((void **)argv), (const char **)argv));
	else if (!ft_strcmp("env", argv[0]))
		return (ft_env(ft_void_len((void **)argv), (const char **)argv));
	else if (!ft_strcmp("exit", argv[0]))
		return (ft_exit(ft_void_len((void **)argv), (const char **)argv));
	else if (!ft_strcmp("set", argv[0]))
		return (ft_set(ft_void_len((void **)argv), (const char **)argv));
	else if (ft_strchr(argv[0], '/'))
		return (ft_execute_dir(argv));
	else
		return (ft_execute_else(argv));
	return (0);
}
