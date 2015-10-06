//Jan-Tjorve Sobieski
//Aufgabe 2: 20 Punkte
//Entwickeln Sie ein C-Programm, das die ersten drei Zeilen aus “Brave New World”
//(Schöne Neue Welt) auf der Konsole ausgibt.

#include <stdio.h>

int main(void) {
	char *buf = "A SQUAT grey building of only thirty-four stories\n.\
			     Over the main entrance the words, CENTRAL LONDON HATCHERY\n\
				 AND CONDITIONING CENTRE, and, in a shield, the World State\n\
				's motto, COMMUNITY, IDENTITY, STABILITY.\n\
			     The enormous room on the ground floor faced towards the north.\n";

	printf("%s", buf);
	return 0;
}