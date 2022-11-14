
#include <stdlib.h>
#include <ft_tool.h>
#include <ft_env_tool.h>

const char **ft_export_init(const char *envp[])
{
	const char	**export;
	int			len;
	int			i;
	
	len = ft_void_len((void **)envp);
	export = (const char **)malloc(sizeof(char *) * (len + 1));
	if (!export)
		return (NULL);
	i = 0;
	while (i < len)
	{
		export[i] = ft_strncpy((char *)envp[i], ft_strchr(envp[i], '=') - envp[i]);
		if (!export[i])
			return (NULL);
		i++;
	}
	export[i] = NULL;
	return (export);
}