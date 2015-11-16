/*Sortieren mit SelectionSort und QuickSort*/
#include <stdio.h>

/* Gibt ein Feld auf der Konsole aus
* @param a auszugebendes Feld
* @param size Groesse des Feldes
*/
void printArray(const int a[], size_t size);

/* Sortieren mit SelectionSort
* @param a zu sortierendes Feld
* @param size Groesse des Feldes
*/
void selectionSort(int a[], size_t left, size_t right);

/* Funktion zum Aufteilen eines Feldes fuer QuickSort
*/
size_t partition(int a[], size_t left, size_t right);


/* Sortieren mit QuickSort
* @param a zu sortierendes Feld
* @param left linke Grenze des zu sortierenden Bereichs
* @param right rechte Grenze des zu sortierenden Bereichs
*/
void quickSort(int a[], size_t left, size_t right);


/* Tauscht a und b
*/
void swap(int *a, int *b);


double getMedian(int a[], size_t size);

int main(void)
{
	int a[11] = { 5, 1, 18, 29, 40, 41, 2, 7, 19, 20, 27 };
	int b[10] = { 5, 1, 18, 29, 40, 41, 2, 7, 19, 20};
	
	printArray(a, 11);
	//quickSort(a, 0, 10);
	selectionSort(a, 0, 10);
	printArray(a, 11);
	printf("Median: %lf\n\n", getMedian(a, 11));
	
	printArray(b, 10);
	quickSort(b, 0, 9);
	printArray(b, 10);
	printf("Median: %lf", getMedian(b, 10));
	
	getchar();
}

void printArray(const int a[], size_t size)
{
	size_t i = 0;
	for (i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void selectionSort(int a[], size_t left, size_t right)
{
	size_t i = 0;
	size_t j = 0;
	int temp;
	for (i = left; i < right; i++) {
		for (j = i + 1; j <= right; j++)
			if (a[i] > a[j]) {
			swap(&a[i], &a[j]);
			}
	}
}

void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(int a[], size_t left, size_t right)
{
	size_t i = 0;
	if (right <= left)
		return;
	i = partition(a, left, right);
	quickSort(a, left, i - 1);
	quickSort(a, i + 1, right);
}

size_t partition(int a[], size_t left, size_t right){
	size_t i = left - 1;
	size_t j = right;
	int v = a[right];
	int temp;
	for (;;){
		while (a[++i] < v);
		while (v < a[--j]) if (j == left) break;
		if (i >= j) break;
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	temp = a[i];
	a[i] = a[right];
	a[right] = temp;
	return i;
}

double getMedian(int a[], size_t size) {
	if (size % 2 == 0)
		return (double) (a[size / 2 - 1] + a[size / 2]) / 2;
	else
		return a[size / 2];
}
