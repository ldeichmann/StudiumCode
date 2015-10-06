//Aufgabe 4: 40 Punkte
//Entwickeln Sie ein C - Programm, dass wahlweise US Pfund in Kilogramm oder umgekehrt
//umwandelt.
//Gehen Sie wie in der vorherigen Aufgabe vor.

#include <stdio.h>

int main(void) {

		const double onelbinkg = 0.45359237;
		const double onkginlb = 2.20462262185;
		char buf[21];
		int input;

	
		printf("lb in kg (1)\n");
		printf("kg in lb (2)\n");
	
		gets_s(buf, 21);
		sscanf(buf, "%d", &input);

		if (input == 1)  {
			printf("Geben sie ein wert in LB ein den sie in KG umwandeln wollen!\n");
			gets_s(buf, 21);
			sscanf(buf, "%d", &input);
			printf("das Ergbenis ist: %f: ", input*onelbinkg);
		}
		
		else if(input ==2){
			printf("Geben sie ein wert in KG ein den sie in LB umwandeln wollen!\n");
			gets_s(buf, 21);
			sscanf(buf, "%d", &input);
			printf("das Ergbenis ist: %f: ", input*onkginlb);
		}
	
		return 0;
}