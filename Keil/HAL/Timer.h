#ifndef _TIMER_H_
#define _TIMER_H_

#include "Config.h"

void Timer0_Init(unsigned char TM,unsigned char TH,unsigned char TL); 
void Timer1_Init(unsigned char TM,unsigned char TH,unsigned char TL) ; 
void Timer0_Start();
void Timer1_Start(); 
void Timer0_Stop(); 
void Timer1_Stop();

#endif