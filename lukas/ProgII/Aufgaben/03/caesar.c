#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "caesar.h"

void caesar(char text[], char offset) {

    for(int i = 0; i < strlen(text); i++)
    {

        if (isalpha(text[i]) )
        {

            char *e;
            int index;
            // get char position in alphabet
            e = strchr(alphabet, tolower(text[i]));
            index = ((int)(e - alphabet)) - offset;
//          printf("%c %d %c\n", text[i], index, alphabet[index] );
            if (index >= 26) { // out of bounds, fix that
                if (isupper(text[i])) {
//                  printf("%c %d %c\n", text[i], index-26, toupper(alphabet[index-26]));
                    text[i] = toupper(alphabet[index-26]);
                } else {
                    text[i] = alphabet[index-26];
//                  printf("%c\n", alphabet[index+offset-26]);
                }
            } else if (index < 0) { // out of bounds, fix that too
                if (isupper(text[i])) {
//                  printf("%c %d %c\n", text[i], index-26, toupper(alphabet[index-26]));
                    text[i] = toupper(alphabet[index+26]);
                } else {
                    text[i] = alphabet[index+26];
//                  printf("%c\n", alphabet[index+offset-26]);
                }
            } else { // change letter 
                if (isupper(text[i])) {
                    text[i] = toupper(alphabet[index]);
//                  printf("%c\n", toupper(alphabet[index+offset]));                
                } else {
                    text[i] = alphabet[index];
//                  printf("%c\n", alphabet[index+offset]);             
                }
            }

//          printf("%c %d\n", text[i], index);



        } else {

//          printf("%c -1\n", text[i]);

        }



    }

}

// void main()
// {
//  char text[] = "Das ist das Haus vom Klaus";
//  caesar(text, 20);

//  for (int j = 0; j < strlen(text); j++ )
//  {
//      printf("%c", text[j] );
//  }
//  printf("\n");
// }
