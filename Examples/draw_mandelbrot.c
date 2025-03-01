// *********************************
/*!
  file          draw_mandelbrot.c
  company       HLS
  details       Simple mandelbrot prints a pixel if value in the mandelbrot.

  date          2025-03-01
 */

#include "draw_mandelbrot.h"
int iy = 0, ix = 0 , iter = 0, sw = 1;  // Välj HW komponent med 0 och SW komponent med 1

void draw_mandelbrot() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            float real0 = (x - WIDTH / 2.0) * 4.0 / WIDTH;
            float imag = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;

            if (sw == 0){
				// Disable interrupt and clear interrupt status register
				int* ptr1 = &real0; // Deklarera och tilldela pekare adressen för real0
				int* ptr2 = &imag; // Deklarera och tilldela pekare adressen för imag

				MANDELBROT_disable_interrupt();
				MANDELBROT_clear_done_status();

				//printf("Vänta not busy\n");
				while (MANDELBROT_busy()){}                      // Wait until not busy
				//printf("Ladda data\n");
				MANDELBROT_WRITE_REAL0_REG(*ptr1); // Skriv data till minnesadresser ( pekare )
				MANDELBROT_WRITE_IMAG_REG(*ptr2); // Om man inte gör såhär blir datan korrupt i denna komponent

				//printf("Starta\n");
				MANDELBROT_start();                              // Start component
				//printf("Vänta på done\n");
				while (!(MANDELBROT_done())){}                   // Wait until component done

				//printf("Läs data\n");

				iter = MANDELBROT_returndata();
			}
            if (sw == 1){
            	iter = mandelbrot_sw(real0, imag);
            }

            if (iter == MAX_ITER) {
            	draw_hline(ix,iy,1,Col_White);
            	//ix +=1;
                //printf("#"); // Point is in the Mandelbrot set
            } else {
            	draw_hline(ix,iy,1,Col_Yellow);
            	//tty_print(ix, iy, " ", Col_Magenta, Col_Black);
            	//ix +=1;
                //printf(" "); // Point is not in the Mandelbrot set
            }
            ix +=1;
        }
        printf("IY=%i\n",iy);
        iy += 1;
        ix = 1;
    }
}




