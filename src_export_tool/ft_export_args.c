
#include <stdio.h>
#include <stdlib.h>
#include <ft_global.h>
#include <ft_tool.h>
#include <stdio.h>
#include <ft_env_tool.h>

int	ft_export_args(void)
{
	int		i;
	char	*max;
	char	*less;
	char	*last;

	last = "";
	max = "";
	less = "";
	i = 0;
	while (global.export_ptr[i])
	{
		if (ft_strcmp(max, global.export_ptr[i]) < 0)
			max = (char *)global.export_ptr[i];
		i++;
	}
	while (less != max)
	{
		i = 0;
		less = max;
		while (global.export_ptr[i])
		{
			if (ft_strcmp(last, global.export_ptr[i]) < 0 && ft_strcmp(less, global.export_ptr[i]) > 0)
				less = (char *)global.export_ptr[i];
			i++;
		}
		if (ft_strcmp("_", less))
		{
			printf("declare -x %s", less);
			if (getenv(less))
				printf("=\"%s\"", getenv(less));
			printf("\n");
		}
		last = less;
	}
	return (EXIT_SUCCESS);
}