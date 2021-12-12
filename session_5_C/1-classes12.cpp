/* Static Keyword */

#include <iostream>

class Base {

	public:
		inline static int x = 0; // 'inline' required otherwise we would have to define the static variable outside of the class

};


int main(){

	Base A;
	Base B;

	A.x = A.x + 1;

	std::cout << B.x << std::endl; // Addition to an instance is carried over to other instances

	return 0;
}
