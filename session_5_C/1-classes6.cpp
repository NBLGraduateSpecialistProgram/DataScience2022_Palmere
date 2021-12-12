#include <iostream>

class Polygon{
	
	public:

		Polygon(){
			std::cout << "Polygon created." << std::endl;
		}

		~Polygon(){
			std::cout << "Polygon removed." << std::endl;
		}

		void display(void){  // Define this as a virtual function
		
			std::cout << "Polygon has no display." << std::endl;
		
		}

};

class Rectangle: public Polygon {

	public:

		int x = 0;
		int y = 0;

		void display(int nx, int ny){

			x = nx;
			y = ny;
			
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

	A.display(4, 3); // Call the overloaded function

	return 0;
}

// What if we want to access the same object "type" but modify the behavior according to the derived object?

