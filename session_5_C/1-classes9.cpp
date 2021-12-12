
/* Demonstration of the use of 'virtual' keyword for member functions of a base class
 *
 * The 'virtual' keyword allows us to have the compiler not to bind the function at compile time
 * but to wait and see what derived class it is called from. Only the definition can be changed
 * within the derived class, not the function prototype.
 *
 */ 

#include <iostream>

class Base{
	
	public: void print(void){ std::cout << "Hello from base class" << std::endl; } // Function prototype and definition

};

class Derived: public Base {

	public: void print(void){ std::cout << "Hello from derived class" << std::endl; }

};

int main(){

	Base* B = new Base();
	Derived* D = new Derived();
		
	B->print(); // Will print from the class which is pointed to as expected
	D->print();

	
	Base* Other = D; // Point to the poitner pointing to object instance "D" which is a derived class of Base

	Other->print(); // At compile time, although "Other" points to D (a derived class) it is of type Base*. The function is not 'virtual' so it does not look to the derived class for the overriden definition (same prototype).

	delete B;
	delete D;

	return 0;
}

// If we now change print() of the Base to be a virtual function, we will obtain the expected behavior for runtime (pointing to a Derived class).
