/* Hauptprogramm fuer vierte Praktikumsaufgabe
* Programmierung 1
*/

#include <stdio.h>


#define PI 3.1415
/* Prototypen fuer Aufgaben */
int cubeSurfaceArea(int length);
double circleCircumference(double radius);
void printTri(unsigned int size);
int areCoprime(unsigned int a, unsigned int b);
int ggt(unsigned int x);

/* Nutzerschnittstelle fuer die Aufgaben */

void a1();
void a2();
void a3();
void a4();

/* Auswahlmenu */

char menu() {
	int i = 0;
	char selection = 0;
	printf("\n");
	printf("1) Aufgabe 1\n");
	printf("2) Aufgabe 2\n");
	printf("3) Aufgabe 3\n");
	printf("4) Aufgabe 4\n");
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
