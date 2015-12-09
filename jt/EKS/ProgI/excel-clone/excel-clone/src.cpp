#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int numbers[], int size, int rows, int cols);
int askNumbers();
void fillArray(int* numbers, int size, int rows, int cols);
int rowsSum(int* numbers, int size, int row);
int colSum(int* numbers, int size, int col);


void printArray(int numbers[], int size, int rows, int cols) {
	int i = 0;
	int rowscnt = 0;
	printf("\n");
	for (i = 0; i < size; i++) {
		if (rowscnt == cols) {
			printf("\n");
			rowscnt = 0;
		}
		rowscnt++;
		printf("%d \t", *(numbers + i));
	}
	printf("\n");
}

int askNumbers() {
	int size = 0;
	char buffer[80];
	gets_s(buffer, 80);
	sscanf(buffer, "%d", &size);
	return size;
}

void fillArray(int* numbers, int size,int rows, int cols) {
	int value = 0;
	int spalte = 0;
	int zeile = 0;

	while (zeile != -1 || spalte != -1 || zeile != rows || spalte != cols) {

		printf("bitte Zeile eingeben ");
		zeile = askNumbers();
		if (zeile == -1)
			break;

		printf("bitte Spalte eingeben ");
		spalte = askNumbers();
		if (spalte == -1)
			break;

		printf("bitte Wert eingeben ");
		value = askNumbers();
		if (value == -1)
			break;

		*(numbers + (zeile * rows + spalte )) = value;
	}

	printf("\n");
}

int main(void) {
	int n = 0;
	
	printf("geben sie die Anzahl der Spalten ein\n");
	int rows = askNumbers();
	printf("\ngeben sie die Anzahl der Zeilen ein\n");
	int cols = askNumbers();

	int size = rows * cols;

	int* numbers = (int*)malloc(rows * cols * sizeof(int));
	memset(numbers, 0, rows*cols*sizeof(int));

	while (n != -1) {
		printf(" 1: Tabelle ausgeben\n");
		printf(" 2: Wert eingeben\n");
		printf("-1: Beenden\n");
		n = askNumbers();
		printf("\n");

		switch (n) {
		case 1:
			printArray(numbers, size, rows, cols);
			break;
		case 2:
			fillArray(numbers, size, rows, cols);
			break;
		case -1:
			return 0;
		default:
			printf(" 1: Tabelle ausgeben");
			printf(" 2: Wert eingeben");
			printf("-1: Beenden\n");
		}
	}


	free(numbers);
}