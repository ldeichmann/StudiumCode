#include <stdio.h>
#include <math.h>

#define PI 3.1415

/* Prototypen fuer Aufgaben */
int cubeSurfaceArea(int length);
double circleCircumference(double radius);
void printTri(unsigned int size);
int areCoprime(unsigned int a, unsigned int b);
int ggt(unsigned int x);

/*Aufgaben 

/* Aufgabe 1
 * berechnet die Oberflaeche eines Wuerfels
 * @param length Kantenlaenge des Wuerfels
 * @return Oberflaeche
 */

int cubeSurfaceArea(int length) {
	return length * length * length;
}


/* Aufgabe 2
 * berechnet den Umfange eines Kreises
 * @param radius Radius des Kreises
 * @return Umfang des Kreises
 */

double circleCircumference(double radius) {
	return 2 * PI * radius;
}

/* Aufgabe 3
 * gibt ein rechtwinkliges Dreieck aus * auf der Konsole aus
 * @param size Hoehe des Dreiecks
 */

void printTri(unsigned int size) {

}

/* Aufgabe 4
 * Bestimmt ob zwei Zahlen teilerfremd sind
 * @param a zu untersuchende Zahl
 * @param b zu untersuchende Zahl
 * @return 0 falls a und b teilerfremd sind, sonst 1
 */

int areCoprime(unsigned int a, unsigned int b) {
	if(ggt(a) != ggt(b))
		return 0;
	else
		return 1;
}

int ggt(unsigned int n) {
    if( b==0)
        return a;
    else
        ggT(b, a%b);    // Rekursiv
}
}


