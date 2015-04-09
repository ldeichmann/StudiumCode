#include <stdio.h>
#include <math.h>
#include <string.h>

void addToArray(char *minutes, int h1, int m1, int h2, int m2);
void printLargestFreeBlock(char *minutes);
void printFormatHoursMinutes(int place, int size);

void addToArray(char *minutes, int h1, int m1, int h2, int m2)
{

		int hb, he;
		hb = ( (h1 - 8) * 60 ) + m1;
		he = ( (h2 - 8) * 60 ) + m2;

		for (hb; hb < he; hb++) {

			minutes[hb] = 1;

		}

}

void printFormatHoursMinutes(int place, int size)
{

	int min = place % 60;
	int hours = ((place - min) / 60 ) + 8;

	printf("Programmieren II- Aufgaben bearbeiten um %02d:%02d fuer %d Minuten.\n", hours, min, size);

}

void printLargestFreeBlock(char *minutes)
{

	int blockplace, blocksize, tmpplace, tmpsize, counting ;
	blockplace = blocksize = tmpplace = tmpsize = counting = 0;
	for (int i = 0; i < 600; i++)
	{
		if ( minutes[i] == 0 ) {
			if ( counting == 0 ) {
				tmpplace = i;
				counting = 1;

			}
			tmpsize++;
		} else {
			if ( counting == 1 ) {

//				printf("%d %d\n", blocksize, tmpsize);
				counting = 0;
				if ( tmpsize > blocksize ) {
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
	printFormatHoursMinutes(blockplace, blocksize);
}

int main(void)
{

	char minutes[600] = { 0 };

	// for(int i = 0; i < 600; i++) {
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