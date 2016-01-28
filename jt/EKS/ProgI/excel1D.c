/*
* Excel VL Beispiel: 2D Arrays als 1D Array
*/
#include <stdio.h>
#include <stdlib.h>

void readCellValues(int* cells, size_t rows, size_t cols);
void printCellValues(int* cells, size_t rows, size_t cols);
void printCellValuesAndSums(int* cells, size_t rows, size_t cols);
int calcRowSum(int* cells, size_t rows, size_t cols, size_t row);
int calcColSum(int* cells, size_t rows, size_t cols, size_t col);


int main(void) {
	char buffer[21];
	size_t rows = 0;
	size_t cols = 0;
	int *cells;
	size_t row = 0;
	printf("Anzahl Spalten:");
	gets_s(buffer, 21);
	sscanf(buffer, "%Iu", &cols);
	printf("Anzahl Zeilen:");
	gets_s(buffer, 21);
	sscanf(buffer, "%Iu", &rows);
	// Speicher allozieren
	if (NULL == (cells = malloc(rows * cols * sizeof(int*))))
		exit(EXIT_FAILURE);
	readCellValues(cells, rows, cols);
	printCellValues(cells, rows, cols);
	printf("++++++++++\n");
	printCellValuesAndSums(cells, rows, cols);
	// Speicher freigeben
	free(cells);
}


void readCellValues(int* cells, size_t rows, size_t cols) {
	char buffer[21];
	size_t row = 0;
	size_t col = 0;
	for (row = 0; row < rows; row++)
		for (col = 0; col < cols; col++) {
			printf("Zelle %d/%d: ", row, col);
			gets_s(buffer, 21);
			sscanf(buffer, "%d", &cells[row * cols + col]);
		}
}

void printCellValues(int* cells, size_t rows, size_t cols) {
	size_t row = 0;
	size_t col = 0;
	for (row = 0; row < rows; row++) {
		for (col = 0; col < cols; col++)
			printf("%5d ", cells[row * cols + col]);
		printf("\n");
	}
}

void printCellValuesAndSums(int* cells, size_t rows, size_t cols) {
	size_t row = 0;
	size_t col = 0;
	for (row = 0; row < rows; row++) {
		for (col = 0; col < cols; col++)
			printf("%5d ", cells[row * cols + col]);
		printf("%5d \n", calcRowSum(cells, rows, cols, row));
	}

	for (col = 0; col < cols; col++)
		printf("%5d ", calcColSum(cells, rows, cols, col));
	printf("\n");
}

int calcRowSum(int* cells, size_t rows, size_t cols, size_t row) {
	int sum = 0;
	size_t col = 0;
	if (row >= rows)
		return 0;
	for (col = 0; col < cols; col++)
		sum += cells[row * cols + col];
	return sum;
}

int calcColSum(int* cells, size_t rows, size_t cols, size_t col) {
	int sum = 0;
	size_t row = 0;
	if (col >= cols)
		return 0;
	for (row = 0; row < rows; row++)
		sum += cells[row * cols + col];
	return sum;
}