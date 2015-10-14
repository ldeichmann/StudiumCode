//  Jan-Tjorve Sobieski
//  Bonusaufgabe: 10 Bonuspunkte
//	Ein Kassensystem enthält 50ct, 5ct Münzen.Entwickeln Sie ein C - Programm, dass
//	einen Wechselgeldbetrag in ct einliest und bestimmt wie viele Münzen jeder Sorte
//	das System zurückgeben muss.Es gibt Problemfälle. Überlegen Sie, wie Sie dafür eine
//	Lösung finden.#include <stdio.h>

int main(void) {

	char buf[21];
	int ctinput = 0;
	int cent1 = 50;
	int cent2 = 5;
	int i = 0;
	int j = 0;

	printf("Wechselgeldbetrag\n");
	gets_s(buf, 21);
	sscanf(buf, "%d", &ctinput);
	
	if (ctinput % cent1 != 0) {
		i = ctinput / cent1;
		ctinput = ctinput - i * cent1;
	}

	j = ctinput / cent2;
	

	printf("Ausgabe\n");
	printf("50ct %d\n", i);
	printf("5ct %d\n", j);

	return 0;
}