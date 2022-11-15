/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:44:45 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/15 12:46:15 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <ft_tool.h>
#include <ft_env_tool.h>

int	ft_cd(int argc, const char *argv[])
{
	int			ret;
	char		buf[1024];
	const char	*target;

	(void)argc;
	ft_setenv("_", argv[0], 1);
	target = argv[1];
	if (!ft_strcmp(argv[1], "~"))
		target = getenv("HOME");
	if (!ft_strcmp(argv[1], "-"))
		target = getenv("OLDPWD");
	ret = chdir(target);
	if (ret != 0 && printf("ERROR : '%s' is %s\n", target, strerror(errno)))
		return (0);
	if (getcwd(buf, 1024) == NULL && printf("ERROR : %s\n", strerror(errno)))
		return (0);
	ft_putenv(ft_strjoin("OLDPWD=", getenv("PWD")));
	ft_putenv(ft_strjoin("PWD=", buf));
	return (1);
}
