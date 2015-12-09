#include <stdio.h>

void swap42Fail(int* a, int* b);
int *yield42();


int main(void) {
	//int a = 3;
	//int b = 2;
	//swap42Fail(&a, &b);
	//printf("3-a:%d  2-b:%d", a, b);
	printf("Hello");
	int* answer = yield42();
	printf("%d", *answer);
}

void swap42Fail(int* a, int* b) {
	int tmp = *a * 42;
	*a = *b * 42;
	*b = tmp;
}

int* yield42() {
	int answer = 42;
	return &answer;
}