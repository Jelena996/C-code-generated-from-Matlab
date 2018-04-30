/*
 * File: fir_direct_transpose.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 13-Jan-2018 05:29:37
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "fir_direct_transpose.h"

/* Function Definitions */

/*
 * Arguments    : const short b[91]
 *                const short x[256]
 *                short y[91]
 * Return Type  : void
 */
void fir_direct_transpose(const short b[91], const short x[256], short y[91])
{
  short x1[91];
  short h1[91];
  int i0;
  int i;
  short b_x[91];
  int medju[91];
  int i1;
  int b_i1;
  int i2;
  int i3;
  for (i0 = 0; i0 < 91; i0++) {
    x1[i0] = 0;
    h1[i0] = 0;

    /* medju=cast((zeros(1,m)),'like',T.y); */
    y[i0] = 0;
  }

  for (i = 0; i < 256; i++) {
    b_x[0] = x[i];
    memcpy(&b_x[1], &x1[0], 90U * sizeof(short));
    memcpy(&x1[0], &b_x[0], 91U * sizeof(short));
    if (1 + i <= 91) {
      h1[i] = b[i];
    }

    for (i0 = 0; i0 < 91; i0++) {
      i1 = x1[i0] * h1[i0];
      if ((i1 & 8388608) != 0) {
        medju[i0] = i1 | -8388608;
      } else {
        medju[i0] = i1 & 8388607;
      }
    }

    for (b_i1 = 0; b_i1 < 90; b_i1++) {
      i0 = medju[89 - b_i1];
      i1 = medju[90 - b_i1];
      if ((i0 & 16777216) != 0) {
        i2 = i0 | -16777216;
      } else {
        i2 = i0 & 16777215;
      }

      if ((i1 & 16777216) != 0) {
        i3 = i1 | -16777216;
      } else {
        i3 = i1 & 16777215;
      }

      i0 = i2 + i3;
      if ((i0 & 16777216) != 0) {
        i0 |= -16777216;
      } else {
        i0 &= 16777215;
      }

      if (i0 > 8388607) {
        i0 = 8388607;
      } else {
        if (i0 < -8388608) {
          i0 = -8388608;
        }
      }

      medju[89 - b_i1] = i0;
    }

    i0 = medju[0];
    i0 = (i0 + 512) >> 10;
    if (i0 > 2047) {
      i0 = 2047;
    } else {
      if (i0 < -2048) {
        i0 = -2048;
      }
    }

    y[i] = (short)i0;
  }
}

/*
 * File trailer for fir_direct_transpose.c
 *
 * [EOF]
 */
