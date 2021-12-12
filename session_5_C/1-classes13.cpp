#include <iostream>
#include <cmath>

class Base{
	
	friend class Derived; // Classes are separate (no inheritance) but Derived can now access attributes of Base

	private: int secret_number = 0;

};

class Derived{ // No longer inheriting so we cannot access within the class definition
	
	
	public:

		void secret(Base& A){ std::cout << "Secret Number: " << A.secret_number << std::endl; }

};

int main(){
	
	Base B;
	Derived D;

	D.secret(B); // We can now access the private secret_number attribute of Base
	
	return 0;
}
