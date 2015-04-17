#include <stdio.h>
#include <math.h>
#include <string.h>

#define ARRAYSIZE 600

//add a timeslot to the time array
void addToArray(char *minutes, int h1, int m1, int h2, int m2);

//get the largest free block in the array
void printLargestFreeBlock(char *minutes);

//print it like its hot
void printFormatHoursMinutes(int place, int size);

void addToArray(char *minutes, int h1, int m1, int h2, int m2)
{

		int hb, he;
		hb = ( (h1 - 8) * 60 ) + m1; //beginning of timeblock
		he = ( (h2 - 8) * 60 ) + m2; //end

		for (hb; hb < he; hb++) {

			minutes[hb] = 1;

		}

}

void printFormatHoursMinutes(int place, int size)
{

	int min = place % 60; // get minutes
	int hours = ((place - min) / 60 ) + 8; // get hours

	printf("Programmieren II- Aufgaben bearbeiten um %02d:%02d fuer %d Minuten.\n", hours, min, size);

}

void printLargestFreeBlock(char *minutes)
{

	int blockplace, blocksize, tmpplace, tmpsize, counting ;
	blockplace = blocksize = tmpplace = tmpsize = counting = 0;
	for (int i = 0; i < ARRAYSIZE; i++) //NO SKYLER, I AM THE ONE WHO ITERATES!
	{
		if ( minutes[i] == 0 ) {
			if ( counting == 0 ) { //not counting but found a free block, so count now
				tmpplace = i;
				counting = 1;

			}
			tmpsize++;
		} else {
			if ( counting == 1 ) { //was counting but the block is done, so stop that

//				printf("%d %d\n", blocksize, tmpsize);
				counting = 0;
				if ( tmpsize > blocksize ) { //and compare our biggest known block
					blocksize = tmpsize;
					blockplace = tmpplace;
				}
				tmpsize = 0;
				tmpplace = 0;
			}
		}
	}

	if ( tmpsize > blocksize ) {
		blocksize = tmpsize;
		blockplace = tmpplace;
	}

	//printf("%d %d\n", blockplace, blocksize);
	printFormatHoursMinutes(blockplace, blocksize); //print me baby one more time
}

int main(void)
{

	char minutes[ARRAYSIZE] = { 0 };

	// for(int i = 0; i < ARRAYSIZE; i++) {
 //        printf("%d ", minutes[i]);
	// }


	char buffer[60];
	int h1, m1, h2, m2;

	while (1)
	{
		fgets(buffer, 60, stdin);
		if (strlen(buffer) <= 1) { break; }
//		printf("%d\n", strlen(buffer));
		if ( sscanf ( buffer , "%d:%d %d:%d %*s ", &h1, &m1, &h2, &m2 ) == 4) {

//			printf("%d %d %d %d\n", h1, m1, h2, m2);
			addToArray(minutes, h1, m1, h2, m2);
			memset(buffer, 0, sizeof(buffer));

		}
	}
	printLargestFreeBlock(minutes);
	printf("Goodbye\n");
	// for(int i = 0; i < sizeof(minutes)/sizeof(minutes[0]); i++) {
 //        printf("%d", minutes[i]);
	// }
	return 0;
}
