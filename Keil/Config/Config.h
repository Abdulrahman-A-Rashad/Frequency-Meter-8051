#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <reg51.h>



sbit EN = P2^1; // Enable LCD
sbit RW = P2^2; // Read Write 
sbit RS = P2^0; // Register Select
sbit signal_pin = P3^5;  // External signal input

#define LCD_PORT P1

#endif