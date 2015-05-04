#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "queue.h"

/**
 * Initialisiert eine Queue. Legt leere Instanz von Queue auf Heap an
 * und liefert Pointer darauf. (10 Punkte)
 * @return Leere Queue
 */
QueuePtr initQueue() {
    QueuePtr Queue = malloc(sizeof(Queue));
    return Queue;
}

/**
 * Fuegt einen Task hinten in die Queue ein. Ein Zeiger auf die Funktion und eine
 * Zeichenketter fuer den Namen des Task werden dazu in die Queue eingefuegt.
 * Die Zeichenkette wird dazu kopiert. Zu diesem Zweck wird neu ein TaskListNode auf
 * dem Heap angelegt und an die Queue angehaegt. (10 Punkte)
 * @param queue Queue zu der das Element hinzuzufuegen ist
 * @param task Zu speichernder Task
 * @param taskName Textuelle Beschreibung des Task
 */
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

/**
 * Entfernt einen Task Zeichenkette vorne aus der Queue und fuehrt ihn aus.
 * Dem auszufuehrenden Task wird dabei immer die id 42 als Parameter uebergeben
 * Die Beschreibung des ausgefuehrten Task wird in dem uebergebenen Zielpuffer gespeichert.
 * Der Puffer muss mindestens Platz fuer 20 Zeichen besitzen (10 Punkte)
 * @param queue Queue aus der das Element entfernt werden soll
 * @param dest Zielpuffer fuer die Beschreibung des ausgefuehrten Task
 */
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

/**
 * Gibt den Speicher der Queue wieder frei. (10 Punkte)
 * @param queue Freizugebende Queue
 */
void destroyQueue(QueuePtr queue) {
    TaskListNodePtr tmp;
    TaskListNodePtr nextTmp;

    if(queue -> head) {
        tmp = queue -> head;
        if (queue -> head -> next) {
            nextTmp = queue -> head -> next;
        }

        while (tmp != NULL) {
        if (nextTmp != NULL) {
            tmp = nextTmp;
            if (tmp -> next)
                tmp = tmp -> next;
        }
        free(tmp);

        }
    }
}

/**
 * Gibt die Liste der in der Queue gespeicherten Tasks aus,
 * indem element->next bis NULL gefolgt wird (Zusammen 10 Punkte)
 * @param queue
 */
void printQueue(QueuePtr queue) {
    TaskListNodePtr tmp;
    TaskListNodePtr tmpNext = NULL;
    if (queue->head) {
        tmp = queue->head;
        if (queue->head->next) {
            tmpNext= queue->head->next;
        }

        while ( tmp ) {
            printf("%s\n", tmp->taskname);
            if (tmpNext) {
                tmp = tmpNext;
                if (tmp->next) {
                    tmpNext = tmp->next;
                } else {
                    tmpNext = NULL;
                }
            } else {
                tmp = NULL;
            }
        }
    }
}
