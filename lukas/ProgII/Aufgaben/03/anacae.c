#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "caesar.h"

void anacae(char text[]) {

    int count[26] = { 0 };

    for(int i = 0; i < strlen(text); i++)
    {

        if ( isalpha(text[i]) )
        {

            char *e;
            int index;
            // get char position in alphabet
            e = strchr(alphabet, tolower(text[i]));
            index = (int)(e - alphabet);
            ++count[index];
        }

    }

    int maximum = count[0];
    int location = 0;

    for (int c = 0; c < 26; c++)
    {
        if (count[c] > maximum)
        {
            maximum  = count[c];
            location = c;
        }
    }

    char maxchar = alphabet[location];


    int rot = location - 4; // Position of e = 4

    caesar(text, rot);

}


// void main()
// {
//     char text[] = "Xl ptk xbg lmktaexgw-dtemxk Tikbemtz, ngw wbx Nakxg lvaenzxgwkxbsxag. Pbglmhg Lfbma, wtl Dbgg tg wbx Uknlm zxshzxg, nf wxf lvaxnllebvaxgPbgw sn xgmzxaxg, lvaenxiymx ktlva wnkva wbx Zetlmnxkxg wxk ObvmhkrFbxmldtlxkgx, whva gbvam ktlva zxgnz, nf sn oxkabgwxkg, wtll fbm baftnva xbg zkbxllbzxk Lmtnupbkuxe axkxbgpxamx.";

//     anacae(text);

//     for (int j = 0; j < strlen(text); j++ )
//     {
//         printf("%c", text[j] );
//     }
//     printf("\n");
// }
