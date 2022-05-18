#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dislin.h"

// DISLIN formatting (global parameters)
void format(void){
	window(0, 0, 1200, 800);
	metafl("cons");
	scrmod("revers");
}

// Set page parameters for X11 display
void set_params(void){
	pagera();
	complx();	
}

// Place the axis systems
void set_plot(void){

	graf(0.0, 100, 0.0, 100, 0, 26, 0, 25); // Does heavy lifting of placing x,y axis on the page
	
}

// Generate and Plot data on axis systems
void place_data(void){
	
	float x[100];
	float y1[100], y2[100];
	
	for (int i = 0; i < 100; i++){
		x[i] = i;
		y1[i] = ((float) rand() / (RAND_MAX)) + 15;
		y2[i] = ((float) rand() / (RAND_MAX)) + 15;
	}
	
	linwid(10); // Set the linewidth for lines
	curve(x, y1, 100); // Plot x, y data using 100 points
	color("red");
	curve(x, y2, 100); // matplotlib.pyplot.plot()
}

int main ()
{
	format();
	disini();
	set_params();
	set_plot();
	place_data();
	errmod("ALL", "OFF");
	disfin ();
  return 0;
}
