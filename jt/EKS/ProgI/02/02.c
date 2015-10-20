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

int messwerteingabe(void) {

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
		if (messwert < 42) {
			printf("wrong value!\n");
			continue;
		}
		summe += messwert;

		zaehler++;

		printf("\nweiter? (j)a oder (n)ein:");
		gets_s(buffer, 21);
		sscanf(buffer, "%c", &c);
	}

	printf("\n\ndas Ergebnis ist: %lf\n\n", summe / zaehler);


	return 0;
}

int main(void) {

	messwerteingabe();
	return 0;
}