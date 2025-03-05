
#include "KeypadManager.h"
#include "LCDManager.h"
#include "InterruptManager.h"

unsigned int last_frequency = 0;
unsigned int FREQUENCY = 0;
unsigned int PULSE_COUNT = 0;

void main(){
	
	init();  // Initialize LCD
	setup_timers();
	while (1) 
		{ 
			if (FREQUENCY != last_frequency) // To avoid keep uptading the LCD
			{
					clearLCD();
					lcd_print(" Freq : ");
					print_result(FREQUENCY);
					lcd_print("Hz");
			}
			last_frequency = FREQUENCY; 
		}
	
}