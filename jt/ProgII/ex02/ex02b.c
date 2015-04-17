#include <stdio.h>
#include <math.h>

int main(void) {
    char buffer[80];
    fgets(buffer, 80 , stdin);
    float v1, v2, v3;
    if (sscanf ( buffer, "%f %f %f", &v1, &v2, &v3) == 3) {
        printf("%f \n", sqrt((v1*v1) + (v2*v2) + (v3*v3)));
    }
}
