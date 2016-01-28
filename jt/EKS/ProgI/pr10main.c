/** Hauptprogramm fuer 10. Praktikumsaufgabe
* Programmierung 1
*/

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
/* Prototypen fuer Aufgaben */

/** Aufgabe 1
* Erstellt eine Teilnehmerliste mit size Eintraegen fuer Teilnehmer
* Alle Eintraege werden mit NULL initialisiert
* @param size Groesse der Liste
* @return Zeiger auf den ersten Eintrag der Liste
*/
char** initList(size_t size);

/** Aufgabe 2
* Gibt den Speicher einer Teilnehmerliste wieder frei.
* Dazu gibt die Funktion zuerst den Speicher fuer alle Eintraege und dann
* den Speicher fuer die Liste wieder frei
* @param size Groesse der Liste
*/
void freeList(char** list, size_t size);

/** Aufgabe 3
* Gibt die Liste auf der Konsole aus
* @param list Teilnehmerliste
* @param size Groesse der Liste
*/
void printList(char** list, size_t size);

/** Aufgabe 4
* Fuegt einen Teilnehmer zur Liste hinzu
* Dazu ist der uebergebene String zu kopieren
* Denken Sie an Problemfaelle
* @param list Teilnehmerliste
* @param size Groesse der Liste
* @param name Name des Teilnehmers
*/

void addList(char** list, size_t size, char* name);

/* Nutzerschnittstelle fuer die Aufgaben */


#define MAX_TASKS 4


void a1();
void a2();
void a3();
void a4();


void(*a[MAX_TASKS])() = { a1, a2, a3, a4 };
char *name[MAX_TASKS] = { "Liste anlegen", "Liste freigeben", "Liste ausgeben", "Name hinzufuegen" };

/* Auswahlmenu */

char** list;

char menu() {
	int i = 0;
	char selection = 0;
	printf("\n");
	for (i = 0; i < MAX_TASKS; i++)
		printf("%d) Aufgabe %d (%s)\n", i + 1, i + 1, name[i]);
	printf("s) Stop");
	selection = getchar();
	while (getchar() != '\n');
	return selection;
}

int main(void)
{
	char selection;
	while ((selection = menu()) != 's') {
		if ('1' <= selection && selection < '1' + MAX_TASKS)
			a[selection - '1']();
	}
}

void printIntArray(int a[], size_t size) {
	size_t i = 0;
	for (i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void readIntArray(int a[], size_t size) {
	size_t i;
	char buffer[81];
	for (i = 0; i < size; i++)
		a[i] = 0;
	printf("Eingabe eines Feldes mit max %d Elementen (Leerzeile fuer Ende): \n", size);
	i = 0;
	do {
		gets_s(buffer, 81);
	} while ((sscanf(buffer, "%d", &a[i]) == 1) && ++i < size);

}

void a1(){
	if (NULL == (list = initList(30)))
		exit(EXIT_FAILURE);
}

void a2(){
	freeList(list, 30);
}

void a3(){
	printList(list, 30);
}

void a4() {
	char buffer[40];
	printf("Name: ");
	gets_s(buffer, 40);
	addList(list, 30, buffer);
}
