/** @file
 *
 * Verwaltung einer Playlist
 *
 *  @date 27.05.2014
 *  @author: ansch
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

/**
 * Liest einen Eintrag von der Konsole ein und fuegt ihn in die Playlist ein.
 * @param list Playlist
 * @param count Anzahl der in der Liste gespeicherten Eintraege
 * @param capacity Kapazitaet (Groesse) der Liste
 */
void addItem(char** list, int* count, int capacity);

/**
 * Liest einen Eintrag von der Konsole ein und loescht ihn aus der Playlist.
 * @param list Playlist
 * @param count Anzahl der in der Liste gespeicherten Eintraege
 */
void deleteItem(char** list, int* count);

int main(void) {
	char** list; //Array von Zeichenketten - die Playlist
	int count = 0; //Anzahl der Eintraege in der Playlist
	int capacity = 3; // Kapazitaet des Array

	list = calloc(capacity, sizeof(char*)); // Speicher fuer das Array auf dem Heap allozieren
	char menusel = 0;
	do {
		printf("1 Titel hinzufuegen\n");
		printf("2 Titel entfernen\n");
		printf("3 Liste ausgeben\n");

		printf("X Ende\n");
		menusel = getchar();
		while (getchar() != '\n')
			;
		if (menusel == '1')
			addItem(list, &count, capacity);
		if (menusel == '2')
			deleteItem(list, &count);
		if (menusel == '3')
			listprint(list, count);
	} while (menusel != 'X');
	listfreeallitems(list, count); // Alle Elemente des Arrays loeschen und Speicher freigeben
	free(list); // Speicher fuer das Array freigeben
	return 0;
}

void addItem(char** list, int* count, int capacity) {
	char buffer[80];
	printf("Titel: ");
	fgets(buffer, 80, stdin);
	strtok(buffer, "\n");
	if (!(listadditem(list, buffer, count, capacity)))
		printf("Fehler\n");
}

void deleteItem(char** list, int* count) {
	char buffer[80];
	printf("Titel: ");
	fgets(buffer, 80, stdin);
	strtok(buffer, "\n");
	if (!listdeleteitem(list, buffer, count))
		printf("Fehler\n");
}
