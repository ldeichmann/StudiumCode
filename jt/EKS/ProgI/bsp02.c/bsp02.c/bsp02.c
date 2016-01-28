#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

typedef struct listnode_ {
	int data;
	struct listnode_* next;
} Listnode;

//typedef Listnode* listnode;

char findMax(char s[]);
double avgArray(int values[], size_t count);
int exists(int values[], size_t count, int(*fkt)(int));
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
/*char findMax(char s[]) {
	char tmp[26] = { 0 };
	int cnt = 0;
	char c = NULL;

	for (int i = 0; i < strlen(s); i++) {
		tmp[s[i] - 'a'] += 1;
	}

	cnt = tmp[0];
	for (int i = 1; i < 26; i++) {
		if (tmp[i] > cnt) {
			cnt = tmp[i];
			c = i + 'a';
		}
	}

	return c;
}*/

char findMax(char s[]) {
	size_t haufigkeit[256] = { 0 };
	int i = 0;
	char maxindex = 0;
	for (i = 0; s[i] != '\0'; i++) 
		haufigkeit[s[i]]++;
	for (i = 0; i < 256; i++)
		if (haufigkeit[i] > haufigkeit[maxindex]);
			maxindex = i;

	return maxindex;
}

// Aufgabe 2 (10 Punkte)

/**
* Bestimmt den Durchschnittswert der Elemente im uebergebenen Array
* @param values Array der zu summierenden Elemente
* @param count Anzahl der Elemente in dem Array values
* @return Durchschnittswert der Elemente
*/
double avgArray(int values[], size_t count) {
	double avg = 0;
	for (size_t i = 0; i < count; i++) {
		avg += values[i];
	}
	return avg / count;
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
* @return 1 falls fkt fuer ein Element wahr liefert und 0 sonst.
*/
int exists(int values[], size_t count, int(*fkt)(int)) {
	for (size_t i = 0; i < count; i++) {
		if (fkt(values[i]))  {
			return 1;
		}
	}
	return 0;
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
	char c = NULL;
	int i = 0;
	int k = 0;
	FILE *fp = fopen(filename, "w+");
	while (c != EOF) {
		c = fgetc(fp);
		if (isupper(c)) i++;
		if (islower(c)) k++;
	}
	return i > k;
}

// Aufgabe 5 (20 Punkte)

/**
* Bestimmt den maximalen Wert der in der verketteten Liste
* gespeicherten Werte.
* @param head Zeiger auf das erste Element der Liste
* @return Maximaler Wert in Liste falls Liste nicht leer und INT_MIN sonst.
*/
int maxList(Listnode* head) {
	int c = 0;
	if ( head == NULL) return INT_MIN;
	while (head != NULL) {
		printf("%d ", head->data);
		if (head->data > c) {
			c = head->data;
		}
		head = head->next;
	}
	return c;
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
typedef struct pruefung_{
	char* fach;
	int note;
} Pruefung;

typedef Pruefung* pruefung;

Pruefung* mkPr(char* fach, int note) {
	pruefung pr = (pruefung*)malloc(sizeof(Pruefung));
	pr->fach = malloc(sizeof(fach) / sizeof(char));
	
	strcpy(pr->fach, fach);
	pr->note = note;

	return pr;
}

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
	int j, k = 0;
	int bedingung = 0;
	size_t strlength = strlen(src1) + strlen(src2) + 1;
	for (size_t i = 0, j = 1; k < strlen(dest); i+=2, j+=2) {
		if (k >= strlen(src1)) {
			for (size_t c = k; c < strlen(src1); c++) {
				dest[c] = src2[c];
			}
			//return 0;
		}
		dest[i] = src1[k];
		dest[j] = src2[k];
	
		k++;
	}
	//dest[] = '\0';
	//printf("%s\n", dest);
}

// Ende der Aufgaben
// Die folgenden Hilfsfunktionen koennen Ihnen helfen, falls
// Sie Ihren Code testen moechten.

Listnode* addFront(Listnode* head, int item) {
	Listnode* newHead = (Listnode*)malloc(sizeof(Listnode));
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
	char teststr[] = "abbcd";
	printf("Maxchar ist: %c \n", findMax(teststr));

	int intArray[] = { 1, 4, 2, 7, 9, 42 };
	if (exists(intArray, sizeof(intArray)/sizeof(int), is42)) printf("is42() == TRUE\n");
	else printf("is42() == FALSE\n");
	
	printf("Array durchschnitt ist:%lf\n", avgArray(intArray, sizeof(intArray) / sizeof(int)));

	Listnode* ln = NULL;
	for (int i = 0; i < sizeof(intArray) / sizeof(int); i++)
		ln = addFront(ln, intArray[i]);
	printf("Maxint in List is: %d\n", maxList(ln));

	char *src1 = "Chris";
	char *src2 = "Max";
	char dest[80];
	//mix(src1, src2, dest);

	//freelist(ln);

}
