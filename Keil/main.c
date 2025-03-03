#include <reg51.h>
#include "define_ports.h"
#include "delay.h"
#include "lcd.h"
#include "results.h"

unsigned int pulse_count = 0;
unsigned int frequency = 0;
unsigned int last_frequency = 0;
void timer0_isr() interrupt 1 
	{
    TR0 = 0;  // Stop Timer 0
    TR1 = 0;  // Stop Timer 1

    // Read Timer 1 count
    pulse_count = (TH1 << 8) | TL1;
    
    // Frequency is directly the counted pulses * 20 
    frequency = pulse_count*20;

    // Reset Timer 0 for 50ms delay
    TH0 = 0x3C;
    TL0 = 0xB0;

    // Reset Timer 1 for new measurement
    TH1 = 0x00;
    TL1 = 0x00;

    TR0 = 1;  // Start Timer 0
    TR1 = 1;  // Start Timer 1
  }

void setup_timers() 
	{
    TMOD = 0x51;  // Timer 0:(16-bit timer), Timer 1:(16-bit counter)

    // Timer 0 for 50ms
    TH0 = 0x3C;
    TL0 = 0xB0;

    TH1 = 0x00;  // Clear Timer 1 counter
    TL1 = 0x00;

    ET0 = 1;  // Enable Timer 0 Interrupt & global interrupts
    EA = 1; 

    TR0 = 1;  // Start Timer 0 & Timer 1
    TR1 = 1;  
  }

void display_frequency(unsigned int freq) 
	{ 
    lcd_print("Freq: ");
    print_result(freq);
	  lcd_print("Hz");
  }

void main() 
	{
    init();  // Initialize LCD
    setup_timers();

    while (1) 
			{ 
				if (frequency != last_frequency) // To avoid keep uptading the LCD
				{
						display_frequency(frequency);
        }
				last_frequency = frequency; 
      }
  }
