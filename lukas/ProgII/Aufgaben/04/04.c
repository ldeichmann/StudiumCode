# include <stdio.h>
# include <string.h>
 #define MAX 512

int main(int argc, char *argv[]) {
    if ( argc != 2 ) /* argc should be 2 for correct execution */
    {
        /* We print argv[0] assuming it is the program name */
        printf( "usage: %s filename\n", argv[0] );
    }
    else 
    {

    	char filename[MAX];
    	strcpy(filename, argv[1]);
		FILE *file;
		int words = 0;
		char hasAlpha = 0;
		int c;
		// Dateiname einlesen
//		fgets(filename, 81, stdin);
		// das \n aus Dateinamen entfernen
		filename[strcspn(filename, "\n")] = 0;
		file = fopen(filename, "r"); // oeffnen zum Lesen
		if (file == NULL) {

			printf("File is null\n");
			return(-1);

		}
		// FEHLER Datei kann nicht geoeffnet werden

		while((c = fgetc(file)) != EOF) {
//			printf("%d ", c);
			if (isalpha(c)) {

				hasAlpha = 1;

			} else if (c == '\n' || c == '\t' || c == '\r' || isspace(c)) {

				if (hasAlpha) {
					hasAlpha = 0;
					++words;
				}

			}
		}

    	printf("Count: %d - File: %s\n", words, filename);

		fclose ( file ); // Datei schliessen
	}
}