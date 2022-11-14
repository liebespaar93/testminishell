



#include <ft_global.h>
#include <stdlib.h>
#include <ft_tool.h>
#include <ft_export_tool.h>

int	ft_export_unset(char *name)
{
	(void)name;
	const char	**export;
	const char	**target;
	int			i;
	
	target = ft_export_find(name);
	if (!target)
		return (0);
	export = global.export_ptr;
	i = 0;

	while (export[i] && export[i] != *target)
		i++;
	free((void *)export[i]);
	while (export[i])
	{
		export[i] = export[i + 1];
		i++;
	}
	return (0);
}

