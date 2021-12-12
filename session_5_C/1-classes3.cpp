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

class Rectangle: public Polygon { // Inherit 'Polygon' as the base clase for this derived class

	public:

		int x = 0;
		int y = 0;

};

int main(){
	
	Rectangle A; // Instantiate a Rectangle object

	return 0;
}


// Notice that the inherited base class "Polygon" constructor / destructor are called
// Rectangle is a type of Polygon which does not have its own constructor / destructor

