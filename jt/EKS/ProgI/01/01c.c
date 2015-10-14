// Jan-Tjorve Sobieski
// Aufgabe 3: 40 Punkte
// Entwickeln Sie ein C-Programm, das Angaben in US Pfund (lb) in Kilogramm umwandelt.
// Bestimmen Sie, welche Daten Ihr Programm verarbeiten muss, welche Berechnungen
// vorgenommen werden müssen und welche C-Datentypen dafür zu wählen
// sind.
// Entwerfen Sie den Algorithmus und modellieren Sie ihn durch ein Aktivitätsdiagramm.
// Implementieren und testen Sie das Programm.
#include <stdio.h>

int main(void) {
	const double onelbinkg = 0.45359237;
	char buf[21];
	double input;


	printf("Geben sie ein wert in Pfund ein den sie in KG umwandeln wollen!\n");

	gets_s(buf, 21);
	sscanf(buf, "%lf", &input);
	
	printf("das Ergbenis ist: %f\n", input*onelbinkg);

	return 0;
}
