#include <iostream>

class Polygon{

}; // Declare the class Polygon with no specified attributes

int main(){
	
	Polygon A;  // Instantiate 'A' as a polygon object

	return 0;
}

/*
 * We declared and defined the class Polygon with no data members. 
 * Similar to the Python data model, C++ also provides a default
 * constructor for instantiating the class. By providing our own
 * constructor / deconstructor, we will negate the implicit default
 * constructor from the compiler.
 *
 */

