#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "caesar.h"

int main(void) {
    char testStr[] = {0};
//     char testStr[] = "FH Luebeck";
    char testStr2[] = {0};
    char in;

//     char testStr2[] = "Xl ptk xbg lmktaexgw-dtemxk Tikbemtz, ngw wbx Nakxg lvaenzxgwkxbsxag. Pbglmhg Lfbma, wtl Dbgg tg wbx Uknlm zxshzxg, nf wxf lvaxnllebvaxg Pbgw sn xgmzxaxg, lvaenxiymx ktlva wnkva wbx Zetlmnxkxg wxk Obvmhkr Fbxmldtlxkgx, whva gbvam ktlva zxgnz, nf sn oxkabgwxkg, wtll fbm baf tnva xbg zkbxllbzxk Lmtnupbkuxe axkxbgpxamx.";

    printf("1 crack Caesar String\n");
    printf("2 'encrypt' String\n");
    printf("3  exit\n");
    printf("Select:\n");



    fgets(testStr, 200, stdin);
    if ( sscanf ( testStr , "%c", &in ) == 1) {

        switch(in) {
        case'1':
            printf("Enter String\n");

            fgets(testStr, 200, stdin);

            anacae(testStr);
            printf("%s", testStr);

            printf("\n");
            break;

        case'2':
            printf("Enter Rotation\n");
            char index;
            fgets(testStr, 200, stdin);

            if ( sscanf ( testStr , "%c", &index) == 1) {
                printf("Enter String\n");
                fgets(testStr, 200, stdin);

                caesar(testStr, index);

                printf("%s", testStr);

            }
            printf("bye\n");

            break;

        case '3':
            printf("bye\n");
            break;

        default:
            printf("bye\n");
            break;
        }
    }
}
