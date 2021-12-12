#include <stdio.h>
#include <math.h>
#include "dislin.h"

float zmat[50][50], xray[50], yray[50], zlev[20];

int main ()
{ int n = 50 ,i, j, nlev = 20;
  double fpi = 3.1415927 / 180.0, step, x, y;
  char *ctit1 = "Shaded Surface / Contour Plot",
       *ctit2 = "F(X,Y) = 2*SIN(X)*SIN(Y)";

  step = 360.0 / (n - 1);
  for (i = 0; i < n; i++)
  { x = i * step;
    xray[i] = (float) x;
    for (j = 0; j < n; j++)
    { y = j * step;
      yray[j] = (float) y;
      zmat[i][j] = (float) (2 * sin (x * fpi) * sin (y * fpi));
    }
  }

  scrmod ("revers");
  setpag ("da4p");
  metafl ("cons");
  disini ();
  pagera ();
  hwfont ();
  window(0, 0, 800, 800);
  axslen (800, 800);
  axspos(600, 1200);

  name   ("X-axis", "x");
  name   ("Y-axis", "y");
  name   ("Z-axis", "z");

  titlin (ctit1, 2);
  titlin (ctit2, 4);

  graf3d (0.0, 360.0, 0.0, 90.0, 0.0, 360.0, 0.0, 90.0,
            -2.0, 2.0, -2.0, 1.0);
  height (50);
  title  ();

  grfini (-1.0, -1.0, -1.0, 1.0, -1.0, -1.0, 1.0, 1.0, -1.0);
  nograf ();
  graf   (0.0, 360.0, 0.0, 90.0, 0.0, 360.0, 0.0, 90.0);
  step = 4.0 / nlev;
  for (i = 0; i < nlev; i++)
    zlev[i] = (float) (-2.0 + i * step); 

  conshd (xray, n, yray, n, (float *) zmat, zlev, nlev);
  box2d  ();
  reset  ("nograf");
  grffin ();

  shdmod ("smooth", "surface"); 
  surshd (xray, n, yray, n, (float *) zmat);
  errmod("ALL","OFF");
  disfin ();
  return 0;
}
