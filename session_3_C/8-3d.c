#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
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

	graf3d(-100, 100, 0.0, 100, -100, 100, 0, 100, -100, 100, 0, 100); // graf 3d version
}

////////////////////////
/* Analysis functions */
////////////////////////

////////////////////////////////////////////
/* Generate and Plot data on axis systems */
////////////////////////////////////////////

void place_data(void){
	
	int iret = zbfini ();
	light("ON");
	litop3 (1, 0.5, 0.5, 0.5, "ambient");
	shdmod ("smooth", "surface");
	matop3 (1.0, 0.5, 0.0, "diffuse");
	sphe3d (-50, 50, 50, 25, 10, 10);
	sphe3d (50, 50, 50, 25, 10, 10);

}

int main ()
{
	format();
	disini();
	set_params();
	set_plot();
	place_data();
	errmod("ALL", "OFF");
	zbffin ();
	disfin ();
  return 0;
}
