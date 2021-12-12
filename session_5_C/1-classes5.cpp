#include <iostream>

class Polygon{
	
	public:

		Polygon(){
			std::cout << "Polygon created." << std::endl;
		}

		~Polygon(){
			std::cout << "Polygon removed." << std::endl;
		}

		void display(void){  // We create a function to display the object as text
		
			std::cout << "Polygon has no display." << std::endl; // We have not defined the polygon we want to display
		
		}

};

class Rectangle: public Polygon {

	public:

		int x = 5;
		int y = 5;

		void display(void){ // Overload the function from the base class
			
			for (int i = 0; i < x; i++){
				std::cout << "-";
			}
			std::cout << std::endl;
			
			for (int j = 0; j < y; j++){
				for (int i = 0; i < x; i++){
					if (i == 0 || i == (x-1)){
						std::cout << "|";
					}
					else{
						std::cout << " ";
					}
				}
				std::cout << std::endl;
			}

			for (int i = 0; i < x; i++){
				std::cout << "-";
			}
			std::cout << std::endl;

		}

};

int main(){
	
	Rectangle A; // Instantiate a Rectangle "A"

	A.display(); // Call the overloaded function

	return 0;
}

// We have x, y attributes which we defined within the Rectangle class.
// What if we wanted to still have an overloaded display() function, but
// with arguments specifically suited for a Rectangle?
