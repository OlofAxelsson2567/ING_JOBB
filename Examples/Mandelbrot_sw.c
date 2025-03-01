// *********************************
/*!
  file          mandelbrot_sw.c
  company       HLS
  details       Simple mandelbrot
  date 			2025-03-01
 */



// ****************************** Mjukvarukomponent ***************************
#include "mandelbrot_sw.h"

int mandelbrot_sw(float real00,float imag0) {
    float z_real = 1.0f;
    float z_imag = 0.0f;
    int iter;

    for (iter = 0; iter < MAX_ITER; iter++) {
        float z_real2 = z_real * z_real;
        float z_imag2 = z_imag * z_imag;

        if (z_real2 + z_imag2 > 4.0f) {
        //if ((z_real2 + z_imag2).to_double() > 4.0f) {
            break;
        }

        z_imag = 2.0f * z_real * z_imag + imag0; // 2.0f
        z_real = z_real2 - z_imag2 + real00;
    }
    return iter;
}
// ****************************** Mjukvarukomponent ***************************




