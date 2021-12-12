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

int main ()
{
	format();
	disini();
	set_params();
	set_plot();

	int frames = 0;
	float x[100];
	float y1[100], y2[100];
	
	while (frames != 100){
		frames++;
	
		for (int i = 0; i < 100; i++){
			x[i] = i;
			y1[i] = rand() % 50;
			y2[i] = rand() % 50;
		}

		curve(x, y1, 100);
		sendbf();
	}
	endgrf();
	set_params();
	set_plot();
	setrgb(0, 0, 0);
	curve(x, y1, 100);
	errmod("ALL", "OFF");
	disfin ();
  return 0;
}
