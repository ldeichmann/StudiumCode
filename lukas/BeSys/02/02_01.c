#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int status;
    pid = fork();
    if (pid < 0) { // failed fork
        printf("Fork failed.");
        return -1;
    } else if (pid == 0) { // child
        printf("Hello, I am a child and my pid is %d and my parent pid is %d\n", getpid(), getppid() );
        printf("Hello, I am a child and I am now going to make my parent wait for me.\n");
        sleep(2);
        printf("Hello, I am a child and I'm done.\n");
    } else { // parent
        printf("Hello children, my PID is %d\n", getpid() );
        printf("Hello children, I am now going to wait for you.\n");
        wait(&status);
        printf("Hello children, your exit status was %d, I am done waiting.\n", status);
    }
    return 0;
}