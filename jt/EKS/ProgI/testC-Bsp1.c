#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

typedef struct listnode_ {
	int data;
	struct listnode_* next;
} Listnode;

char findMax(char s[]);
double avgArray(int values[], size_t count);
int exists(int values[], size_t count, int (*fkt)(int));
int capsFile(char* filename);
int maxList(Listnode* head);
Listnode* addFront(Listnode* head, int item);
void freeList(Listnode* head);
int is42(int x);

/* Es folgen die Aufgaben */
// **************************

// Aufgabe 1 (15 Punkte)
/**
 * Bestimmt den haeufigsten Buchstaben in der Zeichenkette s
 * @param s Zeichenkette
 * @return Haeufigster Buchstabe in s
 */
char findMax(char s[]) {

}

// Aufgabe 2 (10 Punkte)

/**
 * Bestimmt den Durchschnittswert der Elemente im uebergebenen Array
 * @param values Array der zu summierenden Elemente
 * @param count Anzahl der Elemente in dem Array values
 * @return Durchschnittswert der Elemente
 */
double avgArray(int values[], size_t count) {

}

// Aufgabe 3 (15 Punkte)

/**
 * Wendet auf jedes Element eines int-Arrays eine Funktion an. Die angewendete
 * Funktion muss fuer jedes Element des int-Array 0 (falsch) oder 1 (wahr) liefern.
 * Falls die angewendete Funktion fuer ein Array-Element (wahr) 1 liefert, dann liefert
 * die exists auch wahr. Andernfalls liefert exists falsch.
 * Hinweis: is42 waere eine moegliche solche Funktion fkt.
 * @param values Array von int-Werten
 * @param count Anzahl der Elemente in values
 * @param fkt Funktionspointer auf die anzuwendende Funktion
 * @return 1 falls fkt fuer ein Elemet wahr liefert und 0 sonst.
 */
int exists(int values[], size_t count, int (*fkt)(int)) {

}

// Aufgabe 4 (20 Punkte)

/**
 * Die Funktion ermittelt ob die Anzahl der Grossbuchstaben oder der Kleinbuchstaben
 * in der uebergebenen Datei groesser ist.
 * Dazu oeffnet die Funktion die Datei mit fopen
 * liest die Datei zeichenweise mit fgetc ein bis das Ergebnis
 * EOF ist und schliesst die Datei mit fclose
 * Hinweis: Umlaute / Sonderzeichen koennen wie immer unberuecksichtigt bleiben
 * @param filename Dateiname
 * @return wahr falls es mehr Grossbuchstaben als Kleinbuchstaben gibt, falsch sonst
 */
int capsFile(char* filename) {

}

// Aufgabe 5 (20 Punkte)

/**
 * Bestimmt den maximalen Wert der in der verketteten Liste
 * gespeicherten Werte.
 * @param head Zeiger auf das erste Element der Liste
 * @return Maximaler Wert in Liste falls Liste nicht leer und INT_MIN sonst.
 */
int maxList(Listnode* head) {

}

// Aufgabe 6 (20 Punkte)

// Eine Pruefungsliste soll in C verwaltet werden
// Erstellen Sie einen typedef Pruefung fuer eine Struktur.
// In der Stuktur sollen das Fach und seine Note
// enthalten sein.
// Erstellen Sie eine Funktion mkPr(fach, note), die eine solche Struktur
// auf dem Heap erzeugt und die Eintraege der Struktur den Parametern
// entsprechend fuellt. Die Funktion soll dann einen Zeiger auf die
// Struktur zurueckgeben.

// Aufgabe 7 (20 Bonuspunkte)

/**
 * Die Funktion mix mischt zwei Zeichenketten fair. Aus Christiane und Max wird
 * CMharxistiane.
 * @param src1 Erster zu mischender String
 * @param src2 Zweiter zu mischender String
 * @param dest Zielpuffer fuer das Ergebnis.
 * Der Puffer muss mindestens strlen(src1) + strlen(src2) + 1 Zeichen
 * aufnehmen koennen.
 */
void mix(char* src1, char* src2, char* dest) {

}

// Ende der Aufgaben
// Die folgenden Hilfsfunktionen koennen Ihnen helfen, falls
// Sie Ihren Code testen moechten.

Listnode* addFront(Listnode* head, int item) {
	Listnode* newHead = (Listnode*) malloc(sizeof(Listnode));
	newHead->next = head;
	newHead->data = item;
	return newHead;
}

void freeList(Listnode* head) {
	if (head == NULL)
		return;
	freeList(head->next);
	free(head);
}

int is42(int x) {
	return x == 42;
}

int main(void) {

}
