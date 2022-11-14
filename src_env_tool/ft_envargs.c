/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envargs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:30:24 by kyoulee           #+#    #+#             */
/*   Updated: 2022/10/26 04:41:08 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_envargs(void)
{
	extern char **environ;
	char **ep;

	ep = environ;
	while (*ep != NULL)
		printf("environ: %s\n", *ep++);
	return (EXIT_SUCCESS);
}