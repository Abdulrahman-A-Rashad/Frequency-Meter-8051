#include "InterruptManager.h"

void setup_timers() 
	{
		Timer0_Init(0x50,0x3C,0xB0); // Timer 0 : 16 bit timer : 50 ms
		Timer1_Init(0x01,0x0,0x0); // Timer 1 : 16 bit counter : clear counter
		

    EnableGlobalInterrupt();
		EnableTimerInterrupt();
		
		Timer0_Start();
		Timer1_Start();
 }
	
 void timer0_isr() interrupt 1 
	{
    Timer0_Stop();
		Timer1_Stop();
		
    // Read Timer 1 count
    PULSE_COUNT = (TH1 << 8) | TL1;
    
    // Frequency is directly the counted pulses * 20 
    FREQUENCY = PULSE_COUNT*20;

    // Reset Timer 0 for 50ms delay
    Timer0_Init(0x50,0x3C,0xB0);

    // Reset Timer 1 for new measurement
    Timer1_Init(0x01,0x0,0x0);

    Timer0_Start();
		Timer1_Start();
  }