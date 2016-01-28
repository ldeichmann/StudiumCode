#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

typedef struct listnode_ {
	int data;
	struct listnode_* next;
} Listnode;

int counta(char s[]);
int sumArray(int values[], size_t count);
void applyFkt(int values[], size_t count, int(*fkt) (int));
int countAFile(char* filename);
double avgList(Listnode* head);
Listnode* addFront(Listnode* head, int item);
void freeList(Listnode* head);

/* Es folgen die Aufgaben */
// **************************


// Aufgabe 1 (10 Punkte)

/**
* Bestimmt die Anzahl der Vorkommen des Buchstabens 'a' in der
* Zeichenkette s
* @param s Zeichenkette
* @return Anzahl der Vorkommen von 'a'
*/
int counta(char s[])
{
	int c = 0;
	for (size_t i = 0; i < strlen(s); i++) {
		if (s[i] == 'a') c++;
	}
	return c;
}


// Aufgabe 2 (15 Punkte)

/**
* Bestimmt die Summe der Elemente im uebergebenen Array
* @param values Array der zu summierenden Elemente
* @param count Anzahl der Elemente in dem Array values
* @return Summe der Elemente
*/
int sumArray(int values[], size_t count)
{
	int summe = 0;
	for (size_t i = 0; i < count; i++) {
		summe += values[i];
	}
	return summe;
}


// Aufgabe 3 (15 Punkte)

/**
* Wendet auf jedes Element eines int-Arrays eine Funktion an und
* ersetzt das Element durch den Rueckgabewert der Funktion.
* @param values Array von int-Werten
* @param count Anzahl der Elemente in values
* @param fkt Funktionspointer auf die anzuwendende Funktion
*/
void applyFkt(int values[], size_t count, int(*fkt) (int))
{
	for (size_t i = 0; i < count; i++) {
		values[i] = fkt(values[i]);
	}
}


// Aufgabe 4 (20 Punkte)

/**
* Die Funktion ermittelt die Anzahl der 'a' oder 'A' in der
* uebergebenen Datei.
* Dazu oeffnet die Funktion die Datei mit fopen
* liest die Datei zeichenweise mit fgetc ein bis das Ergebnis
* EOF ist und schliesst die Datei mit fclose
* @param filename Dateiname
* @return Anzahl der 'A'/'a' in der Datei
*/
int countAFile(char* filename)
{	
	char c = NULL;
	int i = 0;
	FILE *fp = fopen(filename, "w+");
	while (c != EOF) {
		c = fgetc(fp);
		if (c == 'A' || c == 'a') i++;
	}
	return c;
}

// Aufgabe 5 (20 Punkte)

/**
* Bestimmt den Durchschnittswert der in der verketteten Liste
* gespeicherten Werte.
* @param head Zeiger auf das erste Element der Liste
* @return Durchschnitt der gespeicherten Werte.
*/
double avgList(Listnode* head)
{
	int i = 0;
	double c = 0;
	while (head) {
		c += head->data;
		head = head->next;
		i++;
	}
	return c/i;
}

// Aufgabe 6 (20 Punkte)

// Ein Reiseplan soll in C verwaltet werden
// Erstellen Sie einen typedef Station fuer eine Struktur,
// die eine Station auf der Reise abbildet.
// In der Stuktur sollen Reisetag und Reiseziel
// enthalten sein.
// Erstellen Sie eine Funktion mkSt(tag, ziel), die eine solche Struktur
// auf dem Heap erzeugt und die Eintraege der Struktur den Parametern
// entsprechend fuellt. Die Funktion soll dann einen Zeiger auf die
// Struktur zurueckgeben.

typedef struct reiseplan_{
	char *reisetag;
	char *reiseziel;
} Reiseplan;

typedef Reiseplan* reiseplan;

Reiseplan* mkSt(char* tag, char* ziel) {
	reiseplan rp = (reiseplan)malloc(sizeof(reiseplan));
	rp->reisetag = malloc(sizeof(tag) / sizeof(char));
	rp->reiseziel = malloc(sizeof(ziel) / sizeof(char));

	strcpy(rp->reisetag, tag);
	strcpy(rp->reiseziel, ziel);
	
	return rp;
}

// Ende der Aufgaben

Listnode* addFront(Listnode* head, int item)
{
	Listnode* newHead = (Listnode*)malloc(sizeof(Listnode));
	newHead->next = head;
	newHead->data = item;
	return newHead;
}

void freeList(Listnode* head)
{
	if (head == NULL)
		return;
	freeList(head->next);
	free(head);
}

int quad(int x)
{
	return x*x;
}


int main(void)
{
	char s[] = "analysis";
	int v[] = { 1, 6, -3, 6, 0 };
	int i = 0;
	Listnode* head = NULL;
	printf("%s %d\n", s, counta(s));
	printf("%d = %d\n", 10, sumArray(v, sizeof(v) / sizeof(int)));
	for (i = 0; i < sizeof(v) / sizeof(int); i++)
		printf("%d ", v[i]);
	printf(" == quad ==> ");
	applyFkt(v, sizeof(v) / sizeof(int), quad);
	for (i = 0; i < sizeof(v) / sizeof(int); i++)
		printf("%d ", v[i]);
	printf("\n");
	for (i = 0; i < sizeof(v) / sizeof(int); i++)
		head = addFront(head, v[i]);
	printf("Durchschnitt %f\n", avgList(head));
	freeList(head);

	Reiseplan* rp = mkSt("01.12.2016", "Eutin");
	printf("\n%s %s\n", rp->reisetag, rp->reiseziel);
	return EXIT_SUCCESS;
}
