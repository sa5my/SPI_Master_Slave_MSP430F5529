#include <msp430f5529.h>
#include <stdint.h>

#ifndef SPI_H_
#define SPI_H_


#define ENABLE_CHIP() P3OUT &= ~BIT3;
#define DISABLE_CHIP() P3OUT |= BIT3;

void spi_init();
uint8_t spi_transmit(uint8_t data);



#endif /* SPI_H_ */
