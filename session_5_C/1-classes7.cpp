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

		void display(int nx, int ny){ // Overload the function from the base class (not override)

			// Set class instance attributes (static would render them class attributes we are familiar with in Python)
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

class Square : public Polygon {

	public:

		int x = 0;
		int y = 0;

		void display(int nxy){

			x = nxy;
			y = nxy;

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
	
	Rectangle A;
	Square B;

	Polygon* P1 = &A; // Polygon points to address of derived class Rectangle object "A";
	Polygon* P2 = &B; // Polygon points to address of derived class Square object "B";

	P1->display(4, 3); // Access the virutal function "template" of the base class which is overriden in the derived classes
	P2->display(5);    // Since P1 is a pointer to address held by "A" and "B", we access the member functions using "->" arrow

	return 0;
}

/* We will see that this does not work since Polygon class does not have the arugments / attributes appropriate for Rectangle or Square
 *
 * Diagram:
 *
 *											     [ DERIVED CLASS: void display ( int nx, int ny ) ]
 *                                             /
 *   [ BASE CLASS: void display( void ) ] --> /
 *                                            \
 *                                             \
 *                                               [ DERIVED CLASS: void display ( int nxy ) ]
 *
 *
 * What we would like instead is:
 *
 *                                                             [ DERIVED CLASS: void display ( void ) ]
 *                                                           /
 *   [ BASE CLASS: void display ( void ) { <action> } ] --> /
 *                                                          \
 *                                                           \
 *                                                             [ DERIVED CLASS: void display ( void ) ]
 *
 * This is the power of Polymorphism. We should not have to rewrite code for each derived class but instead, use the base class
 * as a "template" which is modified by the derived class. This will limit the amount of code we have to write while also making future
 * edits and appendages easier to implement.
 *
 *\


