#include <stdio.h>

int main(void) {

	unsigned int zaehler = 0;
	char buffer[21];
	double durchschnitt;
	double summe = 0;
	double messwert = 0;
	char c = 'j';

	while (c == 'j') {
		printf("\nMesswert:");
		
		gets_s(buffer, 21);
		sscanf(buffer, "%lf", &messwert);
		summe = summe + messwert;
		
		zaehler++;

		printf("\nweiter? (j)a oder (n)ein:");
		gets_s(buffer, 21);
		sscanf(buffer, "%c", &c);
	}

	printf("das Ergebnis ist: %lf", summe / zaehler);

	
		return 0;
}