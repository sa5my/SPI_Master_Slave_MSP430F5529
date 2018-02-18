///////////////////////////////////////////////////////////////////////////////
//   Malcolm Ma
//   UT Dallas
//   Dec 2015
//   Built with CCSv6.1.1
//
//	 Version: v0.1
//
//  Description:
//  Simple UART program with only TX as RX is not used in this project
//	Simple polling implementation,the output data size should be less than 20.
//
//
//
//                 MSP430F552x
//             -----------------
//         /|\|                 |
//          | |                 |
//          --|RST              |
//            |                 |
//            |     P3.3/UCA1TXD|------------>
//            |                 | 115200 - 8N1
//            |     P3.4/UCA1RXD|<------------
///////////////////////////////////////////////////////////////////////////////

#ifndef UART_H
#define UART_H

void initUART();
void print(float data);
void println(float data);
void printchar(char data);
void printstring(char *buff,char length);
inline void sendUART(char *buff,unsigned char length);


#endif
