/* Hauptprogramm fuer vierte Praktikumsaufgabe
* Programmierung 1
*/

#include <stdio.h>

/* Prototypen fuer Aufgaben */

/* Aufgabe 1
* berechnet die Oberflaeche eines Wuerfels
* @param length Kantenlaenge des Wuerfels
* @return Oberflaeche
*/

int cubeSurfaceArea(int length);


/* Aufgabe 2
* berechnet den Umfange eines Kreises
* @param radius Radius des Kreises
* @return Umfang des Kreises
*/

double circleCircumference(double radius);

/* Aufgabe 3
* gibt ein rechtwinkliges Dreieck aus * auf der Konsole aus
* @param size Hoehe des Dreiecks
*/

void printTri(unsigned int size);

/* Aufgabe 4
* Bestimmt ob zwei Zahlen teilerfremd sind
* @param a zu untersuchende Zahl
* @param b zu untersuchende Zahl
* @return 0 falls a und b teilerfremd sind, sonst 1
*/

int areCoprime(unsigned int a, unsigned int b);

/* Aufgabe 5
* Berechnet den Binomialkoeffizienten n ueber k
* @param n
* @param k
* @return n ueber k
*/

unsigned int binomialCoefficient(unsigned int n, unsigned int k);


/* Nutzerschnittstelle fuer die Aufgaben */

void a1();
void a2();
void a3();
void a4();
void a5();
/* Auswahlmenu */

char menu() {
	int i = 0;
	char selection = 0;
	printf("\n");
	printf("1) Aufgabe 1\n");
	printf("2) Aufgabe 2\n");
	printf("3) Aufgabe 3\n");
	printf("4) Aufgabe 4\n");
	printf("5) Aufgabe 5\n");
	printf("s) Stop");
	selection = getchar();
	while (getchar() != '\n');
	return selection;
}

int main(void)
{
	char selection;
	while ((selection = menu()) != 's') {
		switch (selection)
		{
		case '1':
			a1();
			break;
		case '2':
			a2();
			break;
		case '3':
			a3();
			break;
		case '4':
			a4();
			break;
		case '5':
			a5();
			break;
		}
	}
}

void a1()
{
	int length = 0;
	char buffer[21];

	printf("Wuerfeloberflaechenberechnung\n");
	printf("Seitenlaenge des Wuerfels: ");
	fgets(buffer, 21, stdin);
	sscanf(buffer, "%d", &length);
	printf("Oberflaeche: %d\n", cubeSurfaceArea(length));
}

void a2()
{
	double radius = 0.0;
	char buffer[21];
	printf("Kreisumfangeberechnung\n");
	printf("Radius: ");
	fgets(buffer, 21, stdin);
	sscanf(buffer, "%lf", &radius);
	printf("Kreisumfang: %f\n", circleCircumference(radius));
}


void a3()
{
	int size = 0;
	char buffer[21];
	printf("Dreieck\n");
	printf("Hoehe: ");
	fgets(buffer, 21, stdin);
	sscanf(buffer, "%d", &size);
	printTri(size);
}

void a4()
{
	unsigned int a;
	unsigned int b;
	char buffer[21];

	printf("Teilerfremdheit\n");
	printf("Zahl a:");
	fgets(buffer, 21, stdin);
	sscanf(buffer, "%u", &a);
	printf("Zahl b:");
	fgets(buffer, 21, stdin);
	sscanf(buffer, "%u", &b);
	if (areCoprime(a, b))
		printf("%u und %u sind teilerfremd\n", a, b);
	else
		printf("%u und %u sind nicht teilerfremd\n", a, b);
}

void a5()
{
	unsigned int n;
	unsigned int k;
	char buffer[21];

	printf("Binomialkoeffizient\n");
	printf("Zahl n:");
	fgets(buffer, 21, stdin);
	sscanf(buffer, "%u", &n);
	printf("Zahl k:");
	fgets(buffer, 21, stdin);
	sscanf(buffer, "%u", &k);
	printf("%u ueber %u = %u", n, k, binomialCoefficient(n, k));
}


