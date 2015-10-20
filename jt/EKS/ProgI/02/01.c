/*
Jan-Tjorve Sobieski 

Programmieren 1 Praktikum

Aufgabe 1: Casting-Shows 20 Punkte
Es soll ein Programm für eine Casting-Show entwickelt werden. Das Programm soll
für die Teilnehmer Alexander, Beatrix und Christiane zuerst die Ergebnisse der Telefonrunde
(Prozent der Anrufer) einlesen und dann drei entsprechende Balken auf den
Bildschirm zeichnen.
Alexander: 50
Beatrix: 48
Christiane: 2
Alexander: #########################
Beatrix: ########################
Christiane: #

(a)Beschreiben Sie, welche Daten das Programm verwalten und welche Rechnungen
durchzuführen sind.

- wir brauchen drei Eingaben fuer die Anzahl der Anrufer fuer die einzelnen Spieler
- dann brauchen wir einen Eingabe Buffer der alle Eingaben enthaelt und dann in einen Integer speichert
- ich habe noch 3 zwischen variablen fuer die Rechnung benutzt

- jeweils die Prozentzahl des einzelnen Anrufer muss berechnet werden

(b)Entscheiden Sie, welche Datentypen Sie dafür in C verwenden.Begründen Sie
Ihre Entscheidung.

- da Prozentrechnung benutzt wird habe ich mich fuer double entschieden

(c)Modellieren Sie den Programmablauf durch ein Aktivitätsdiagramm.



(d)Implementieren Sie das Programm in C.
*/

#include <stdio.h>

void drawOnScreen(int x) {
	int i = 0;
	for (i = 0; i < x; i++) {
		printf("#");
	}
}

int main(void) {

	double player1;
	double player2;
	double player3;
	int caller;
	char buffer[21];

	int play1;
	int play2;
	int play3;

	printf("Alexander: ");
	gets_s(buffer, 21);
	sscanf(buffer, "%d", &play1);

	printf("Beatrix: ");
	gets_s(buffer, 21);
	sscanf(buffer, "%d", &play2);

	printf("Christine: ");
	gets_s(buffer, 21);
	sscanf(buffer, "%d", &play3);

	caller = play1 + play2 + play3;
	player1 = (double) play1 / caller * 50;
	player2 = (double) play2 / caller * 50;
	player3 = (double) play3 / caller * 50;

	printf("Alexander: \t");
	drawOnScreen(player1);
	printf("\n");
	//printf(" %f\n", player1);

	printf("Beatrix: \t");
	drawOnScreen(player2);
	printf("\n");
	//printf(" %f\n", player2);

	printf("Christine: \t");
	drawOnScreen(player3);
	printf("\n");
	//printf(" %f\n", player3);
	return 0;
}