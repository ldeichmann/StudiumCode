#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "caesar.h"
#include "anacae.h"


int main (void) {

    char buffer[200];
    char n;

    printf("1 - Enter Caesar String to crack\n"); 
    printf("2 - Enter Rotation and String to rotate\n"); 
    printf("3 - Exit\n");  
    printf("Select:\n");

    fgets(buffer, 200, stdin); //throw input into buffer
    if ( sscanf ( buffer , "%c", &n ) == 1) {

        switch(n) {
        case'1':
            printf("Enter String\n");

            fgets(buffer, 200, stdin); //into buffer again

            anacae(buffer); //crack that

            for (int j = 0; j < strlen(buffer); j++ ) //print dat
            {
                printf("%c", buffer[j] );
            }
            printf("\n");
            break;
        case'2':
            printf("Enter Rotation\n");
            int rot;
            fgets(buffer, 200, stdin);

            if ( sscanf ( buffer , "%d", & rot ) == 1) {
//              printf("%d\n", rot);
		if ( rot > 26 || rot < 0) { printf("out of range\n"); break; } //fuck you and your case
                printf("Enter String\n");
                fgets(buffer, 200, stdin);

                caesar(buffer, rot); //rotate my life
                for (int j = 0; j < strlen(buffer); j++ )
                {
                    printf("%c", buffer[j] );
                }

            }
            printf("Bye bye\n");

            break;

        case '3':
            printf("Bye bye\n");
            break;
        
        default:
            printf("Bye bye\n");
            break;
        }
    }

    return 0;
}
