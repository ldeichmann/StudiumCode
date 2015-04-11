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

    fgets(buffer, 200, stdin);
    if ( sscanf ( buffer , "%c", &n ) == 1) {

        switch(n) {
        case'1':
            printf("Enter String\n");

            fgets(buffer, 200, stdin);

            anacae(buffer);

            for (int j = 0; j < strlen(buffer); j++ )
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
                printf("Enter String\n");
                fgets(buffer, 200, stdin);

                caesar(buffer, rot);
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