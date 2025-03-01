
 #include <HLS/hls.h>
 #include <HLS/ac_fixed.h>
 #include <HLS/ac_int.h>
 #include <stdio.h>
 #include <stdlib.h>
 
 #define WIDTH 80
 #define HEIGHT 40
 #define MAX_ITER 100
 //Datatype declaration, 16 bits, Integerpart 3 bits, unsigned
 //typedef ac_fixed<16,3,false> ac_16_3_f;
 typedef ac_fixed<32,3,false> ac_32_3_f;
 //typedef ac_fixed<64,3,false> ac_64_3_f;
 int iy = 1, ix = 1;
 
 // Function ihc::mm_master<int, ihc::aspace<1>, ihc::awidth<8>, ihc::dwidth<32> >& p1
 hls_avalon_slave_component // Instead of start-busy-done-stall
 component int mandelbrot(hls_avalon_slave_register_argument ac_32_3_f real0,hls_avalon_slave_register_argument ac_32_3_f imag) {
     ac_32_3_f z_real = 1.0f;
     ac_32_3_f z_imag = 0.0f;
     int iter;
    
     for (iter = 0; iter < MAX_ITER; iter++) {
         ac_32_3_f z_real2 = z_real * z_real;
         ac_32_3_f z_imag2 = z_imag * z_imag;
 
         if (z_real2 + z_imag2 > 4) {
         //if ((z_real2 + z_imag2).to_double() > 4.0f) {
             break;
         }
 
         z_imag = 2 * z_real * z_imag + imag; // 2.0f
         z_real = z_real2 - z_imag2 + real0;
     }
 
     return iter;
 }
 
 void draw_mandelbrot() {
     for (int y = 0; y < HEIGHT; y++) {
         for (int x = 0; x < WIDTH; x++) {
             ac_32_3_f real0 = (x - WIDTH / 2.0f) * 4.0f / WIDTH; // 80 = -2 -> +2
             ac_32_3_f imag = (y - HEIGHT / 2.0f) * 4.0f / HEIGHT; // 40 = -2 -> +2
             ac_32_3_f z_real = 1.0f;
             ac_32_3_f z_imag = 0.0f;
         
 
             int iter = mandelbrot(real0, imag);
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
         printf("IY=%i\n",iy);
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