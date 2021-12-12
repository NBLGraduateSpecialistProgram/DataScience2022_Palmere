
/* Demonstration of the use of private inheritance
 * 
 * Public inheritance allowed for the Derived class to be considered a subcategory of the Base class.
 * We will see that private inheritance of a Base class allows for implementation of Base class attributes
 * without those attributes being exposed to rest of the program.
 *
 */

#include <iostream>
#include <cmath>

class Base{
	
	public: double square(double x){ return pow(x, 2); }

};

class Derived: private Base {

	public: double distance(double x1, double x2, double y1, double y2){ return square((x2-x1)) + square((y2-y1)); }

};

int main(){

	Derived D;
	double distance = D.distance(0, 1, 0, 1);
	std::cout << "Distance: " << distance << std::endl;
	
	double sq = D.square(2);

	return 0;
}

// We can see that we are able to implement member functions of the Base class from within the Derived class.
// If we try to access this function directly from the Derived class, we will see that it is inaccessible.
