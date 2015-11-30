#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <math.h>

#define N0 8
//Global
int divisor = 2;
int totalThread = 0;
pthread_mutex_t totalThreadMutex= PTHREAD_MUTEX_INITIALIZER;

//struct used for passing information to children
struct threadInfo{
    int threadNum;
    int parentThreadCount;
};

//min - returns lesser integer
int min(int a, int b){
    if(a<=b){
        return a;
    }
    else{
        return b;
    }

}


//threadFunc
void *threadFunc(void *ptr){
    struct threadInfo* parentInfo = (struct threadInfo*) ptr;
    int numChildren = min(parentInfo->parentThreadCount/divisor, 16);
    int i;
    pthread_t pthreadArr[numChildren];

    //start
    printf("START: %d\n\tparent children: %d\n\tchildren: %d\n", parentInfo->threadNum, parentInfo->parentThreadCount, numChildren);
    //create
    for(i = 0; i < numChildren; i++){
        pthread_mutex_lock(&totalThreadMutex);
        totalThread++;

        // we'll have to work with malloc here, otherwise there'll be conflicting childInfos found within children (eg wrong values)
        struct threadInfo *childInfo = (struct threadInfo*)malloc(sizeof(struct threadInfo));
        childInfo->threadNum = totalThread;
        childInfo->parentThreadCount = numChildren;
        pthread_mutex_unlock(&totalThreadMutex);

        pthread_create(&pthreadArr[i], NULL, threadFunc, childInfo);
    }

    //wait for every child we have
    for(i = 0; i < numChildren; i++){
        pthread_join(pthreadArr[i], NULL);
    }

    printf("END: %d\n", parentInfo->threadNum);

    return NULL;

}

//Main
int main(void){
    pthread_t pth;
    struct threadInfo *info = (struct threadInfo*)malloc(sizeof(struct threadInfo));
    pthread_mutex_lock(&totalThreadMutex);
    totalThread++;
    info->threadNum = totalThread;
    pthread_mutex_unlock(&totalThreadMutex);

    // although the result is most likely not an integer, we'll just assume it is
    // as we are supposed to floor (N0/divisor), which is equal to simply dropping
    // the remainder when only looking at values >= 0, just as we do
    info->parentThreadCount = min(N0/divisor, 16);

    pthread_create(&pth, NULL, threadFunc, info);

    pthread_join(pth, NULL);

    printf("final ThreadCount: %d\n", totalThread);
}
