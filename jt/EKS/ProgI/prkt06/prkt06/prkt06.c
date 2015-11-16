//Jan-Tjorve Sobieski
//Praktikum 06 Hausaufgabe

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
	//Zaehlvariable
	int i;
	//Abbruchbedingung
	if (size == 0)
		return 0;
	else
	//Forschleife um Array zu durchsuchen maximal 'size' Ueberpruefungen
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
	//Abbruchbedingung 1 Fall 
	if (size == 0 && numOcc == 0)
		return 1;
	//Abbruchbedingung 2 Fall 
	if (size == 0 && numOcc != 0)
		return 0;
	//Bedingung fuer Zaehlvariable
	if (a[size] == elem )
		numOcc--;
	//rekursiver Funktionsaufruf mit Sizecounter -1
	return findRecN(elem, numOcc, a, size-1);
}

/** Aufgabe 3
* addiert zu jedem Element des Arrays 42
* @param a Array
* @param size Groesse des Feldes
*/

void fortyTwo(int a[], size_t size) {
	//Zaehlvariable
	int i;
	//Abbruchbedingung
	if (size == 0)
		return 0;
	else
	//Forschleife zur Addition von 42 zu jedem Element
		for (i = 0; i < size; i++)
			a[i] = a[i] + 42;
}

/** Aufgabe 4
* Dreht eine Zeichenkette um
* @param a Zeichenkette, die umgedreht werden soll
*/

void rev(char a[]) {
	//Zaehlvariablen
	int i;
	int x;
	//temporaere Variable fuer Variablenswap
	char tmp;
	//Forschleife um Laenge des Arrays zu ermitteln
	for (i = 0; i < 81; i++) {
		if (a[i] == '\0')
			break;
	}
	//Forschleife Array zur Arraydrehung
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

void copyArray(int src[], int dst[], size_t size) {
	//Zaehlvariable fuer forschleife
	int i;
	//forschleife fuer Kopiervorgang
	for (i = 0; i < size; i++) {
		dst[i] = src[i];
	}
	//Ausgabe des Zielarrays
	//printf("%s", dst);
}

/** Aufgabe 5.2
* Kopiert den Inhalt von einem Quell- in ein Zielfeld rekursiv.
* @param src Quellfeld
* @param dst Zielfeld
* @param size Groesse des Feldes
*/

void copyArrayRec(int src[], int dst[], size_t size) {
	//Abbruchbedingung
	if (size == 0)
		return 0;
	//Kopiervorgang
	//Quellenarray in Zielarray
	dst[size] = src[size];	
	//rekursiver Funktionsaufruf mit Sizecounter -1 und Ziel/Quellarray
	return copyArrayRec(src, dst, size - 1);
}