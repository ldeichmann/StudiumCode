/**@file
 * 	Prototyp Uhrenbetriebssystem
 *
 *  */

#include <stdio.h>
#include <string.h>
#include "queue.h"
#include "tasks.h"

int main(void) {
	QueuePtr queue = initQueue();
	char buffer[20];
	char sel = 0;
	while (sel != 'X') {
		printf("+++ Queue +++\n");
		printQueue(queue);
		printf("++++++\n");
		printf("1) Enqueue printID\n");
		printf("2) Enqueue printHello\n");
		printf("3) Enqueue printDate\n");
		printf("4) Dequeue and execute\n");
		printf("X) Exit\n");
		sel = getchar();
		while (getchar() != '\n')
			;
		switch (sel) {
		case '1':
			enqueue(queue, printID, "printID");
			break;
		case '2':
			enqueue(queue, printHello, "printHello");
			break;
		case '3':
			enqueue(queue, printDate, "printDate");
			break;
		case '4':
			dequeue(queue, buffer);
			printf("Executed: %s\n", buffer);
		}
	}
	return 0;
}
