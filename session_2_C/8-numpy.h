/* Header file defining Numpy class for 8-numpy.cpp */

#include <vector>

class Numpy{
	public:
		int rows, cols;
		std::vector< std::vector<float> > data;
		void array(int nrows, int ncols);
		void display(void);
};

void Numpy::array(int nrows, int ncols){

	this->rows = nrows;
	this->cols = ncols;

	std::vector<float> r;
	for (int i = 0; i < this->cols; i++){
		r.push_back(0);
	}

	for (int i = 0; i < this->rows; i++){
		this->data.push_back(r);
	}
}

void Numpy::display(void){
	for (int i = 0; i < this->rows; i++){
		for (int j = 0; j < this->cols; j++){
			std::cout << this->data[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
