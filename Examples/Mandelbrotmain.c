// *********************************
/*!
  file          mandelbrot.c
  company       HLS
  details       Simple mandelbrot returning pixel and color.
                count increases by 1 when key_in is '1' then '0'.
  date changed  2022-06-01
 */
#include <stdio.h>
#include <stdlib.h>
#include "DE10_Lite_VGA_Driver.h"
#include "draw_vga.h"
#include "altera_avalon_timer_e_regs.h"
#include "Mandelbrotmain.h"

int main()
{
	// Test med 640 x 480 pixels driver
	clear_screen(Col_Black);
  printf("Hello from Nios II!\n");

	TIMER_RESET;
	TIMER_START;
  draw_mandelbrot();
  printf("Tidsåtgång=%i", TIMER_READ_NS);
  printf(" Nanosekunder\n");
  printf("Tidsåtgång=%i", TIMER_READ_S);
  printf(" Sekunder\n");
  printf("Tidsåtgång=%i", TIMER_READ_M);
  printf(" Minuter\n");
// För HW komponenten
// 11567247ns, SW 44879490
// 53 sekunder, SW 59
// 3 minuter, SW 12
  printf("Klar"); // Klar
  return 0;
}




