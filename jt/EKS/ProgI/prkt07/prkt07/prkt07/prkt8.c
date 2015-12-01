//Dennis Ott - Jan-Tjorve Sobieski
// Praktikum 9 Hausaufgabe

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>
/* Prototypen fuer Aufgaben */

/** Aufgabe 1
* addiert zwei Zahlen
* @param a Zeiger auf ersten Summanden
* @param b Zeiger auf zweiten Summanden
* @return Summe der Summanden
*/
int add(int* a, int* b) {
	//returnt Werte die an den Adressen von a und b stehen
	return (*a+*b);
}

/** Aufgabe 2
* Findet den Anfang des ersten Wortes in der Zeichenkette s
* Liefert einen Zeiger auf den ersten Buchstaben innerhalb von s und ueberliest alle Leerzeichen davor
* Fuer "   Hallo" liefert die Funktionen einen Zeiger auf das H.
* @param s
* @return Zeiger auf das erste Zeichen in s, das kein Leerzeichen ist
*/
char* trim(const char s[]) {
	//Pointer auf Erstes Zeichen im Array s	
	char *chrPtr = s;
	//Pointer auf Letztes Zeichen im Array s
	char *endPtr = &s[strlen(s) - 1];
	//While loop um durch Array s zu iterieren 
	while (chrPtr < endPtr) {
		if (*chrPtr != ' ')
			return chrPtr;
		chrPtr++;
	}

	return chrPtr;
}

/** Aufgabe 3
* Erstellt eine Abkuerzung zu einer Zeichenkette s
* Federation Internationale Football Association  -> FIFA
* @param s Langform der Zeichenkette
* @param a Zielpuffer fuer die Abkuerzung
* @param size Groesse des Zielpuffers
*/
void abbrev(const char s[], char a[], size_t size) {
	//Pointer auf Erstes Zeichen im Array s	
	char *chrPtr = s;
	//Pointer auf Letztes Zeichen im Array s
	char *endPtr = &s[strlen(s) - 1];
	//Pointer auf Zielarray
	char *targetPtr = a;
	//Counter um nicht groesser ueber die Grenzen von a zu gehen
	unsigned int cnt = 0;
	
	//Abfrage ob counter fuer Befuellung von a nicht groesser ist als a
	if(cnt < size) {
		//Abfrage ob Pointer Elemente im Array s ein Leerzeichen ist und 
		//Zeichen danach kein Leerzeichen ist
		//hackt erste Leerzeichen weg 
		if (*chrPtr != ' ' && isalpha(*chrPtr)) {
			*targetPtr = *chrPtr;
			targetPtr++;
			chrPtr++;
		}
		//While loop um durch Array s zu iterieren 
		while (chrPtr < endPtr) {
			//Setzt ersten Buchstaben ins Zielarray
			if (*chrPtr == ' ' && *(chrPtr + 1) != ' ') {
				*targetPtr = *(chrPtr + 1);
				*targetPtr++;
				cnt++;
			}
			chrPtr++;
		}
		//Setzt an das ende des Zielarrays ein Nullchar
		*targetPtr = '\0';
	}
}