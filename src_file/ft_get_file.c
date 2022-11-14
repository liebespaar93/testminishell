
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

char	*ft_get_file(char *name)
{
	char	*path;
	char	*next;
	char	*dir_name;
	char	*file_pwd;

	path = getenv("PATH");
	next = NULL;
	while (*path)
	{
		next = ft_strchr(path, ':');
		if (!next)
		{
			if (ft_readdir_get_file(path, name))
				return (ft_dir_join_file(path, name));
			break;
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