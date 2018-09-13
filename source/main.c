
#include <LEDs_and_SWs.h>
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"


int main(void) {

	//SIM->SCGC5   |= 0x1400;
	CLOCK_EnableClock(kCLOCK_PortB);//Habilitar clock para el puerto b
	CLOCK_EnableClock(kCLOCK_PortD);//Comentario2 prueba
	PORTB->PCR[18]= 0x100;//Ptb18 como gpio.....................
	PORTB->PCR[19]= 0x100;

	GPIOB->PDOR	  = 0xC0000;//Primer Branch, Segundo Branch
	//GPIOB->PDOR	  = 0x40000;
	//GPIOB->PDOR	  = 0x80000;
	GPIOD->PDOR	  = 0x1;
	GPIOB->PDDR	  =0x40000;
	GPIOB->PDDR	  =0x80000;
	GPIOD->PDDR	  =0x1;


	Colors_t color_selector = RED;

	BOARD_InitBootPins();

    while(1) {

    	//color_selector = Color_get_next_color();

    	switch (color_selector) {
			case RED:
				Color_Red();
				delay(65000);
				color_selector++;
				break;
			case BLUE:
				Color_Blue();
				delay(65000);
				color_selector++;
				break;
			case GREEN:
				Color_Green();
				delay(65000);
				color_selector++;
				break;
			case YELLOW:
				Color_yellow();
				delay(65000);
				color_selector++;
				break;
			case WHITE:
				Color_white();
				delay(65000);
				color_selector = 0;
				break;
			default:
				Color_OFF();
				break;
		}


    }
    return 0 ;
}
