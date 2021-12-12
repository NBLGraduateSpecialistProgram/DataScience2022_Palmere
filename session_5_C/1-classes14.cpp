// Function template use 

#include <iostream>
#include <string>

template <class T> // Template instantiation (wait until runtime to find what class/type T needs to be
void print(T& a){
	std::cout << a << std::endl;
}

int main(){

	int x = 0;
	double y = 1.234;
	
	std::string s = "Hello World";
	
	print<int>(x); // Explicit type within template function
	print(x);

	print(y);
	print(s);

	return 0;

}
