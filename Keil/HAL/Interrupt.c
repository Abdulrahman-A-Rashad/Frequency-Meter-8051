#include "Interrupt.h"


void EnableGlobalInterrupt()
{
    EA = 1; 
}

void EnableTimerInterrupt()
{
		ET0 = 1;
}




