#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "queue.h"

QueuePtr initQueue() {
    QueuePtr Queue = malloc(sizeof(Queue));
    return Queue;
}

void enqueue(QueuePtr queue, Task task, char* taskName) {
    TaskListNodePtr taskPtr = malloc(sizeof(TaskListNode));
    taskPtr -> next = NULL;
    taskPtr -> task = task;

    strcpy(taskPtr -> taskname, taskName);

    if(queue -> head == NULL) {
        queue -> head = taskPtr;
        queue -> tail = taskPtr;
    }
    else {
        queue -> tail -> next = taskPtr;
        queue -> tail = taskPtr;
    }

}

void dequeue(QueuePtr queue, char* taskName) {
    if(queue -> head == NULL) {
        printf("Queue empty\n");
    }
    else {
        queue -> head -> task(42);
        strcpy(taskName, queue -> head -> taskname);

        if(queue -> head -> next) {
            TaskListNodePtr taskPtr = queue -> head -> next;
            free(queue -> head);
            queue -> head = taskPtr;
        }
        else {
            free(queue -> head);
            queue -> head = NULL;
            queue -> tail = NULL;
        }
    }
}

void destroyQueue(QueuePtr queue) {
    free(queue);
}

void printQueue(QueuePtr queue) {

}
