
#include "LCD.h"


void command(unsigned char cmd)
{
 RW = 0;
 RS = 0;
 LCD_PORT = cmd;
 EN = 1;
 delayUsingInstruction(20);
 EN = 0;
}

void write_data(unsigned char ch)
{
  RW = 0;
  RS = 1;
  LCD_PORT = ch;
  EN = 1;
  delayUsingInstruction(20);
  EN = 0;
}


