#include <iostream>

class Polygon{
	
	public:

		Polygon(){
			std::cout << "Polygon created." << std::endl;
		}

		~Polygon(){
			std::cout << "Polygon removed." << std::endl;
		}

		virtual void display (void) {  // We create a function to display the object as text
		
			std::cout << "Polygon has no display." << std::endl; // We have not defined the polygon we want to display
		
		}

};

class Rectangle: public Polygon {

	public:

		int x = 0;
		int y = 0;

};

int main(){
	
	Rectangle A; // Instantiate a Rectangle "A"

	A.display(); // Call the inherited base class function "display"

	return 0;
}

