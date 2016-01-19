/*
* ringbuffer.h
* Dennis Ott
* Jan-Tjorve Sobieski
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

#endif /* RINGBUFFER_H_ */
