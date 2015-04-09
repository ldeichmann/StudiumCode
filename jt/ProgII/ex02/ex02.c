#include <stdio.h>
#include <string.h>
#define TIMELENGTH 600

void convertToBinary( int *pTime, int h1, int m1, int h2, int m2 );

void countZeros( int *pTime, int length );

void intToTime(int pos, int cnt);

int main(void) {

    char buffer[60];
    int time[TIMELENGTH] = {0};
    int h1,h2,m1,m2;

    h1  = 0;
    h2  = 0;
    m1  = 0;
    m2  = 0;

    while(1) {

        if( fgets (buffer, 60, stdin) != NULL) {
            if(sscanf(buffer, " %d:%d %d:%d %*s ", &h1 , &m1 , &h2 , &m2 ) == 4){
                convertToBinary(time, h1, m1, h2, m2);
            }
        }

        if( strlen(buffer) <= 1) {break;}
   }
    countZeros( time, TIMELENGTH);
    return 0;
}

void convertToBinary( int *pTime, int h1, int m1, int h2, int m2 ) {
    int hBeginn, hEnd;

    hBeginn = ( (h1 - 8) * 60) + m1;
    hEnd    = ( (h2 - 8) * 60) + m2;

    for(hBeginn; hBeginn < hEnd; hBeginn++) {
        pTime[hBeginn] = 1;
    }
}

void countZeros( int *pTime, int length ) {
    int cnt, pos, tmpcnt, tmppos, iscnt;

    cnt     = 0;
    pos     = 0;
    tmpcnt  = 0;
    tmppos  = 0;
    iscnt   = 0;

    for(int i = 0; i < length ;i++){
        if(pTime[i] == 0) {
            if(iscnt == 0) {
                iscnt   = 1;
                tmppos  = i;
            }
            tmpcnt++;
        }
        else {
            if ( iscnt == 1) {
                iscnt = 0;
                if( tmpcnt > cnt) {
                   cnt = tmpcnt;
                   pos = tmppos;
                }
             tmpcnt = 0;
             tmppos = 0;
            }
        }
        if( tmpcnt > cnt) {
            cnt = tmpcnt;
            pos = tmppos;
        }
    }
   intToTime(pos, cnt);
}

void intToTime( int pos ,int cnt) {

    int minuten = pos % 60;
    int stunden = ((pos - minuten) / 60) + 8;

    printf("Programmieren II- Aufgaben bearbeiten um %02d:%02d fuer %d Minuten\n",stunden, minuten, cnt);

}
