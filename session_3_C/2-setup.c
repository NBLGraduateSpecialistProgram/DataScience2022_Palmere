#include <stdio.h>
#include <math.h>
#include "dislin.h"

int main ()
{

  window(0, 0, 1200, 800); // X11 Window spawns at (0, 0) top left of screen with size 1200x800 pixels
  metafl ("cons");         // Metafile information goes to console
  scrmod ("revers");     // Set background color to white and foreground to black
  disini ();               // Initialize DISLIN with default plot parameters
  pagera ();               // Plots border around the page
  complx ();               // Sets font to 'Complex'
  errmod ("ALL", "OFF");   // Turn off warnings and error output from disfin();
  disfin ();               // Terminate DISLIN
  return 0;
}
