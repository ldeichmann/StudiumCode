# include <stdio.h>
# include <math.h>

int main(void) {

    //Variablen !!
    int n,i;
    n = 0; i = 0;

    //Eingabe
    scanf("%d",&n);
    printf("you put in %d\n",n);

    //Abfangen bei Nulleingabe
    if(n==0) return 0;

    //Case wenn Eingabe Grade ist
    while (n%2 == 0)
    {
        printf("%d ", 2);
        n = n/2;
    }

    //Hier Eingabe aufjedenfall ungerade
    for (i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            printf("%d ", i);
            n = n/i;
        }
    }

    // Final Case
    if (n > 2)
        printf ("%d ", n);

    printf("\n");
}
