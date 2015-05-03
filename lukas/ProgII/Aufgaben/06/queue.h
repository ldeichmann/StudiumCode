/** @file
 * queue.h
 * Queue von Zeichenketten durch verkettete Liste realisiert.
 *
 *  Created on: 10.06.2014
 *  @author ansch
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include "tasks.h"
/**
 * Knoten in verketteter Liste
 */
typedef struct tasklistnode_ {
	Task task;
	char taskname[20];
	struct tasklistnode_* next;
} TaskListNode;

typedef TaskListNode* TaskListNodePtr;

/**
 * Queue mit Head / Tail Pointer
 */
typedef struct queue_ {
	TaskListNodePtr head;
	TaskListNodePtr tail;
} Queue;

typedef Queue* QueuePtr;

/**
 * Initialisiert eine Queue. Legt leere Instanz von Queue auf Heap an
 * und liefert Pointer darauf. (10 Punkte)
 * @return Leere Queue
 */
QueuePtr initQueue();

/**
 * Fuegt einen Task hinten in die Queue ein. Ein Zeiger auf die Funktion und eine
 * Zeichenketter fuer den Namen des Task werden dazu in die Queue eingefuegt.
 * Die Zeichenkette wird dazu kopiert. Zu diesem Zweck wird neu ein TaskListNode auf
 * dem Heap angelegt und an die Queue angehaegt. (10 Punkte)
 * @param queue Queue zu der das Element hinzuzufuegen ist
 * @param task Zu speichernder Task
 * @param taskName Textuelle Beschreibung des Task
 */
void enqueue(QueuePtr queue, Task task, char* taskName);

/**
 * Entfernt einen Task Zeichenkette vorne aus der Queue und fuehrt ihn aus.
 * Dem auszufuehrenden Task wird dabei immer die id 42 als Parameter uebergeben
 * Die Beschreibung des ausgefuehrten Task wird in dem uebergebenen Zielpuffer gespeichert.
 * Der Puffer muss mindestens Platz fuer 20 Zeichen besitzen (10 Punkte)
 * @param queue Queue aus der das Element entfernt werden soll
 * @param dest Zielpuffer fuer die Beschreibung des ausgefuehrten Task
 */
void dequeue(QueuePtr queue, char* taskName);

/**
 * Gibt den Speicher der Queue wieder frei. (10 Punkte)
 * @param queue Freizugebende Queue
 */
void destroyQueue(QueuePtr queue);

/**
 * TODO Dokumentation (Zusammen 10 Punkte)
 * @param queue
 */
void printQueue(QueuePtr queue);
#endif /* QUEUE_H_ */
