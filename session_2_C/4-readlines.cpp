// Generate and demonstrate the use of a readlines() function

#include <iostream>
#include <string>
#include <fstream>

float** readlines(const std::string& fn){

	// Create the file input stream using constructor (i.e. in(fn) )
	std::ifstream in(fn);

	// Check if input stream was able to be opened
	if (!in){ printf("Error: Could not access file."); exit(1); }

	int rc = 0; // Row count
	int cc = 0; // Col count

	std::string l; // String to contain line
	std::string d = " "; // Delimiter

	// While std::getline() get the number of rows and cols of the data 
	
	while (std::getline(in, l)){
		rc++;
		if (rc == 1){
			for (int i = 0; i < l.size(); i++){
				if (l[i] == ' '){
					cc++;
				}
			}
		}
	}

	cc = cc + 1; // # of cols = # spaces in string + 1

	in.close();

	// Now that sizes are known, we can allocated arrays for x and y cols
	
	float** data = new float*[rc];
	for (int i = 0; i < rc; i++){
		data[i] = new float[cc];
	}
	
	// Now place values as floats in the 'data' matrix and return
	
	std::fstream inagain(fn);
	
	int cl = 0; // Current line
	while (std::getline(inagain, l)){
		std::string x_str = l.substr(0, l.find(d));
		std::string y_str = l.erase(0, l.find(d) + d.length());
		data[cl][0] = atof(x_str.c_str());
		data[cl][1] = atof(y_str.c_str()); // Assuming 2 cols otherwise another nested loop would be required to check delimiter and remove until delimiter is not found
		cl++;
	}

	return data;
}

int main(){
	
	std::string fn = "Data.txt";
	float** data = readlines(fn);

	// Print some of the lines to show what data contains
	
	for (int i = 0; i < 5; i++){
		std::cout << data[i][0] << " " << data[i][1] << std::endl;
	}

	return 0;
}










