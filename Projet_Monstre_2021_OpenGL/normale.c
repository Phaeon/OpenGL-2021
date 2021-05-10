#include "normale.h"

// n = v0 x v1 avec V0 = s2 - s1 et v1 = s0 - s1
normale * calcul_normale(float s0x, float s0y, float s0z, float s1x, float s1y, float s1z, float s2x, float s2y, float s2z) {
  normale * normale = malloc(sizeof(normale));
  float v0x = s2x - s1x; // 0
  float v0y = s2y - s1y; // 0
  float v0z = s2z - s1z; // -30
  float v1x = s0x - s1x; // 30
  float v1y = s0y - s1y; // 0
  float v1z = s0z - s1z; // 0
  normale->x = (v0y * v1z) - (v0z *v1y); // 900
  normale->y = (v0z * v1x) - (v0x *v1z); // 0
  normale->z = (v0x * v1y) - (v0y *v1x); // 0
  float norme = sqrtf(normale->x * normale->x + normale->y * normale->y + normale->z * normale->z);
  normale->x = normale->x / norme;
  normale->y = normale->y / norme;
  normale->z = normale->z / norme;
  return normale;
}
