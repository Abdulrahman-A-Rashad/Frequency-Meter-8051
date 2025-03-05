#ifndef _INTERUPTMANAGER_H_
#define _INTERUPTMANAGER_H_

#include "Timer.h"
#include "Interrupt.h"

extern unsigned int FREQUENCY;
extern unsigned int PULSE_COUNT; // fe variable met3rf fe makan tany


void setup_timers() ;
void timer0_isr() ;

#endif