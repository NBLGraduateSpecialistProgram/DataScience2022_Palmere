// Store values as type float in separate arrays

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::vector< std::vector<float> > readlines(const std::string& fn){

	// Create the file input stream using constructor (i.e. in(fn) )
	std::ifstream in(fn);

	// Check if input stream was able to be opened
	if (!in){ printf("Error: Could not access file."); exit(1); }

	std::string l; // String to contain line
	std::string d = " "; // Delimiter

	// * Use of std::vector *
	
	std::vector< std::vector<float> > data;

	// While std::getline() get the number of rows and cols of the data 
	
	while (std::getline(in, l)){
		std::vector<float> row;
		std::string x_str = l.substr(0, l.find(d));
		std::string y_str = l.erase(0, l.find(d) + d.length());
		row.push_back(atof(x_str.c_str()));
		row.push_back(atof(y_str.c_str())); // push_back() (append() in Python)
		data.push_back(row);
		row.clear();
	}

	return data;
}

int main(){
	
	std::string fn = "Data.txt";
	std::vector< std::vector<float> > data = readlines(fn);

	// Print some of the lines to show what data contains
	
	for (int i = 0; i < 5; i++){
		std::cout << data[i][0] << " " << data[i][1] << std::endl;
	}

	// Notice std::vector manages memory allocation/deallocation
	// In 4-readlines.cpp we allocated using 'new', but we never freed the memory

	return 0;
}










