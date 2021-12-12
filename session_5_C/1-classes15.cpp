// Operator overloading

#include <iostream>

class Base{
	
	public: 
		int count;

		Base() : count(0) {}

		// Operator overloading : <return type> operator <symbol> (args) {}
		void operator ++ (){
			count = count + 1;
		}

};

int main(){

	Base A;
	Base B;

	++A;
	++B;

	std::cout << A.count << std::endl;
	std::cout << B.count << std::endl;

	return 0;

}

