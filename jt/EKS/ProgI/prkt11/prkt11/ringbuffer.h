/*
* ringbuffer.h
*
*  Created on: 03.06.2014
*      Author: ansch
*/

#ifndef RINGBUFFER_H_
#define RINGBUFFER_H_

#include <stddef.h>
#include <stdio.h>
#include <string.h>

typedef struct ringbuffer_ {
	size_t size; // Groesse des Puffers
	size_t count;// Anzahl der Elmente im Puffer
	size_t head; // Index des vordersten Elements
	size_t tail; // Index des hintersten Elements
	char* data; // Zeiger auf den Puffer
	// data wird durch malloc auf dem Heap
	// angelegt.
} ringbuffer;

/**
* Initialisiert einen Rinbbuffer und alloziert Speicher.
* @param size Groesse des Ringbuffer
* @return Zeiger auf Ringbuffer
*/
ringbuffer* rbinit(size_t size);

/**
* Fuegt ein Element in den Puffer am Ende ein. Falls die
* Queuebereits voll ist, wird das Element nicht eingefuegt.
* @param buffer Rinbuffer in den eingefuegt werden soll
* @param item Einzufuegendes Element
* @return true falls die Operation erfolgreich war, false sonst
*/
int rbput(ringbuffer* buffer, char item);

/**
* Entfernt ein Element am Anfang des Ringbuffers
* Falls der Ringbuffer leer ist, liefert die Funktion 0.
* @param buffer Ringbuffer
* @return Erstes Element
*/
char rbget(ringbuffer* buffer);

/**
* Gibt den reservierten Speicher wieder frei.
* @param buffer
*/
void rbfree(ringbuffer* buffer);

////////////////////////////////////////////////////////////
//Implementierung

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
		ringbuffer* rb = malloc(sizeof(ringbuffer));		 // alloziert Speicher fuer struct
		rb -> data = (char*)malloc(sizein * sizeof(char));   // alloziert Speicher fuer Array
		memset(rb -> data, '_', sizein);					 // memset fuer schoeneres Printen auf der Konsole
		rb -> size = sizein;								 // Setzen von size in der Struct
		rb->data[sizein] = '\0';							 // Setzen des Nullterminators 
		rb->count = 0;
		rb->head = 0;
		rb->tail = 0;
		return rb;
}

/**
* Fuegt ein Element in den Puffer am Ende ein. Falls die
* Queue bereits voll ist, wird das Element nicht eingefuegt.
* @param buffer Rinbuffer in den eingefuegt werden soll
* @param item Einzufuegendes Element
* @return true falls die Operation erfolgreich war, false sonst
*/
int rbput(ringbuffer* buffer, char item) {
	//Case fuer Buffer mit Inhalt und nicht Voll

	//Case fuer komplett leeren buffer
	for (size_t i = buffer->size -1; i >= 0; i--) {
		if (i == 0 && buffer->data[i] != '_') {
			return 0;
		}
		else if(buffer->data[i] == '_'){
			buffer->head = buffer->size - 1;
			buffer->data[i] = item;
			buffer->count++;
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
	if (buffer->data[buffer->size - 1] == '_') return 0;
	char c = buffer->data[buffer->head];
	buffer->data[buffer->head] = '_';
	for (int i = buffer->size - 1; i > 0; i--) {
		buffer->data[i] = buffer->data[i - 1];
	}
	buffer->data[buffer->tail] = '_';
	return c;
}

/**
* Gibt den reservierten Speicher wieder frei.
* @param buffer
*/
void rbfree(ringbuffer* buffer) {
	//free(buffer->data);
	free(buffer);
}

/**
* Returnt den Data buffer an die Main
* @param buffer
*/
char* rbprint(ringbuffer* buffer) {
	return buffer->data;
}

#endif /* RINGBUFFER_H_ */
