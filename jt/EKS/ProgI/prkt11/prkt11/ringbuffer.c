//Dennis Ott
//Jan-Tjorve Sobieski
//Prkt11

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "ringbuffer.h"

//typedef struct ringbuffer_ {
//	size_t size; // Groesse des Puffers
//	size_t count;// Anzahl der Elmente im Puffer
//	size_t head; // Index des vordersten Elements
//	size_t tail; // Index des hintersten Elements
//	char* data; // Zeiger auf den Puffer
//	// data wird durch malloc auf dem Heap
//	// angelegt.
//} ringbuffer;


/**
* Initialisiert einen Rinbbuffer und alloziert Speicher.
* @param size Groesse des Ringbuffer
* @return Zeiger auf Ringbuffer
*/
ringbuffer* rbinit(size_t sizein) {
	ringbuffer* rb = malloc(sizeof(ringbuffer)); // alloziert Speicher fuer struct
	rb->data = (char*)malloc(sizein * sizeof(char)); // alloziert Speicher fuer Array
	memset(rb->data, '_', sizein); // memset fuer schoeneres Printen auf der Konsole
	rb->size = sizein; // Setzen von size in der Struct
	rb->data[sizein] = '\0'; // Setzen des Nullterminators 
	rb->count = 0; //Setzen der Struct Variablen							
	rb->head = 0;
	rb->tail = 0;
	return rb; // return des neu angelegten Buffers
}

/**
* Fuegt ein Element in den Puffer am Ende ein. Falls die
* Queue bereits voll ist, wird das Element nicht eingefuegt.
* @param buffer Rinbuffer in den eingefuegt werden soll
* @param item Einzufuegendes Element
* @return true falls die Operation erfolgreich war, false sonst
*/
int rbput(ringbuffer* buffer, char item) {
	for (size_t i = buffer->size - 1; i >= 0; i--) { // Abfrage ob Ringbuffer voll ist
		if (i == 0 && buffer->data[i] != '_') {
			return 0;
		}
		else if (buffer->data[i] == '_') { //Einfuegen des neuen Charackters
			buffer->head = buffer->size - 1;
			buffer->data[i] = item; 
			buffer->count++; //Neu setzten der Struct-Variablen
			buffer->tail = i;
			return 1;
		}
	}
	return 0;
}

/**
* Entfernt ein Element am Anfang des Ringbuffers
* Falls der Ringbuffer leer ist, liefert die Funktion 0.
* @param buffer Ringbuffer
* @return ErstesElement
*/
char rbget(ringbuffer* buffer) {
	if (buffer->data[buffer->size - 1] == '_') return 0; //Abfrage ob Ringbuffer leer ist
	char c = buffer->data[buffer->head]; // auslesen des Ersten Elements
	buffer->data[buffer->head] = '_'; //Neusetzen des Ersten Elements
	for (int i = buffer->size - 1; i > 0; i--) {
		buffer->data[i] = buffer->data[i - 1]; //Verschieben der size-1 Elemente nach links 
	}
	buffer->data[buffer->tail] = '_'; //Neusetzen des letzten Elements auf "freies" Element
	return c; // Return des Ersten Elements
}

/**
* Gibt den reservierten Speicher wieder frei.
* @param buffer
*/
void rbfree(ringbuffer* buffer) {
	free(buffer); //Gibt die Struct wieder frei
}

/**
* Returnt den Data buffer an die Main
* @param buffer
*/
char* rbprint(ringbuffer* buffer) {
	return buffer->data; //Help Funktion zur Ausgabe der Queue
}