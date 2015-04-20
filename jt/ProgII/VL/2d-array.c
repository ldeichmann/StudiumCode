#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int numbers[3][5] = { { 1,2,3,4,5},
                        { 10,20,30,40,50},
                        {100,200,300,400,500}};
    int (*pnumbers)[5];
    pnumbers = &numbers[0][0];
    int i = 0;
    for (i = 0; i<3 ; i++) {
        printf("%p %p ", numbers + i , pnumbers + i);
        printf("%d %d\n", *(*(numbers+i)+i),
                          *(*(pnumbers +i) +i ));
    }
    return 0;
}
