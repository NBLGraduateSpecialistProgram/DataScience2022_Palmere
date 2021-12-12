#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dislin.h"

void format(void){
	window(0, 0, 1200, 800);
	metafl("cons");
	scrmod("revers");
}

void set_params(void){
	pagera();
	complx();	
}

void set_plot_left(void){
	
	float x[2] = {0, 25};
	float y[2] = {0, 25};

	axspos(600, 600); // Position of the subplot
	axslen(500, 500);	
	graf(0.0, 100, 0.0, 100, 0, 26, 0, 25);
	curve(x, y, 2);
	endgrf(); // set level back to 1 (DISLIN initialized)

	// if axspos() and axslen() placed here?
}

void set_plot_right(void){
	
	float x[3] = {0, 25, 50};
	float y[3] = {0, 10, 20};

	axspos(1500, 600);
	axslen(500, 500);
	graf(0.0, 100, 0.0, 100, 0, 26, 0, 25);
	color("red");
	curve(x, y, 3);
	endgrf();

}

int main ()
{
	format();
	disini();
	set_params();
	set_plot_left();
	set_plot_right();
	errmod("ALL", "OFF");
	disfin ();
  return 0;
}
