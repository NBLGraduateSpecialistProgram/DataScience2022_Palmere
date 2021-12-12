/* Header File for 10-analysis.cpp */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::vector< std::vector<float> > readlines(const std::string& fn){
	std::ifstream in(fn);
	if (!in){ printf("Error: Could not access file."); exit(1); }
	std::string l;
	std::string d = " ";
	std::vector< std::vector<float> > data;
	while (std::getline(in, l)){
		std::vector<float> row;
		std::string x_str = l.substr(0, l.find(d));
		std::string y_str = l.erase(0, l.find(d) + d.length());
		row.push_back(atof(x_str.c_str()));
		row.push_back(atof(y_str.c_str()));
		data.push_back(row);
		row.clear();
	}
	return data;
}

class Numpy{
	public:
		int rows, cols;
		std::vector< std::vector<float> > data;
		void array(int nrows, int ncols);
		void display(void);

		// Now we can add arbitrary number of analysis functions
		float sum(void);
		float average(void);

};

// 'this' keyword isn't required but is explicit
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

float Numpy::sum(void){
	float s = 0;
	for (int i = 0; i < this->cols; i++){
		for (int j = 0; j < this->rows; j++){
			s += this->data[i][j];
		}
	}
	return s;
}

float Numpy::average(void){
	float s = 0;
	for (int i = 0; i < this->cols; i++){
		for (int j = 0; j < this->rows; j++){
			s += this->data[i][j];
		}
	}
	float avg = s / (this->cols * this->rows);
	return avg;
}
