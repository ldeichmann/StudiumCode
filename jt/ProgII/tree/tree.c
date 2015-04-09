#include <stdio.h>
#define GRAPHSIZE 5

// int checkWay(int start, int ziel);

int main(void) {
    int graph[GRAPHSIZE][GRAPHSIZE] = {
            {1,0,0,0,0},
            {1,1,1,0,0},
            {0,1,0,1,0},
            {0,0,0,0,0}};
    int  bKnoten[GRAPHSIZE] = {0};
    char buffer[30];
    int  start   = 0;
    int  ziel    = 0;

    fgets(buffer, 30, stdin);
    printf("Start:");
    if(sscanf(buffer, "%d", &start) != 0) {
        printf("Falsche Eingabe");
    }

    fgets(buffer, 30, stdin);
    printf("\nZiel:");
    if(sscanf(buffer, "%d", &ziel) != 0){
        printf("Falsche Eingabe");
        return 1;
    }
}

int checkWay(int graph[][GRAPHSIZE], int bKnoten[], size_t size, int start, int ziel) {
    int result = 0;
    return graph[start][ziel];
}
