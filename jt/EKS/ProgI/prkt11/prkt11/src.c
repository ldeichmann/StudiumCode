#include "ringbuffer.h"
#include <stdio.h>
#include <ctype.h>

typedef	ringbuffer* RingBuffer;

int main(void) {

	RingBuffer rb = NULL;
	char buffer[21];
	int buffersize = 0;
	char input = NULL;
	char cget = NULL;

	char c = NULL;

	while (c != 'e') {
		printf(" (i) for init \n (+) for input \n (-) for output \n (e) for escape \n\n :> ");
		gets_s(buffer, 21);
		sscanf(buffer, "%c", &c);

		switch (c) {

			case 'i':
				printf("\nRingbuffer Length: ");
				gets_s(buffer, 21);
				sscanf(buffer, "%d", &buffersize);
				rb = rbinit(buffersize);
				printf("\nBuffer wurde erfolgreich angelegt\n");
				break;

			case '+':
				while (!isupper(input)) {
					printf("\nInput: ");
					gets_s(buffer, 21);
					sscanf(buffer, "%c", &input);
				}

				if (rbput(rb, input) != 0) {
					input = NULL;
					break;
				}
				else {
					printf("Fehler, Ringbuffer ist voll\n");
					break;
				}

			case '-':
				if ((cget = rbget(rb)) != 0) {
					printf("\nFirst Element removed is %c \n", cget);
					break;
				}
				else {
					printf("\nRingbuffer leer\n");
					break;
				}

			case 'p':
				printf("buffer: %s \n", rbprint(rb));
				break;

			////////////////////////////////////////////////
			//Testcases

			case 'h':
				printf("head: %d \n", rb->head);
				break;

			case 't':
				printf("tail: %d \n", rb->tail);
				break;

			case 'c':
				printf("count: %d \n", rb->count);
				break;

			case 's':
				printf("size: %d \n", rb->size);
				break;

			default:
				printf(" (i) for init \n (+) for input \n (-) for output \n (e) for escape \n\n :> ");
				break;
		}
	}
	rbfree(rb);

	return 0;
}