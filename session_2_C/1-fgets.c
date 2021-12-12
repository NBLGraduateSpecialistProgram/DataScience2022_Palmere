// Read a file using C fgets()

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 100 // Define the length of a line of the file

int main(){



	const char fn[] = "Data.txt";

	FILE* fp = fopen(fn, "r"); // File pointer ('FILE' type is special in C)

	// In the event that the file name 'fn' cannot be accessed, fopen() will return a null pointer so we check

	if (fp == NULL){
    	printf("ERROR: could not access the file.");
    	return -1; // Indicate error when returning from main()
	}

	// We use char* fgets(char* str, int n, FILE* stream) to read lines

	char line[LENGTH];
	int line_counter = 0;

	while (fgets(line, LENGTH, fp) != NULL){ // Print out first 5 lines of the file
    
    	line_counter++;
    
    	if (line_counter > 5){ // Limit the output to the first 5 lines
        	break;
    	}
    
    	printf("%s", line);
	}

	fclose(fp);

return 0;
}
