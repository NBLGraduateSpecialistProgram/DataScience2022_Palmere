
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "10-analysis.h"

int main(int argc, char** argv){
	
	if (argc == 1 || argc > 2){
		std::cout << "Usage: ./program <file name>" << std::endl;
		return -1;
	}

	std::string fn = argv[1];
	
	std::vector< std::vector<float> > data;

	data = readlines(fn); // from 9-manip.h

	Numpy np; // from 8-numpy.h

	int rs = data.size();
	int cs = data[0].size();

	np.array(rs, cs);
	
	// Take values from file and allocate to our "Numpy" array
	for (int i = 0; i < data.size(); i++){
		for (int j = 0; j < data[i].size(); j++){
			np.data[i][j] = data[i][j];
		}
	}

	float sum = np.sum();
	float average = np.average();

	std::cout << "Sum: " << sum << std::endl;
	std::cout << "Average: " << average << std::endl;

	return 0;
}
