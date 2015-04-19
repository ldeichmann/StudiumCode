#include <stdio.h>
#include <math.h>

double NormVektor(double z1, double z2, double z3);

int main(void) {

    double z1,z2,z3;

    z1=0.0;
    z2=0.0;
    z3=0.0;

    printf("Geben sie bitte einen drei Dimensionalen Vektor ein\n");
    if( scanf("%lf %lf %lf", &z1, &z2, &z3) == 3) {
        printf("%f", NormVektor(z1,z2,z3));
    }
    return 0;
}

double NormVektor(double z1, double z2, double z3) {
    double v = 0;
    v = sqrt( pow(z1,2)+pow(z2,2)+ pow(z3,2) );

    return v;
}
