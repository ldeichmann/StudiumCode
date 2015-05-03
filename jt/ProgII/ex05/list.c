#include "list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int listadditem(char** list, char* item, int* count, int capacity) {
    for (int i = 0; i < capacity; i++) {
        for (int j = 0; j < *count; j++) {
            strcpy(list[i][j],item[j]);

        }
    }
    printf("%s %s \n", *list, item);
    return 1;
}

int listfinditem(char** list, char* item, int count) {

}

int listdeleteitem(char** list, char* item, int* count) {

}

void listprint(char** list, int count) {
    for(size_t i = 0; i < count; i++) {
        printf("%c ", list[i]);
    }
}

void listfreeallitems(char** list, int count) {

}
