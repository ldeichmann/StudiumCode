/** Hauptprogramm fuer vierte Praktikumsaufgabe
* Programmierung 1
*/

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stddef.h>
/* Prototypen fuer Aufgaben */

/** Aufgabe 1
* addiert zwei Zahlen
* @param a Zeiger auf ersten Summanden
* @param b Zeiger auf zweiten Summanden
* @return Summe der Summanden
*/
int add(int* a, int* b);


/** Aufgabe 2
* Findet den Anfang des ersten Wortes in der Zeichenkette s
* Liefert einen Zeiger auf den ersten Buchstaben innerhalb von s und ueberliest alle Leerzeichen davor
* Fuer "   Hallo" liefert die Funktionen einen Zeiger auf das H.
* @param s
* @return Zeiger auf das erste Zeichen in s, das kein Leerzeichen ist
*/
char* trim(const char s[]);

/** Aufgabe 3
* Erstellt eine Abkuerzung zu einer Zeichenkette s
* Federation Internationale Football Association  -> FIFA
* @param s Langform der Zeichenkette
* @param a Zielpuffer fuer die Abkuerzung
* @param size Groesse des Zielpuffers
*/
void abbrev(const char s[], char a[], size_t size);

/* Nutzerschnittstelle fuer die Aufgaben */


#define MAX_TASKS 3


void a1();
void a2();
void a3();



void(*a[MAX_TASKS])() = { a1, a2, a3 };
char *name[MAX_TASKS] = { "Add", "Trim", "Abbrev" };

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
	int a = 3;
	int b = 42;
	printf("%d + %d = %d", a, b, add(&a, &b));
}

void a2()
{
	char buffer[81];
	printf("Eingabe:");
	gets_s(buffer, 81);
	printf("getrimmt:%s\n", trim(buffer));
}


void a3()
{

	char inputString[81];
	char abrString[81];
	printf("Eingabe:");
	gets_s(inputString, 81);
	abbrev(inputString, abrString, 81);
	printf("%s -> %s\n", inputString, abrString);
}
