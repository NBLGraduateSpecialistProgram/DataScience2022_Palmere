#include <iostream>
#include <cmath>

class Base{
	
	private: int secret_number = 0;

	public: double square(double x){ return pow(x, 2); }

};

class Derived: protected Base { // Changing to 'protected' inheritance of Base class (can access public and protected attributes but not private)

	public: double distance(double x1, double x2, double y1, double y2){ return square((x2-x1)) + square((y2-y1)); }
	
	public: void secret(void){ std::cout << "Secret Number: " << secret_number << std::endl; }

};

int main(){

	Derived D;
	double distance = D.distance(0, 1, 0, 1);
	std::cout << "Distance: " << distance << std::endl;
		
	D.secret(); // We cannot access the secret_number from a protected base class with private attribute
	
	return 0;
}

// We still cannot access the public function of the Base class from the Derived class since it is protected when inherited (i.e. D.square(value) is inaccessible within main() ).
