/* Implementing C struct to emulate NumPy behavior */

#include <stdio.h>
#include <stdlib.h>

typedef struct Numpy{

	// Declare various data types as attributes of the Numpy struct
	int rows, cols;
	float** data;

// Define numpy struct as a data type called 'np'
} np;

// Define a function which initializes and returns our new struct

struct Numpy* array(int rows, int cols){

	// Cast maloc to type 'np*' as required by C
	struct Numpy* mat = (np*)malloc(sizeof(np));

	// Defined matrix as pointer so arrow operator is required to access attribute values
	mat->rows = rows;
	mat->cols = cols;
	float** data = (float**)malloc(sizeof(float*) * rows);
	for (int i = 0; i < rows; i++){

		// Use calloc() here to 0 initialize our array
		data[i] = (float*)calloc(cols, sizeof(float));
	}
	mat->data = data;
	return mat;
}

void print(struct Numpy* a){
	for (int i = 0; i < a->rows; i++){
		for (int j = 0; j < a->cols; j++){
			printf("%f ", a->data[i][j]);
		}
		printf("\n");
	}
}

// Can provide arguments on the command line to determine matrix size if we want
int main(int argc, char** argv){
	
	if (argc > 3 || argc == 1){
		printf("Usage: ./program <# rows> <# cols>\n");
		return -1;
	}

	int nrows = atoi(argv[1]);
	int ncols = atoi(argv[2]);

	np* matrix = array(nrows, ncols);
	print(matrix);

	// Free allocated memory
	
	// Rule of thumb: free() required for each alloc()
	for (int i = 0; i < matrix->rows; i++){
		free(matrix->data[i]);
	}
	free(matrix->data);
	free(matrix);

	return 0;
}
