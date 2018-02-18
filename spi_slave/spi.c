#include "spi.h"

void spi_init()
{
P2SEL |= BIT7;                            // UCB0 Slave Transmit Enable
P3SEL |= BIT0+BIT1+BIT2;                  // P3.0= SIMO, P3.1= SOMI, P3.2= UCB0CLK
UCB0CTL1 |= UCSWRST;                      // **Put state machine in reset**
UCB0CTL0 |= UCSYNC+UCCKPH+UCMSB+UCMODE_2;          // 3-pin, 8-bit SPI SLave,Clock polarity high, MSB
//UCA0CTL1 |= UCSSEL_2;                     // SMCLK
//UCA0BR0 = 0x02;                           // /2
//UCA0BR1 = 0;                              //
//UCB0MCTL = 0;                             // No modulation
UCB0CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
}

uint8_t spi_transmit(uint8_t data)
{
    UCB0TXBUF = data;
    while(!(UCB0IFG & UCTXIFG));
    return UCB0TXBUF;
}
