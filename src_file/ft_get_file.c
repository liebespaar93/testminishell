/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:53:37 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/15 12:31:43 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <ft_tool.h>
#include <ft_dir.h>

char	*ft_dir_join_file(char *dir, char *file_name)
{
	char	*file_pwd;

	file_pwd = (char *)malloc(ft_strlen(dir) + ft_strlen(file_name) + 2);
	if (!file_pwd)
		return (NULL);
	ft_strcpy(file_pwd, dir);
	ft_strcat(file_pwd, "/");
	ft_strcat(file_pwd, file_name);
	return (file_pwd);
}

char	*ft_get_file_in_path(char *name, char *path, char *next)
{
	char	*dir_name;
	char	*file_pwd;

	while (*path)
	{
		next = ft_strchr(path, ':');
		if (!next)
		{
			if (ft_readdir_get_file(path, name))
				return (ft_dir_join_file(path, name));
			break ;
		}
		dir_name = ft_strncpy(path, next - path);
		path = next + 1;
		if (ft_readdir_get_file(dir_name, name))
		{
			file_pwd = ft_dir_join_file(dir_name, name);
			free(dir_name);
			return (file_pwd);
		}
		free(dir_name);
	}
	return (NULL);
}

char	*ft_get_file(char *name)
{
	char	*path;
	char	*next;
	char	*file_pwd;

	path = getenv("PATH");
	next = NULL;
	file_pwd = ft_get_file_in_path(name, path, next);
	if (file_pwd)
		return (file_pwd);
	return (ft_strdup(""));
}
