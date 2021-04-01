# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include <signal.h>

int main()
{

    
    const char *afplay[] = { "/usr/bin/afplay", "/Users/sel-fcht/Downloads/test.mp3", 0 };

    int g_pid;
    char *argc[] = {"~/Downloads/test.mp3"};
	int		pid;

	
	if((pid = fork()) == 0)
	{
		execve(afplay[0],afplay,NULL );
	}
	else
	{
		g_pid = pid;
		printf("%d\n",getpid());
	}
}