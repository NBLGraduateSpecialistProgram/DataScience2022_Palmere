#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dislin.h"

///////////////////////////////////////////
/* DISLIN formatting (global parameters) */
///////////////////////////////////////////

void format(void){
	window(0, 0, 1200, 800);
	metafl("cons");
	scrmod("revers");
}

/////////////////////////////////////////
/* Set page parameters for X11 display */
/////////////////////////////////////////

void set_params(void){
	pagera();
	complx();
}

////////////////////////////
/* Place the axis systems */
////////////////////////////

void set_plot(void){

	graf(0.0, 100, 0.0, 100, 0, 100, 0, 100); // Does heavy lifting of placing x,y axis on the page
	polcrv("SPLINE"); // Applies spline interpolation to all curves
}

////////////////////////
/* Analysis functions */
////////////////////////

////////////////////////////////////////////
/* Generate and Plot data on axis systems */
////////////////////////////////////////////

void place_data(void){
	
	float x[100];
	float y1[100], y2[100];
	
	for (int i = 0; i < 100; i++){
		x[i] = i;
		y1[i] = ((float) rand() / (RAND_MAX)) + 15;
		y2[i] = ((float) rand() / (RAND_MAX)) + 15;
	}
	
	curve(x, y1, 100);
	color("red");
	curve(x, y2, 100);
	
	color("FORE");
	char legbuf[6];   // String for Legend Contents
    legini(legbuf, 2, 6); // 2 line of text containing 6 characters each
    leglin(legbuf, "Data 1", 1);
    leglin(legbuf, "Data 2", 2);
    legtit ("Legend Title");
    legend(legbuf, 7); // 7 indicates upper right corner of axis system

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
