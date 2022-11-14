
#include <pwd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int	ft_pwd(void)
{
	char	buf[1024];
	
	if (getcwd(buf, 1024) == NULL)
	{
		printf("ERROR: PWD %s \n", strerror(errno));
		return (0);
	}
	else
		printf("%s\n",buf);
	return (1);
}