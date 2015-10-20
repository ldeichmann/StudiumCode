#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	int i = 111;
	pid_t pid;
	pid = fork();
	if (pid < 0) { // failed fork
		printf("Fork failed.");
		return -1;
	} else if (pid == 0) { // child
		printf("Hello, I am a child and my pid is %d\n", getpid() );
		printf("Hello, I am a child and I am going to change i = %d now\n", i);
		i = 50;
                printf("Hello, I am a child and I changed i to i = %d\n", i);
	} else { // parent
		printf("Hello children, my PID is %d\n", getpid() );
                printf("Hello children, I am going to change i = %d now\n", i);
		i = 90;
                printf("Hello children, I changed i to i = %d\n", i);
	}
//	printf( "Hello, my PID is %d\n", getpid() );
	return 0;
}
