#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    int i, j;
    pid_t pid;
    pid_t ppid = getpid();
    int status;

    for( i = 0; i < 4; i++ ) { // Fork 1, four times
        if (getpid() == ppid) {
	        pid = fork();
	        if ( pid == 0 ) {
	            printf("F1: Kind: PID: %d; PPID: %d\n", getpid(), getppid() );
	            for( j = 0; j < 2; j++ ) {  // Fork 2, twice
	                if (getppid() == ppid) {
		                pid = fork();
		                if (pid == 0) {
		                    sleep(1);
		                    printf("F2: Kind: PID: %d; PPID: %d\n", getpid(), getppid() );
		                    pid = fork();
		                    if (pid == 0) {  // Fork 3, one time
		                        sleep(8);
		                        printf("F3: Kind: PID: %d; PPID: %d\n", getpid(), getppid() );
		                        sleep(5);
		                    }
		                    sleep(2);
		                }
		            }
	            }
	            sleep(2);
	        }
	    }
    }
    if (ppid == getpid()) {
        printf("I am the parent, my PID is %d and I'm waiting now.\n", getpid());
        wait(&status);
        wait(&status);
        wait(&status);
        wait(&status);
        printf("I am the parent, we're done here.\n");
    } else {
        printf("I am %d and I am waiting.\n", getpid());
        wait(&status);
        wait(&status);
        printf("I am %d and I am done.\n", getpid());
    }


}