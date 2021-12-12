// C-style using fgetc() and feof() 

#include <stdio.h>
#include <stdbool.h>

int main(){

	FILE *f;
	f = fopen("Data.txt", "r");

	int counter = 0;
	int ll;

	if (f == NULL){ printf("ERROR: could not access the file."); return -1; }

	do{
    	ll = fgetc(f);
    
    	counter++;
    	if (feof(f)){ break; } // feof() returns an unsigned value (>0) when the end of file (eof) is reached
    
    	if (counter <= 5){ printf("%c", ll); }
    
	} while(true);

	fclose(f);

	return 0;
}

// Does not print out the first 5 lines of the file since fgetc() gets characters of the line from the file stream.
// We would need an additional loop to get all the characters of the line
