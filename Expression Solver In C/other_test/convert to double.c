/* strtod example */
#include <stdio.h>
#include <stdlib.h>

int main ()
{
  char szOrbits[] = "365.24 29.53";
  char * pEnd;
  double d1, d2;
  d1 = strtod (szOrbits,&pEnd);
  d2 = strtod (pEnd,NULL);
  //printf ("The moon completes %.2lf orbits per Earth year.\n", d1/d2);
  printf ("|%f| , |%f|\n", d1 , d2);
  return 0;
}
