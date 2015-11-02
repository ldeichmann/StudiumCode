#include <stdio.h>
#include <math.h>

#define PI 3.1415

/* Prototypen fuer Aufgaben */
int cubeSurfaceArea(int length);
double circleCircumference(double radius);
void printTri(unsigned int size);
int areCoprime(unsigned int a, unsigned int b);
int ggt(unsigned int a, unsigned int b);

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

//void printTri(unsigned int size) {
//	int i = 0;
//	int j = 0;
//	int x = 0;
//	printf("\n");
//	for (i = 1; i <= size; i++) {
//		printf("*");
//		if (i == size) {
//			for (x = 0; x <= j; x++) {
//				printf("*");
//			}
//			printf("\n");
//			return 0;
//		}
//		for (j = 1; j < i; j++) {
//			printf(" ");
//		}
//
//		printf("*\n");
//		
//		
//	}
//	printf("\n");
//}

void printTri(unsigned int size) {
	int i = 0;
	int j = 0;
	int x = 0;

	printf("\n");
	for (i = 0; i < size; i++){
		for (j = 0; j <= i; j++){
			printf("*");
		}
		printf("\n");
	
		
	}
}

/* Aufgabe 4
* Bestimmt ob zwei Zahlen teilerfremd sind
* @param a zu untersuchende Zahl
* @param b zu untersuchende Zahl
* @return 0 falls a und b teilerfremd sind, sonst 1
*/

int areCoprime(unsigned int a, unsigned int b) {
	if (ggt(a,b))
		return 0;
	else
		return 1;
}

int ggt(unsigned int a, unsigned int b) {
	if (b == 0)
		return a;
	else
		return ggt(b, a%b);    // Rekursiv

}



