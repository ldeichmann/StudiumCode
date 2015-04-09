#include <stdio.h>
#include <math.h>

int main(void)
    {
    int n;

    printf("Please input an integer value: ");
    scanf("%d", &n);
    printf("Your input was: %d\n", n);


    printf("%d = ", n);

    // Print the number of 2s that divide n
    if (n == 0 || n == 1)
    {
        printf("%d \n", n);
        return 0;
    }

    while (n%2 == 0)
    {
        if (n/2 > 1) {
            printf("%d * ", 2);
        } else {
            printf("%d ", 2);
        }
        n = n/2;
    }

    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            if (n/i > 1) {
                printf("%d * ", i);
            } else {
                printf("%d ", i);
            }
            n = n/i;
        }
    }

    // This condition is to handle the case whien n is a prime number
    // greater than 2
    if (n > 2)
    {
        printf ("%d ", n);
    }

    printf ("%s", "\n");


    return 0;
}
