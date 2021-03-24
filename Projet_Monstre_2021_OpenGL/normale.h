#ifndef __NORMALE
#define __NORMALE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct {
  float x;
  float y;
  float z;
} normale;
 
// n = v0 x v1 avec V0 = s2 - s1 et v1 = s0 - s1
normale * calcul_normale(float s0x, float s0y, float s0z, float s1x, float s1y, float s1z, float s2x, float s2y, float s2z);
#endif