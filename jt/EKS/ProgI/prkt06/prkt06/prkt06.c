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

int find(int elem, const int a[], size_t size) {
	int i;
	if (size == 0)
		return 0;
	else
		for (i = 0; i < size; i++) 
			if (a[i] == elem) 
				return 1;
}


/** Aufgabe 2
* durchsucht rekursiv ein Array nach vorgegebenem Element und prueft, ob es
* mindestens numOcc mal vorhanden ist.
* @param elem zu suchendes Element
* @param numOcc minimale Anzahl an Vorkommen des Elements elem in a
* @param a zu durchsuchendes Feld
* @param size Groesse des Feldes
* @return 0 falls nicht gefunden, 1 sonst
*/

int findRecN(int elem, size_t numOcc, const int a[], size_t size) {
	if (size == 0)
		return 0;
	if (a[size] == elem) {
		numOcc++;
		return 1;
	}
	return findRecN(elem, numOcc, a, size-1);
}

/** Aufgabe 3
* addiert zu jedem Element des Arrays 42
* @param a Array
* @param size Groesse des Feldes
*/

void fortyTwo(int a[], size_t size) {
	int i;
	if (size == 0)
		return 0;
	else
		for (i = 0; i < size; i++)
			a[i] = a[i] + 42;
}

/** Aufgabe 4
* Dreht eine Zeichenkette um
* @param a Zeichenkette, die umgedreht werden soll
*/

void rev(char a[]) {
	int i;
	int x;
	char tmp;
	for (i = 0; i < 81; i++) {
		if (a[i] == '\0')
			break;
	}

	for (x = 0; x < i / 2; x++) {	
		tmp = a[x];
		a[x] = a[i - x - 1];
		a[i - x - 1] = tmp;
	}
}

/** Aufgabe 5
* Kopiert den Inhalt von einem Quell- in ein Zielfeld.
* @param src Quellfeld
* @param dst Zielfeld
* @param size Groesse des Feldes
*/