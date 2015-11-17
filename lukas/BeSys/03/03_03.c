#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <time.h>

#define MAX_THREAD 10
//#define RAND_MAX 10

int makerand();
void *foo(void*);

struct threadInfo {
   int  randNum;
   int  threadNum;
};

int waittime = 0;
int curt = 1;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int makerand(){
    int r = 0;
	int M = 0;
	int N = 10;
//	srand ( time(NULL) );
	srand( time(0)+clock()+random() ); // holy random nonsense batman

    r = M + rand() / (RAND_MAX / (N - M + 1) + 1);
    return r;
}

void *foo(void *ptr){
    int i = 0;
	struct threadInfo tiIncoming = *((struct threadInfo*) ptr);
    struct threadInfo ti1;
	struct threadInfo ti2;
    pthread_t pth0;
    pthread_t pth1;
	int t = 0;


    printf("Threadnr: %d st: %d\n", tiIncoming.threadNum, tiIncoming.randNum);

    sleep(tiIncoming.randNum);
    for(i = 0; i < 2; i++){
		pthread_mutex_lock(&mutex);

        if(curt < MAX_THREAD){
            if(i == 0){
				ti1.threadNum = curt + 1;
				ti1.randNum = makerand();
                pthread_create(&pth0, NULL, foo, &ti1);
                curt++;
				t = 1;
            }
            else {
				ti2.threadNum = curt + 1;
				ti2.randNum = makerand();
                pthread_create(&pth1, NULL, foo, &ti2);
                curt++;
				t = 2;
            }
        }
		pthread_mutex_unlock(&mutex);
    }
	if (t == 1) {
    	pthread_join(pth0, NULL);
	} else if (t == 2) {
		pthread_join(pth0, NULL);
		pthread_join(pth1, NULL);
	}
	/* the function must return something - NULL will do */
	return NULL;
}



int main(){
    pthread_t thread;
	struct threadInfo ti0;
	ti0.threadNum = curt;
	ti0.randNum = makerand();

    pthread_create(&thread, NULL, foo, &ti0);

    pthread_join(thread, NULL);
}
