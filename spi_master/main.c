#include <msp430.h> 
#include "spi.h"
#include <stdint.h>

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	uint8_t data='A';

	spi_init();
	
while(1)
{
        ENABLE_CHIP();
        spi_transmit(data++);
        DISABLE_CHIP()
        __delay_cycles(1045876);
}
}

