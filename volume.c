#include "math.h"
#include "tgmath.h"
#include "stdio.h"


double volume();

main()
{
  double vol;
  double theMod;

  vol = volume(12.2, 5.67, 9.03);
  printf("Volume: %f\n",vol);
  theMod = fmod(vol,100.0);
  printf("ratio of Volume and 100.0 is %f\n",vol/100.0);
}

double volume(double s1, double s2, double s3)
{
  return s1*s2*s3;
}
