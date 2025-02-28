#include <reg51.h>
#include "define_ports.h"
#include "delay.h"
#include "lcd.h"


unsigned int pulse_count = 0;
unsigned int frequency = 0;

void timer0_isr() interrupt 1 
	{
    TR0 = 0; 
    TR1 = 0;  

    pulse_count = TH1;  
    pulse_count = (pulse_count << 8) | TL1;
    
    frequency = pulse_count * 20; 

    TH0 = 0x3C;
    TL0 = 0xB0;
    
    TH1 = 0;  
    TL1 = 0;

    TR0 = 1;  
    TR1 = 1;  
  }

void setup_timers() 
	{
    TMOD = 0x51;  
    
    TH0 = 0x4B;  
    TL0 = 0xFD;

    TH1 = 0;  
    TL1 = 0;
    
    ET0 = 1;  
    EA = 1;   

    TR0 = 1;  
    TR1 = 1; 
  }

void display_frequency()
	{ 
    lcd_print("Freq: ");
  }

void main() 
	{
    init();  // Initialize LCD
    setup_timers();

    while (1) 
			{
        display_frequency();
        delay(100);  // Small delay before updating LCD
      }
  }
