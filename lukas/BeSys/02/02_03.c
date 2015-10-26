#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    int i;
    pid_t pid;

    for( i = 0; i < 3; i++ ) {
        pid = fork();
        if ( pid == 0 ) {
            printf("Kind: PID: %d; PPID: %d\n", getpid(), getppid() );
            sleep(2);
            break;
        }
    }
    if (pid > 0) {
        sleep(1);
        printf("I am the parent, my PID is %d and I'm waiting now.\n", getpid());
        int status;
        wait(&status);
//        printf("... und tschüss.\n");

    }
    printf("I am %d and I am done.\n", getpid());

}