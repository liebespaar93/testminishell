/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:56:33 by kyoulee           #+#    #+#             */
/*   Updated: 2022/11/14 09:56:34 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void	ft_execute(char *infile, char *outfile, char **argv, int last_cmd)
{
	extern char **environ;

	int	tmpin=dup(STDIN_FILENO);
	int	tmpout=dup(STDOUT_FILENO);
	int fdin;
	int fdout;
	int fdpipe[2];
	int pid;

	if (infile)
		fdin = open(infile, O_RDONLY);
	else
		fdin = dup(tmpin);
	dup2(fdin, 0);
	close(fdin);
	if (!last_cmd)
	{
		if (outfile)
			fdout = open(outfile, O_WRONLY | O_CREAT | O_APPEND);
		else
			fdout = dup(tmpout);
	}
	else
	{
		pipe(fdpipe);
		fdin = fdpipe[STDIN_FILENO];
		fdout = fdpipe[STDOUT_FILENO];
	}
	dup2(fdout, STDOUT_FILENO);
	close(fdout);
	pid = fork();
	if (!pid)
	{
		execve(argv[0], argv, environ);
		exit(1);
	}
	dup2(tmpin, STDIN_FILENO);
	dup2(tmpout, STDOUT_FILENO);
	close(tmpin);
	close(tmpout);
	wait(NULL);
}


# ifdef TEST_FT_EXECUTE
int main(int ar, char *av[])
{
	ft_execute(NULL, NULL, (char *[2]){"/usr/bin/head", NULL}, 0);
	return  (0);
}
#endif