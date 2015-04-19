#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    char s[512] = {0};
    FILE *f;
    int count = 0;

    //Case for direkt input
    if(argc == 1) {
        //Filename input
        fgets(s, 81, stdin);
        s[strcspn(s, "\n")] = 0;
        f = fopen(s, "r");
        printf("FILE: %s\t", s);
        //Errorhandle
        if(f == NULL) {
            printf("File nicht gefunden");
            return 1;
        }
        //wordcounting
        while( !feof(f)) {
            if(fscanf(f, "%80s", s) !=EOF ) {
                    count++;
            }
        }
    }
    //Case for argv input
    else if(argc == 2){
        //Filehandle
        f = fopen(argv[1], "r");
        printf("File: %s\t", argv[1]);
        //Errorhandle
        if(f == NULL) {
            printf("File nicht gefunden");
            return 1;
        }
        //wordcounting
         while(fscanf(f, "%80s", s) !=EOF ) {
                    count++;
         }
    }
    //output
    printf("count: %d", count);
}
