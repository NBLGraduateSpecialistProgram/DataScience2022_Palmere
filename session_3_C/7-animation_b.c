#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dislin.h"
#include <string.h>

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

////////////////////////////////////////////
/* Generate and Plot data on axis systems */
////////////////////////////////////////////

void set_data(float* x, float* y){
	for (int i = 0; i < 100; i++){
		float itx = i;
		float ity = rand() % 50;
		*x = itx;
		*y = ity;
		x++;
		y++;
	}
}
void place_data(float* x, float* y, char* onoff){
	
	if (strcmp(onoff, "ON") == 0){
		color("WHITE");
	}

	if (strcmp(onoff, "OFF") == 0){
		color("BLACK");
	}

	curve(x, y, 100);
}

int main ()
{
	format();
	disini();
	
	int frames = 0;
	float x[100];
	float y1[100];
	set_plot();
	set_params();
	while (frames != 100){
		frames++;
		set_data(&x[0], &y1[0]);
		place_data(x, y1, "ON");
		sendbf();       // Send updated buffer to the screen
		place_data(x, y1, "OFF");
		//endgrf(); 		// Terminate axis system and set level back to 1
	}
	place_data(x, y1, "ON");
	sendbf();
	errmod("ALL", "OFF");
	disfin ();
  return 0;
}
