#include "ringbuffer.h"
#include <stdio.h>
#include <ctype.h>

typedef	ringbuffer* RingBuffer; //typedef fuer struct

int main(void) {

	RingBuffer rb = NULL; // Ringbuffer anlegen
	char buffer[21]; //Buffer fuer input
	int buffersize = 0; //size fuer bufferinit
	char input = NULL; // char input fuer rbput
	char cget = NULL; // char variable fuer rbget

	char c = NULL; // Switch Variable

	while (c != 'e') {
		printf(" (i) for init \n (+) for input \n (-) for output \n (e) for escape \n\n :> "); 
		gets_s(buffer, 21); // Eingabe Auswahlmoeglichkeit
		sscanf(buffer, "%c", &c);

		switch (c) {

		case 'i': // Initcase
			printf("\nRingbuffer Length: ");
			gets_s(buffer, 21);
			sscanf(buffer, "%d", &buffersize);
			rb = rbinit(buffersize);
			printf("\nBuffer wurde erfolgreich angelegt\n");
			break;

		case '+': // Ringbuffer Put case

			while (!isupper(input)) { // Eingabe eines Char-Elements
				printf("\nInput: ");
				gets_s(buffer, 21);
				sscanf(buffer, "%c", &input);
			}

			if (rbput(rb, input) != 0) { // Wenn rbput erfolgreich war
				input = NULL;
				break;
			}
			else { // Wenn rbput nicht erfolgreich war
				printf("Fehler, Ringbuffer ist voll\n");
				break;
			}

		case '-': // Ringbuffer Get case
			if ((cget = rbget(rb)) != 0) { //Wenn rbget erfolgreich war
				printf("\nFirst Element removed is %c \n", cget);
				break;
			}
			else { // Wenn rbget nicht erfolgreich war
				printf("\nRingbuffer leer\n");
				break;
			}
			
			////////////////////////////////////////////////
			//Testcases
		
		case 'p':
			printf("buffer: %s \n", rbprint(rb));
			break;

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