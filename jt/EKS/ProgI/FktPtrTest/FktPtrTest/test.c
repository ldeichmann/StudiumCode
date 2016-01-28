#include <stdio.h>
#include <string.h>

int deliver_fruit(char *address, float speed, int(*fkt)(int, int))
{
	printf("Delivering fruit to %s at speed %.2f\n and this shit %d\n", address, speed, fkt);
	return fkt;
}

int retardFunction(int a, int b) {
	return a + b;
}


int main(void)
{
	int a = 10;
	int(*p)(char*, float); // declare a function pointer variable
	p = deliver_fruit; // p now points to the deliver_fruit() function
	deliver_fruit("My house", 5280.0, retardFunction(a, a*2)); // a normal call
	p("My house", 5280.0); // the same call, but using the pointer

	int(*fp)(int, int);
	fp = retardFunction;
	printf("\n\n%d ", fp(a, 5));

	char s[80];
	long i;
	char *endptr;
	gets_s(s, 80);
	i = strtol(s, &endptr, 10);
	printf("%d : %s", i, endptr);

	return 0;
}