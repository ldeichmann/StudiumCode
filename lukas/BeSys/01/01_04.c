#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	pid_t pid;
	pid = fork();
	if (pid < 0) { // failed fork
		printf("Fork failed.");
		return -1;
	} else if (pid == 0) { // child
		printf("Hello, I am a child and my pid is %d and my parent pid is %d\n", getpid(), getppid() );
	} else { // parent
		printf("Hello children, my PID is %d and my childs PID is %d\n", getpid(), pid );
	}
	return 0;
}
