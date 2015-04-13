#include <stdio.h>
#include <string.h>
#include "caesar.h"
#include "anacae.h"

void anacae(char text[]) {


//     char str[] = "thequickbrownfoxjumpedoverthelazydog";
    char text1[] = "Xl ptk xbg lmktaexgw-dtemxk Tikbemtz, ngw wbx Nakxg lvaenzxgwkxbsxag. Pbglmhg Lfbma, wtl Dbgg tg wbx Uknlm zxshzxg, nf wxf lvaxnllebvaxg Pbgw sn xgmzxaxg, lvaenxiymx ktlva wnkva wbx Zetlmnxkxg wxk Obvmhkr Fbxmldtlxkgx, whva gbvam ktlva zxgnz, nf sn oxkabgwxkg, wtll fbm baf tnva xbg zkbxllbzxk Lmtnupbkuxe axkxbgpxamx.";

    char ch;
    int count[26] = {0};
    int maximum = count[0];
    int pos = 0;

   for(int i = 0; i < strlen(text1); i++) {
       text1[i] = tolower(text1[i]);
       for (int c = 0; c < 26; c++) {
           if (count[c] > maximum) {
                maximum = count[c];
                pos = c;
           }
       }
   }

    printf("%c %d", maximum, pos);
//     caesar(text, text[index]);
}
