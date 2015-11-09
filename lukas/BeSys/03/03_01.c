#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *calc_function1( );
void *calc_function2( );

int value = 10;

int main()
{
    pthread_t thread1, thread2;
    const char *message1 = "Thread 1";
    const char *message2 = "Thread 2";
    int  iret1, iret2;
    

    /* Create independent threads each of which will execute function */

    iret1 = pthread_create( &thread1, NULL, calc_function1, NULL);
    if(iret1)
    {

        fprintf(stderr,"Error - pthread_create() return code: %d\n",iret1);
        exit(EXIT_FAILURE);
    }

//    sleep(1);

    iret2 = pthread_create( &thread2, NULL, calc_function2, NULL);
    if(iret2)
    {
        fprintf(stderr,"Error - pthread_create() return code: %d\n",iret2);
        exit(EXIT_FAILURE);
    }

    printf("pthread_create() for thread 1 returns: %d\n",iret1);
    printf("pthread_create() for thread 2 returns: %d\n",iret2);

    /* Wait till threads are complete before main continues. Unless we  */
    /* wait we run the risk of executing an exit which will terminate   */
    /* the process and all threads before the threads have completed.   */

    pthread_join( thread1, NULL);
    pthread_join( thread2, NULL);

    printf("Final value: %d\n", value);

    exit(EXIT_SUCCESS);
}

void *calc_function1()
{
    sleep(1);
    printf("1 Value: %d \n", value);
    value = value + 15;
    printf("1 Value: %d \n", value);

}


void *calc_function2()
{
    sleep(2);
    printf("1 Value: %d \n", value);
    value = value + 9;
    printf("1 Value: %d \n", value);

}