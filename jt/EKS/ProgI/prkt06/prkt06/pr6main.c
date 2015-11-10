/** Hauptprogramm fuer vierte Praktikumsaufgabe
* Programmierung 1
*/

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stddef.h>
/* Prototypen fuer Aufgaben */

/** Aufgabe 1
* durchsucht Array nach vorgegebenem Element
* @param elem zu suchendes Element
* @param a zu durchsuchendes Feld
* @param size Groesse des Feldes
* @return 0 falls nicht gefunden, 1 sonst
*/

int find(int elem, const int a[], size_t size);


/** Aufgabe 2
* durchsucht rekursiv ein Array nach vorgegebenem Element und prueft, ob es
* mindestens numOcc mal vorhanden ist.
* @param elem zu suchendes Element
* @param numOcc minimale Anzahl an Vorkommen des Elements elem in a
* @param a zu durchsuchendes Feld
* @param size Groesse des Feldes
* @return 0 falls nicht gefunden, 1 sonst
*/

int findRecN(int elem, size_t numOcc, const int a[], size_t size);

/** Aufgabe 3
* addiert zu jedem Element des Arrays 42
* @param a Array
* @param size Groesse des Feldes
*/

void fortyTwo(int a[], size_t size);

/** Aufgabe 4
* Dreht eine Zeichenkette um
* @param a Zeichenkette, die umgedreht werden soll
*/

void rev(char a[]);

/** Aufgabe 5
* Kopiert den Inhalt von einem Quell- in ein Zielfeld.
* @param src Quellfeld
* @param dst Zielfeld
* @param size Groesse des Feldes
*/


/* Nutzerschnittstelle fuer die Aufgaben */


#define MAX_TASKS 4


void a1();
void a2();
void a3();
void a4();


void(*a[MAX_TASKS])() = { a1, a2, a3, a4 };
char *name[MAX_TASKS] = { "Find", "FindRecN", "42", "Rev" };

/* Auswahlmenu */

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

void printIntArray(int a[], size_t size){
	size_t i = 0;
	for (i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void readIntArray(int a[], size_t size){
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

void a1()
{
	int elem = 0;
	char buffer[21];
	int a[30] = { 1, -1, 42, 23, 1, 17, -18 };
	printf("Find\n");
	readIntArray(a, 30);
	printIntArray(a, 30);
	printf("Element:");
	gets_s(buffer, 21);
	sscanf(buffer, "%d", &elem);
	if (find(elem, a, 30))
		printf("Gefunden!");
	else
		printf("Nicht gefunden!");

}

void a2()
{
	int elem = 0;
	int numOcc = 0;
	char buffer[21];
	int a[30] = { 1, -1, 42, 23, 1, 17, -18, 1, 1, 42 };
	printf("FindRecN\n");
	readIntArray(a, 30);
	printf("Element:");
	gets_s(buffer, 21);
	sscanf(buffer, "%d", &elem);
	printf("Anzahl:");
	gets_s(buffer, 21);
	sscanf(buffer, "%d", &numOcc);
	if (findRecN(elem, numOcc, a, 30))
		printf("Gefunden!");
	else
		printf("Nicht gefunden!");
}


void a3()
{
	int elem = 0;
	int a[30] = { 1, -1, 42, 23, 1, 17, -18 };
	printf("42\n");
	printf("Feld (max. 30):\n");
	readIntArray(a, 30);
	fortyTwo(a, 30);
	printIntArray(a, 30);
}

void a4()
{
	char input[81] = "Test";
	printf("Rev\n");
	printf("Eingabestring:\n");
	gets_s(input, 81);
	rev(input);
	printf("Rev: %s", input);
}
