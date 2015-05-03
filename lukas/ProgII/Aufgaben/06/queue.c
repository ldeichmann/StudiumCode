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

    Queue* q = (Queue*) malloc(sizeof(Queue));
    QueuePtr qPtr = q;
    return qPtr;

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

    TaskListNode* t = (TaskListNode*) malloc(sizeof(TaskListNode));
    TaskListNodePtr tPtr = t;
    (*t).task= task;
    strcpy((*t).taskname, taskName);
    (*t).next = NULL;

    if (queue->tail) {
        queue->tail->next = tPtr;
        queue->tail = tPtr;
    } else {
        queue->tail = tPtr;
        queue->head = tPtr;
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

    if (queue->head) {

        (queue->head->task(42));
        strcpy(taskName, queue->head->taskname);
        if (queue->head->next) {
            TaskListNodePtr tPtr = queue->head->next;
            free(queue->head);
            queue->head = tPtr;
        } else {
            free(queue->head);
            queue->head = NULL;
            queue->tail = NULL;
        }
    } else {
        printf("Queue empty!\n");
    }

}

/**
 * Gibt den Speicher der Queue wieder frei. (10 Punkte)
 * @param queue Freizugebende Queue
 */
void destroyQueue(QueuePtr queue) {

    if (queue->head != 0) {
        TaskListNodePtr current = queue->head;
        TaskListNodePtr next;
        if (queue->head->next != 0) {
            next = queue->head->next;
        }

        while (current != 0) {

            free(current);
            if (next != 0) {
                current = next;
                if (current->next != 0) {
                    next = current->next;
                }
            }

        }
    }

    free(queue);
}

/**
 * TODO Dokumentation (Zusammen 10 Punkte)
 * @param queue
 */
void printQueue(QueuePtr queue) {

    if (queue->head) {
        TaskListNodePtr current = queue->head;
        TaskListNodePtr next = NULL;
        if (queue->head->next) {
            next = queue->head->next;
        }

        while ( current ) {
            printf("%s\n", current->taskname);
            if (next) {
                current = next;
                if (current->next) {
                    next = current->next;
                } else {
                    next = NULL;
                }
            } else {
                current = NULL;
            }

        }

    }

}