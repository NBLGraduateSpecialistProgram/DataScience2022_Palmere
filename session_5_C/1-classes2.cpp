#include <iostream>

class Polygon{
	
	public:
		Polygon(){ // Constructor
			std::cout << "Polygon created." << std::endl;
		}

		~Polygon(){ // Destructor
			std::cout << "Polygon removed." << std::endl;
		}

};

int main(){
	
	Polygon A;

	return 0;
}

// Notice that the destructor is called by default prior to the end of runtime (deallocates memory required by Polygon A on the stack).

