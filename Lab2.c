#include <math.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	time_t t = time(NULL);
	struct tm* time = localtime(&t);
	pid_t pid;
	int status;
	int NumberProcess = 0, ProcessCount = pow(2,time->tm_hour);
	while(NumberProcess < ProcessCount)
	{
		NumberProcess++;
		pid=fork();
		if(pid == -1)
		{
			printf("Error");
			exit(1);
		}
		else if(pid == 0)
		{
			printf("ChildProcess Number %7d\tsin=%lf\n",NumberProcess,sin(time->tm_min));
			exit(0);
		}
		else 
		{
			wait(&status);
		}
	}
	printf("ParentProcess\tsin=%lf\n",sin(time->tm_min));
	return 0;
}
