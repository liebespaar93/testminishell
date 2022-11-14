/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir_in_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:21:00 by kyoulee           #+#    #+#             */
/*   Updated: 2022/10/26 16:49:08 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <ft_tool.h>
#include <dirent.h>

struct dirent	*ft_readdir_get_file(char *dir_name, char *file_name)
{
	DIR				*dir;
	struct dirent	*file;
	
	dir = opendir(dir_name);
	file = NULL;
	while(dir)
    {
		file = readdir(dir);
		if (!file)
			break ;
		if (!ft_strcmp(file->d_name, file_name) && !closedir(dir))
			return (file);
    }
	if (dir)
		closedir(dir);
	return (file);
}
