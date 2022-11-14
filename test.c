#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>



int main(int ar, char **av, char **envp)
{
	pid_t	pid;
	int		fd[2];
	int		ttyfd[2];
	int		fdpipe[2];

	putenv("a=");
	ttyfd[STDIN_FILENO] = dup(STDIN_FILENO);
	ttyfd[STDIN_FILENO] = dup(STDOUT_FILENO);
	pipe(fdpipe);
	pid = fork();
	if (pid)
	{
		putenv("a=4");
		execve("/usr/bin/head", (char *[5]){"/usr/bin/head", "-n","100", "test.c", NULL}, envp);
	}
	else
		wait(NULL);
	printf("'%s'",getenv("a"));
	
	dup2(ttyfd[STDIN_FILENO], STDIN_FILENO);
	dup2(ttyfd[STDOUT_FILENO], STDOUT_FILENO);
}