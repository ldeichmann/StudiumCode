#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "caesar.h"

void caesar(char text[], char offset) {
    unsigned int offNr = (offset - text[0]);
    for(int i = 0; i < strlen(text) ; i++) {
        printf("%c", text[i]);
        if(isspace(text[i]));
        if(text[i] >= 65 && text[i] <= 90){
            text[i] = text[i] + offNr;
        }
        if(text[i] >= 97 && text[i] <= 122) {
            text[i] = text[i] + offNr;
        }
        if (text[i] > 90 && text[i] < 97) {
            text[i] = text[i] + 7;
        }

        if (text[i] > 122) {
            text[i] = text[i] - 58;
        }
    }
}


