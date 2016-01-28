//Dennis Ott
//Jan-Tjorve Sobieski
//Praktikum 10

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
/* Prototypen fuer Aufgaben */

char** initList(size_t size);
void freeList(char** list, size_t size);
void printList(char** list, size_t size);
void addList(char** list, size_t size, char* name);


/** Aufgabe 1
* Erstellt eine Teilnehmerliste mit size Eintraegen fuer Teilnehmer
* Alle Eintraege werden mit NULL initialisiert
* @param size Groesse der Liste
* @return Zeiger auf den ersten Eintrag der Liste
*/
char** initList(size_t size) {
	//legt speicherplatz an und schreibt NULL rein
	char** chrptr = (char**)calloc(size,sizeof(char*));
	//return 
	return chrptr;
}

/** Aufgabe 2
* Gibt den Speicher einer Teilnehmerliste wieder frei.
* Dazu gibt die Funktion zuerst den Speicher fuer alle Eintraege und dann
* den Speicher fuer die Liste wieder frei
@param size Groesse der Liste
*/
void freeList(char** list, size_t size) {
	size_t i = 0;
	if (list == NULL) return;
	//gibt Speicherplatz wieder frei
	for (i = 0; i < size; i++) {
			free(list[i]);
	}
	free(list);
}

/** Aufgabe 3
* Gibt die Liste auf der Konsole aus
* @param list Teilnehmerliste
* @param size Groesse der Liste
*/
void printList(char** list, size_t size) {
	size_t i = 0;
	//Schleife fuer Ausgabe
	if (list == NULL) return;
	for (i = 0; i < size; i++) {
		if (list[i] != NULL)
			printf("%s\n", list[i]);
	}
}

/** Aufgabe 4
* Fuegt einen Teilnehmer zur Liste hinzu
* Dazu ist der uebergebene String zu kopieren
* Denken Sie an Problemfaelle
* @param list Teilnehmerliste
* @param size Groesse der Liste
* @param name Name des Teilnehmers
*/

void addList(char** list, size_t size, char* name) {
	size_t i = 0;
	char* upperName = (char*)calloc(strlen(name)+1, sizeof(char));
	// Praesenzaufgabe 
	if (isalpha(name))
		while (name[i]) { // dirty hack!!!
			upperName[i] = toupper(name[i]);
			i++;
		}
	// for schleife zum adden in die Liste
	if (list == NULL) return EXIT_FAILURE;
	for (i = 0; i < size; i++) {
		if (list[i] == NULL) {
			list[i] = (char*)calloc(strlen(name) + 1, sizeof(char));
			strcpy(list[i], upperName);
			break;
		}
	}
}