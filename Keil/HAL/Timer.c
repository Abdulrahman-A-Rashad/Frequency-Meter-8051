#include "Timer.h"


void Timer0_Init(unsigned char TM,unsigned char TH,unsigned char TL) {
    TMOD |= TM; 
    TH0 = TH; 
    TL0 = TL;
}

void Timer1_Init(unsigned char TM,unsigned char TH,unsigned char TL) {
    TMOD |= TM; 
    TH1 = TH;  
    TL1 = TL;
}

void Timer0_Start() {
    TR0 = 1; 
}

void Timer1_Start() {
    TR1 = 1;
}

void Timer0_Stop() {
    TR0 = 0;  
}

void Timer1_Stop() {
    TR1 = 0; 
}