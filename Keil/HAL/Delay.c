#include "Delay.h"


void delayUsingInstruction(unsigned char c)
{
		unsigned int i;
		unsigned char j;
		for(i=0;i<=3;i++)
		{
				for(j=0;j<=c;j++); 
		}
}