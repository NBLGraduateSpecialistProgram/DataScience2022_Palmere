// C++-style -- Implementation of namespaces and simplification of function calls

#include <iostream> // cout
#include <fstream>  // ifstream

int main(){

	std::ifstream in("Data.txt");

	if (!in){ printf("Could not access file."); return -1; }

	std::string l;

	int counter = 0;

	while (std::getline(in, l)){
    
    	counter++;
    
    	if (counter > 5){ break; }
    
    	std::cout << l << std::endl;
    
	}
	return 0;
}
