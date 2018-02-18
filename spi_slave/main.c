#include <msp430.h> 
#include "spi.h"
#include "UART.h"

/*
 * main.c
 */
char data;
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	spi_init();
	__delay_cycles(1045876/2);
	initUART();
	__delay_cycles(1045876/2);
while(1)
{
	while(!(UCB0IFG & UCRXIFG));
	data=UCB0RXBUF;
	printchar(data);
}
}
