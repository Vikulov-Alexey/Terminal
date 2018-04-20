#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

pid_t pid, child_pid;

void main()
{
	int status;
	char *words[100];
	char proc[100];
	char sep[] = " ";
	while(1)
	{
		printf("Терминал: ");
		gets(proc);
		int i = 0; 
		char *ptr = strtok(proc, sep);
		while (ptr != NULL)
		{
			words[i++] = ptr;
			ptr = strtok (NULL, sep);
		}
		words[i] = NULL;
			
		if (strcmp(words[0], "break") == 0)
			exit(0);

		switch(pid=fork()) 
		{
			case -1:
				printf("Ошибка");
				exit(1);
			case 0:
				execvp(words[0],words);
			default:
				child_pid = pid;
				child_pid = wait(&status);
		}
	}
}

void kill_p(int sign)
{
	kill(child_pid,sign);
}
