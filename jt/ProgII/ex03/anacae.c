#include <stdio.h>
#include <string.h>
#include "caesar.h"
#include "anacae.h"

void anacae(char text[]) {


//     char str[] = "thequickbrownfoxjumpedoverthelazydog";
    char text1[] = "Xl ptk xbg lmktaexgw-dtemxk Tikbemtz, ngw wbx Nakxg lvaenzxgwkxbsxag. Pbglmhg Lfbma, wtl Dbgg tg wbx Uknlm zxshzxg, nf wxf lvaxnllebvaxg Pbgw sn xgmzxaxg, lvaenxiymx ktlva wnkva wbx Zetlmnxkxg wxk Obvmhkr Fbxmldtlxkgx, whva gbvam ktlva zxgnz, nf sn oxkabgwxkg, wtll fbm baf tnva xbg zkbxllbzxk Lmtnupbkuxe axkxbgpxamx.";
    char str[] = {0};


//     int array[256] = {0};
//     for(int i = 0; text1[i] != '\0'; i++) {
//         array[text1[i]]++;
//     }
//     int max = 0;
//     int maxchar;
//     for(int i = 0; i < 256; i++) {
//         if(array[i] > max) {
//                 max = array[i];
//                 maxchar = array[i];
//             }
//         }

   int max = 0;
    int count = 0;
    for(char q=' ';q<='~';q++)

    {
        count = 0;
        for(int i=0; i<strlen(text);i++)
        {
            if(text[i]==q)
                count++;
        }

        if(count == max)
        {
            maxCharacter += q;
        }

        if(count>max)
        {
            max=count;
            maxCharacter=q;
        }
    }
    printf("%d %c", maxchar);
//     caesar(text, text[index]);
}
