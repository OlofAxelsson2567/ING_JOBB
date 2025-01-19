/*!
  file          mandelbrot.c
  company       HLS
  details       Simple mandelbrot returning pixel and color.
                count increases by 1 when key_in is '1' then '0'.
  date changed  2022-06-01
 */

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 40
#define MAX_ITER 1000
int iy = 1, ix = 1;

// Function
int mandelbrot(double real, double imag) {
    double z_real = 1.0;
    double z_imag = 0.0;
    int iter;

    for (iter = 0; iter < MAX_ITER; iter++) {
        double z_real2 = z_real * z_real;
        double z_imag2 = z_imag * z_imag;

        if (z_real2 + z_imag2 > 4.0) {
            break;
        }

        z_imag = 2.0 * z_real * z_imag + imag;
        z_real = z_real2 - z_imag2 + real;
    }

    return iter;
}

void draw_mandelbrot() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double real = (x - WIDTH / 2.0) * 4.0 / WIDTH;
            double imag = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;

            int iter = mandelbrot(real, imag);
            if (iter == MAX_ITER) {
            	//tty_print(ix, iy, "#", Col_Magenta, Col_Black);
            	
            	//draw_hline(ix,iy,1,Col_White);
            	//ix +=1;
                printf("#"); // Point is in the Mandelbrot set
            } else {
            	//tty_print(ix, iy, " ", Col_Magenta, Col_Black);
            	ix +=1;
                printf(" "); // Point is not in the Mandelbrot set
            }
        }
        //printf("IY=%i\n",iy);
        iy += 1;
        ix = 1;
    }
}
// Main function
int main() {
	//clear_screen(Col_Black);
    draw_mandelbrot();
    return 0;
}
