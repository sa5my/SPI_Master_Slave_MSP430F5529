#include "spi.h"

void spi_init()
{
P3DIR |= BIT3;                            // Set P3.3 as output for slave select
P3SEL |= BIT0+BIT1+BIT2;                  // P3.3,4 option select
UCB0CTL1 |= UCSWRST;                      // **Put state machine in reset**
UCB0CTL0 |= UCMST+UCSYNC+UCCKPH+UCMSB;    // 3-pin, 8-bit SPI master,Clock polarity high, MSB
UCB0CTL1 |= UCSSEL_2;                     // SMCLK
UCB0BR0 = 0x02;                           // /2
UCB0BR1 = 0;                              //
//UCB0MCTL = 0;                             // No modulation
UCB0CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
}

uint8_t spi_transmit(uint8_t data)
{
    UCB0TXBUF = data;
    while(!(UCB0IFG & UCTXIFG));
    return UCB0TXBUF;
}
