/*
Jan-Tjorve Sobieski

Programmieren 1 Praktikum

Aufgabe 2: Abgas - Messwerte 30 Punkte
Entwickeln Sie ein Programm, das eine Reihe von Abgas - Messwerten einliest und den
Durchschnitt der Messwerte berechnet.Um mögliche Manipulationen zu verhindern,
sollen nur Messwerte berücksichtigt werden, die über 42 liegen bzw.gleich 42 sind.

(a)Beschreiben Sie, welche Daten das Programm verwalten und welche Rechnungen
durchzuführen sind.

- wir brauchen einen Zaehler um die Anzahl der eingegebenen Messwerte zu zaehlen
ausserdem noch einen Eingangsbuffer und Variablen zum speichern vom eingegeben
Messwert

Alle Werte werden zu einer Summe zusammengerechnet und am Ende des Programms
durch die Anzahl der Messwerte geteilt

(b)Entscheiden Sie, welche Datentypen Sie dafür in C verwenden.Begründen Sie
Ihre Entscheidung.
- Ich habe mich fuer double entschieden, da Abgaswerte auch im Komma bereich liegen koennen

(c)Modellieren Sie den Programmablauf durch ein Aktivitätsdiagramm.

(d)Implementieren Sie das Programm in C.
*/

#include <stdio.h>

int main(void) {

	
	char buffer[21];

	double durchschnitt;
	double summe = 0;
	double messwert = 0;

	char c = 'j';
	
	//Variabl um Maxvalue zu finden
	double maxv = 0.0;
	
	//zaehlt wie oft Maxvalue vorkommt
	unsigned int maxcount = 0;
	
	//counter fuer Durchschnittsrechnung
	unsigned int zaehler = 0;

	while (c == 'j') {
		printf("\nMesswert:");

		gets_s(buffer, 21);
		sscanf(buffer, "%lf", &messwert);
		if (messwert < 42) {
			printf("wrong value!\n");
			continue;
		}
		
		//Abfrage ob Messwert der gerade groesste eingegebene Wert ist
		//wenn ja neuen Maxwert setzten und den Counter auf 0 setzten
		if (messwert > maxv) {
			maxv = messwert;
			maxcount = 0;
		}

		//Wenn Maxwert mehrmals vorkommt index hochzaehlen
		if (messwert == maxv)
			maxcount++;

		summe += messwert;

		zaehler++;

		printf("\nweiter? (j)a oder (n)ein:");
		gets_s(buffer, 21);
		sscanf(buffer, "%c", &c);
	}

	printf("\n\ndas Ergebnis ist: %lf\n\n", summe / zaehler);
	printf("\n\nMaxwert ist: %lf und er kommt %d vor\n\n", maxv, maxcount);

	return 0;
}