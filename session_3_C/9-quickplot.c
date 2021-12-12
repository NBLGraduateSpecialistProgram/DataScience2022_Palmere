#include <dislin.h>
#include <stdlib.h>

int main(){

	int size = 100;
	float x[size];
	float y[size];
	float z[size];

	for (int i = 0; i < size; i++){
		x[i] = rand() % 50;
		y[i] = rand() % 50;
	}
	
	// Scatter plot
	window(0, 0, 800, 800);
	scrmod("revers");    // White foreground
	qplsca(x, y, size);  // Quick scatter plot

	return 0;
}
