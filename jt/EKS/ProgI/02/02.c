/*
Jan-Tjorve Sobieski

Programmieren 1 Praktikum

Aufgabe 2: Abgas - Messwerte 30 Punkte
Entwickeln Sie ein Programm, das eine Reihe von Abgas - Messwerten einliest und den
Durchschnitt der Messwerte berechnet.Um mögliche Manipulationen zu verhindern,
sollen nur Messwerte berücksichtigt werden, die über 42 liegen bzw.gleich 42 sind.

(a)Beschreiben Sie, welche Daten das Programm verwalten und welche Rechnungen
durchzuführen sind.

- Wir brauchen eine Zaehler der mit zaehlt wie viele Messwerte eingegeben werden
- einen Eingabe Buffer 
- Variablen fuer den Durchschnitt und die Summe aller Messwerte

- Es muss der Durchschnitt aller eingegeben Messwerte errechnet werden also alle Messwerte durch die Anzahl der eingegeben Werte

(b)Entscheiden Sie, welche Datentypen Sie dafür in C verwenden.Begründen Sie
Ihre Entscheidung.

- da auch Komma Zahlen moeglich sind habe ich mich fuer double entschieden, ausser beim Zaehler

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
			return 0;
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