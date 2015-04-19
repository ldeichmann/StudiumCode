#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int main(int argc, char *argv[]) {
int main(void) {

    ///////////////////////////////////////////////////////
    // variablen
    int h1,m1,h2,m2,a;
    char buffer[100];
    char s[100];

    h1  = 0;
    h2  = 0;
    m1  = 0;
    m2  = 0;
    a   = 0;
    ///////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////
    printf("was moechtest du tun?");
    printf("1: Termin eingeben!");
    printf("2: laengste Freizeit ausgeben");

   switch(a) {
       case 1:
          while(1);
            break;
       case 2:
            break;
   }
    ///////////////////////////////////////////////////////
    //input
    fgets(buffer, sizeof(buffer)/sizeof(buffer[0]) ,stdin);
    sscanf(buffer, "%d:%d %d:%d %100[^\n]", &h1, &m1, &h2, &m2, s);
    printf("%d:%d %d:%d %s", h1, m1, h2, m2, s);
    ///////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////
}
