/* Implementing C++ class to emulate NumPy behavior */


#include <iostream>
#include <vector>
#include "8-numpy.h" // Class and function attributes declared here

void print(Numpy obj){
	for (int i = 0; i < obj.rows; i++){
		for (int j = 0; j < obj.cols; j++){
			std::cout << obj.data[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main(int argc, char* argv[]){
	
	if (argc == 1 || argc < 3){
		std::cout << "Usage: ./program <# rows> <# cols>" << std::endl;
		return -1;
	}

	int nrows = atoi(argv[1]);
	int ncols = atoi(argv[2]);

	// Declare Numpy object as np;
	Numpy np;
	
	np.array(nrows, ncols);

	print(np);

	// No need to free now that memory allocation and deallocation is handled
	// by std::vector
	
	return 0;
}
