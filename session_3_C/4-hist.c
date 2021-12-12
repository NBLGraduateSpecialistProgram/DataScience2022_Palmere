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

	graf(0.0, 20, 0.0, 20, 0, 20, 0, 20); // Does heavy lifting of placing x,y axis on the page
	
}

////////////////////////
/* Analysis functions */
////////////////////////

float min(const float* array, int size){
	float min_;
	for (int i = 0; i < size; i++){
		if (i == 0){
			min_ = array[i];
		}
		if (array[i] < min_){
			min_ = array[i];
		}
	}
	return min_; 
}

float max(const float* array, int size){
	float max_ = 0;
	for (int i = 0; i < size; i++){
		if (i == 0){
			max_ = array[i];
		}
		if (array[i] > max_){
			max_ = array[i];
		}
	}
	return max_;
}

void print(float* array, int size){
    for (int i = 0; i < size; i++){
        printf("%f ", array[i]);
    }
    printf("\n");
}

float* histogram(const float* ys, int size, int bins){

	float sum = 0;
	int bin_size;
	
	// Check bin size
	if (bins <= size){
		bin_size = (size)/(bins);
	}
	else{
		printf("Error: too many bins for array of size %d.", size);
		exit(1);
	}
	
	// Set bin values
	float xb[bin_size];
	float step = (max(ys, 100) - min(ys, 100))/bin_size;
	for (int i = 0; i < bin_size; i++){
		if (i > 0){
			xb[i] = xb[i-1] + step;
		}
		else{
			xb[i] = min(ys, 100);
		}
	}

	float* xh = (float*)malloc(sizeof(float)*bin_size); // bin heights

	for (int i = 0; i < bin_size; i++){
		int sum_ = 0;
		for (int j = 0; j < size; j++){
			if (i > 0){
				if (ys[j] <= (xb[i]) && ys[j] >= (xb[i-1])){
					sum_ += 1;
				}
			
			}
		}
		xh[i] = sum_;
	}
	
	return xh; 
}

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

	// Calculate histogram for plotting
	int bins = 10;
	float* h1 = histogram(y1, 100, bins);
	float* h2 = histogram(y2, 100, bins);

	float hx[bins];
	for (int i = 0; i < bins; i++){
		hx[i] = i+1;
	}
	
	// Bar plot of the data
	float xhb[bins];
	for (int i = 0; i < bins; i++){
		xhb[i] = 0;
	}
	
	bars(hx, xhb, h1, bins);
	bars(hx, xhb, h2, bins);

	free(h1);
	free(h2);

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
