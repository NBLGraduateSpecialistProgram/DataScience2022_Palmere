/* Implementing C++ class to emulate NumPy behavior */


#include <iostream>

class Numpy{
	public: // private by default
		int rows, cols;
		float** data;
		Numpy array(int nrows, int ncols);
};

Numpy Numpy::array(int nrows, int ncols){ // Scope resolution operator

	Numpy obj;
	obj.rows = nrows;
	obj.cols = ncols;
	obj.data = new float*[obj.rows];
	for (int i = 0; i < obj.rows; i++){
		obj.data[i] = new float[obj.cols];
	}

	for (int i = 0; i < obj.rows; i++){
		for (int j = 0; j < obj.cols; j++){
			obj.data[i][j] = 0;
		}
	}

	return obj;
}

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
	
	Numpy array = np.array(nrows, ncols);

	print(array);

	// Free allocated memory
	for (int i = 0; i < nrows; i++){
		delete[] array.data[i];
	}
	delete[] array.data;

	// 'Delete[]' operator deallocates memory and calls destructors for array of objs
	// 'Delete' for single obj created with 'new' keyword

	return 0;
}
